#include <stdio.h>
#define MAX_SIZE 100

void merge(int a[], int low, int mid, int high, int* count);
void mergeSort(int v[], int low, int high, int* count);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        int n, a[MAX_SIZE];
        int count = 0;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        
        mergeSort(a, 0, n-1, &count);
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
    while (i <= mid && j <= high) {
        (*count)++;
        if(tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSort(int v[], int low, int high, int* count) {
    int mid;
    if (low == high)
        return;

    mid = (low + high) / 2;

    mergeSort(v, low, mid, count);
    mergeSort(v, mid+1, high, count);
    merge(v, low, mid, high, count);
}