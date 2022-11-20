#include <stdio.h>
#define lastelement(e) towers[e][getHeight(towers[e])-1]

void hanoi(int towers[][11], int n, int from, int to, int other);
int getHeight(int* tower);

int main(void) {
    int t = 0;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++) {
        int towers[3][11] = {0,};
        int n = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            towers[0][i] = n-i;
        }
        hanoi(towers, n, 0, 2, 1);
        printf("\n");
    }

    return 0;
}

void hanoi(int towers[][11], int n, int from, int to, int other) {
    if (n > 0) {
        hanoi(towers, n-1, from, other, to);

        int t = lastelement(from);
        lastelement(from) = 0;
        towers[to][getHeight(towers[to])] = t;
        
        if (from == 2)
            printf("%d ", lastelement(from));
        else if (to == 2)
            printf("%d ", lastelement(to));
        
        hanoi(towers, n-1, other, to, from);
    }
}

int getHeight(int* tower) {
    int r = 0;
    for(int i = 0; i < 11; i++) {
        if (tower[i] == 0) {
            r = i;
            break;
        }
    }
    return r;
}