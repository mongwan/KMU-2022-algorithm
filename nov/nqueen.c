#include <stdio.h>
#define MAX 16
#define abs(x) ((x) >= 0 ? (x) : (-x))

void nQueens(int N, int col[MAX], int row);
int isPromising(int col[MAX], int row);

int finded = 0;

int main(void) {
    int col[MAX];
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            col[0] = i;
            nQueens(N, col, 0);
        }
        printf("\n");
        finded = !finded;
    }
    return 0;
}

void nQueens(int N, int col[MAX], int row) {
    if (finded) return;
    if (isPromising(col, row)) {
        if (row == N-1) {
            for(int i = 0; i < N; i++)
                printf("%d ", col[i]+1);
            finded = !finded;
            return;
        }
        else
            for(int i = 0; i < N; i++) {
                col[row+1] = i;
                nQueens(N, col, row+1);
            }
    }
}

int isPromising(int col[MAX], int row) {
    int k = 0;
    int promising = 1;

    while (k < row && promising) {
        if (col[row] == col[k] || abs(col[row]-col[k]) == row-k)
            promising = 0;
        k++;
    }
    return promising;
}