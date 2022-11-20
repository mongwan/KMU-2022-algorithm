#include <stdio.h>

enum method {
    Hoare, Lomuto
};

void quicksort(int method, int A[], int low, int high, int* scount, int* ccount);
int partition_Hoare(int A[], int low, int high, int* scount, int* ccount);
int partition_Lomuto(int A[], int low, int high, int* scount, int* ccount);
void swap (int* a, int* b);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, tmp, a1[1000], a2[1000];
        int h_scount = 0, h_ccount = 0, l_scount = 0, l_ccount = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            a1[i] = a2[i] = tmp;
        }
        quicksort(Hoare, a1, 0, n-1, &h_scount, &h_ccount);
        quicksort(Lomuto, a2, 0, n-1, &l_scount, &l_ccount);
        printf("%d %d %d %d\n", h_scount, l_scount, h_ccount, l_ccount);
    }

    return 0;
}

void quicksort(int method, int A[], int low, int high, int* scount, int* ccount) {
    if(low >= high) return;
    int p; // pivot
    if (method == Hoare) {
        p = partition_Hoare(A, low, high, scount, ccount);
        quicksort(method, A, low, p, scount, ccount);
        quicksort(method, A, p+1, high, scount, ccount);
    } else {
        p = partition_Lomuto(A, low, high, scount, ccount);
        quicksort(method, A, low, p-1, scount, ccount);
        quicksort(method, A, p+1, high, scount, ccount);
    }
    return;
}

int partition_Hoare(int A[], int low, int high, int* scount, int* ccount) {
    int i, j, tmp; 
    int pivot = A[low];
    i = low - 1;
    j = high + 1;
    while (1) {
        do { i++; (*ccount)++; } while (A[i] < pivot);
        do { j--; (*ccount)++; } while (A[j] > pivot);
        if (i < j) {
            (*scount)++;
            swap(&A[i], &A[j]);
        } else
            return j;
    }
}

int partition_Lomuto(int A[], int low, int high, int* scount, int* ccount) {
    int pivot = A[low];
    int j, pivot_pos;
    j = low;
    for(int i = low + 1; i < high + 1; i++) {
        (*ccount)++;
        if (A[i] < pivot) {
            j++;
            (*scount)++;
            swap(&A[i], &A[j]);
        }
    }
    (*scount)++;
    swap(&A[j], &A[low]);
    return j;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}