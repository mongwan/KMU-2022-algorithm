#include <stdio.h>
#define SIZE 4

int test(int sudo[SIZE][SIZE]);

int main(void) {
    int sudo[SIZE][SIZE] = {0,};
    for (int i = 0; i < SIZE; i++) {
        scanf("%d %d %d %d", &sudo[i][0], &sudo[i][1], &sudo[i][2], &sudo[i][3]);
    }
    printf("%d", test(sudo));
    return 0;
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
            l[j] = sudo[(i<2 ? 0 : 2) + (j<2 ? 0 : 1)][(i%2 ? 0 : 2) + (j%2 ? 0 : 1)];
            // i: 0, 0, 2, 2 -> i<2 ? 0 : 2
            // i: 0, 2, 0, 2 -> i%2 ? 0 : 2
            // j: 0, 0, 1, 1 -> j<2 ? 0 : 1
            // j: 0, 1, 0, 1 -> j%2 ? 0 : 1

        for (int j = 0; j < SIZE; j++)
            for(int k = j+1; k < SIZE; k++)
                if (l[j] > 0 && l[k] > 0 && l[j] == l[k])
                    return 0;
    }

    return 1;
}