#include <stdio.h>
#define SIZE 4
#define BOX 2

int test(int sudo[SIZE][SIZE]);
void print(int sudo[SIZE][SIZE]);
void sudoku(int sudo[SIZE][SIZE], int n);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int sudo[SIZE][SIZE] = {0,};
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                scanf("%d", &sudo[i][j]);
    
        sudoku(sudo, 0);
    }

    return 0;
}

void sudoku(int sudo[SIZE][SIZE], int n) {
    int a = n/SIZE;
    int b = n%SIZE;

    for (int i = 0; i <= SIZE; i++) {
        if (i > 0)
            sudo[a][b] = i;
        else if (sudo[a][b] == 0)
            continue;
        
        if (!test(sudo)) continue;

        if (n == SIZE*SIZE-1) {
            if (test(sudo))
                print(sudo);
            return;
        }

        sudoku(sudo, n+1);
        sudo[a][b] = 0;
    }
}

void print(int sudo[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", sudo[i][j]);
        printf("\n");
    }
}

int test(int sudo[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int l[SIZE];
        for (int j = 0; j < SIZE; j++)
            l[j] = sudo[i][j]; 

        for (int j = 0; j < SIZE; j++)
            for(int k = j+1; k < SIZE; k++)
                if (l[j] > 0 && l[k] > 0 && l[j] == l[k])
                    return 0;
    }

    for (int i = 0; i < SIZE; i++) {
        int l[SIZE];
        for (int j = 0; j < SIZE; j++)
            l[j] = sudo[j][i];

        for (int j = 0; j < SIZE; j++)
            for(int k = j+1; k < SIZE; k++)
                if (l[j] > 0 && l[k] > 0 && l[j] == l[k])
                    return 0;
    }

    for (int i = 0; i < SIZE; i++) {
        int l[SIZE];
        for (int j = 0; j < SIZE; j++)
            l[j] = sudo[i/BOX*BOX + j/BOX][i%BOX*BOX + j%BOX];

        for (int j = 0; j < SIZE; j++)
            for(int k = j+1; k < SIZE; k++)
                if (l[j] > 0 && l[k] > 0 && l[j] == l[k])
                    return 0;
    }

    return 1;
}