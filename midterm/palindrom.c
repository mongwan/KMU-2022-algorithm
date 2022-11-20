#include <stdio.h>

int chkpal(int l[], int left, int right);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, list[100];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &list[i]);
    
        printf("%d\n", chkpal(list, 0, n-1));
    }
}


int chkpal(int l[], int left, int right) {
    if (left >= right) return 1;
    if (l[left] != l[right]) return 0;
    return chkpal(l, left + 1, right - 1);
}