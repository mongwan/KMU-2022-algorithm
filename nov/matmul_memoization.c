#include <stdio.h>
#define MAX_LENGTH 101

int matmul(int msl[], int M[][MAX_LENGTH], int i, int j);
int min(int l[], int len);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n;
        int msl[MAX_LENGTH];
        int M[MAX_LENGTH][MAX_LENGTH] = {0,};
        scanf("%d", &n);
        for(int i = 0; i < n + 1; i++)
            scanf("%d", &msl[i]);

        printf("%d\n", matmul(msl, M, 1, n));
    }
    return 0;
}

int matmul(int msl[], int M[][MAX_LENGTH], int i, int j) {
    if (i == j) return 0;
    else {
        int l[MAX_LENGTH];
        int len = j - i;
        for(int k = i; k < j; k++) {
            int a, b;
            
            if (M[i][k]) a = M[i][k];
            else a = M[i][k] = matmul(msl, M, i, k);

            if (M[k+1][j]) b = M[k+1][j];
            else b = M[k+1][j] = matmul(msl, M, k+1, j);

            l[k-i] = a + b + msl[i-1]*msl[k]*msl[j];
        }
        
        return (M[i][j] = min(l, len));
    }
}

int min(int l[], int len) {
    int r = __INT_MAX__;
    for (int i = 0; i < len; i++)
        if (r > l[i]) r = l[i];
    return r;
}