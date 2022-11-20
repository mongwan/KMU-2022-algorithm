#include <stdio.h>
#define MAX_LENGTH 11

int matmul(int msl[], int i, int j);
int min(int l[], int len);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n;
        int msl[MAX_LENGTH];
        scanf("%d", &n);
        for(int i = 0; i < n + 1; i++)
            scanf("%d", &msl[i]);

        printf("%d\n", matmul(msl, 1, n));
    }
    return 0;
}

int matmul(int msl[], int i, int j) {
    if (i == j) return 0;
    else {
        int l[MAX_LENGTH];
        int len = j - i;
        for(int k = i; k < j; k++)
            l[k-i] = matmul(msl, i, k) + matmul(msl, k+1, j) + msl[i-1]*msl[k]*msl[j];
        
        return min(l, len);
    }
}

int min(int l[], int len) {
    int r = __INT_MAX__;
    for (int i = 0; i < len; i++)
        if (r > l[i]) r = l[i];
    return r;
}