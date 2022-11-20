#include <stdio.h>
#define MAX_SIZE 100
#define MIN(a, b) (a) < (b) ? (a) : (b)

void merge(int a[], int low, int mid, int high, int* count);
void mergeSort(int a[], int n, int *count);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int a[100], n, count = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        mergeSort(a, n, &count);
        printf("%d\n", count);
    }

    return 0;
}

void merge(int a[], int low, int mid, int high, int* count) {
    int i, j, k;
    int tmp[MAX_SIZE];

    for(i = low; i <= high; i++)
        tmp[i] = a[i];
    
    i = k = low;
    j = mid + 1;
    
    while(i <= mid && j <= high) {
        (*count)++;
        if (tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while(i <= mid)
        a[k++] = tmp[i++];
    
    while(j <= high)
        a[k++] = tmp[j++];
}

void mergeSort(int a[], int n, int *count) {
    int size = 1;

    while (size < n) {
        for (int i = 0; i < n; i += 2*size) {
            int low = i;
            int mid = MIN(low+size-1, n-1);
            int high = MIN(i + 2*size - 1, n-1);

            merge(a, low, mid, high, count);
        }

        size *= 2;
    }
}