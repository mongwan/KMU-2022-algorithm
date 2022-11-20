#include <stdio.h>
#define MAX_LEN 1001

void heapsort(int L[], int n);
void fixheap(int L[], int root, int k, int n);

int count;

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        count = 0;
        int n, L[MAX_LEN];
        scanf("%d", &n);
        L[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &L[i]);

        heapsort(L, n);
        // print(L, n);
        printf("%d\n", count);
    }

    return 0;
}

void heapsort(int L[], int n) {
    int max;

    // heap construction
    for (int i = n/2; i >= 1; i--)
        fixheap(L, i, L[i], n);

    // repeatedly remove the key at the root and rearrange the heap
    for(int heapsize = n; heapsize >= 2; heapsize--) {
        max = L[1];
        fixheap(L, 1, L[heapsize], heapsize-1);
        L[heapsize] = max;
    }

}

void fixheap(int L[], int root, int k, int n) {
    int vacant;
    int larger;

    vacant = root;
    L[vacant] = k;
    while (vacant <= n/2) {
        count++;
        if (vacant*2 == n)
            larger = vacant*2;
        else {
            count++;
            larger = (L[vacant*2] > L[vacant*2+1]) ? vacant*2 : vacant*2+1;
        }

        if (L[vacant] < L[larger]) {
            L[vacant] = L[larger];
            L[larger] = k;
            vacant = larger;
        } else break;
    }
    L[vacant] = k;
}
