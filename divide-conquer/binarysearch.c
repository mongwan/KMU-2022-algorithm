#include <stdio.h>

int binarysearch(int l[100], int k, int left, int right);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        int n, k;
        int l[100];
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%d", &l[i]);
        }
        printf("%d\n", binarysearch(l, k, 0, n - 1));
    }
    return 0;
}

int binarysearch(int l[100], int k, int left, int right) {
    int mid;

    if (left > right)
        return -1;
    else {
        mid = (left + right) / 2;

        if (l[mid] == k)
            return mid;
        else if (l[mid] > k)
            return binarysearch(l, k, left, mid - 1);
        else
            return binarysearch(l, k, mid + 1, right);
    }
}