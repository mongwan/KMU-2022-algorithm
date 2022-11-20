#include <stdio.h>

int getsec(int list[], int left, int right);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, list[100] = {0,};
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &list[i]);

        printf("%d\n", getsec(list, 0, n-1));
    }
}

int getsec(int list[], int left, int right) {
    int length = right - left;

    if (length == 0) return list[left];
    
    int a = getsec(list, left, left+length/2);
    int b = getsec(list, left+length/2+1, right);

    if (length == 1) return a > b? b : a;
    return a > b ? a : b;
}

