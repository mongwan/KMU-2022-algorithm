#include <stdio.h>
#define MAX_LENGTH 101

int minmult(int n, const int d[], int P[][MAX_LENGTH]);
int minidx(int l[], int len);
void order(int P[][MAX_LENGTH], int i ,int j);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n;
        int d[MAX_LENGTH];
        scanf("%d", &n);
        for(int i = 0; i < n + 1; i++)
            scanf("%d", &d[i]);

        int P[MAX_LENGTH][MAX_LENGTH];
        int r = minmult(n, d, P);
        order(P, 0, n-1);
        printf("\n%d\n", r);
    }
    return 0;
}

int minmult(int n, const int d[], int P[][MAX_LENGTH]) {
    int M[MAX_LENGTH][MAX_LENGTH] = {0,};
    for(int diagonal = 1; diagonal < n; diagonal++) {
        for(int i = 0; i < n-diagonal; i++) {
            int j = i + diagonal;
            
            int len = j - i;
            int l[MAX_LENGTH];
            for(int k = i; k < j; k++)
                l[k-i] = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];

            int idx = minidx(l, len);
            M[i][j] = l[idx];
            P[i][j] = i + idx;
        }
    }

    return M[0][n-1];
}

void order(int P[][MAX_LENGTH], int i ,int j) {
    if (i == j)
        printf("M%d", i+1);
    else {
        int k = P[i][j];
        printf("(");
        order(P, i, k);
        order(P, k+1, j);
        printf(")");
    }
}

int minidx(int l[], int len) {
    int r = __INT_MAX__;
    int idx = 0;
    for (int i = 0; i < len; i++)
        if (r > l[i]) {
            r = l[i];
            idx = i;
        }
    return idx;
}