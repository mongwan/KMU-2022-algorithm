#include <stdio.h>

int coin(int k, int list[5], int n);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int k;
        int n, list[5] = {0,};
        int r;
        scanf("%d %d", &k, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &list[i]);
        r = coin(k, list, n);

        printf("%d\n", r);
    }
}

int coin(int k, int list[5], int n) {
    if (k < 0) return 987654321;
    if (k == 0) return 0;
    int min = 987654321;
    int c;
    for (int i = 0; i < n; i++) {
        c = coin(k-list[i], list, n);
        if (c < min) min = c;
    }
    return min + 1;
}