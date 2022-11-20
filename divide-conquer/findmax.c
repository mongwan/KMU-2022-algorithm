#include <stdio.h>
#define MAX_SIZE 100
#define MAX(a, b) ((a) > (b) ? (a): (b))

int findmax(int a[], int left, int right);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int l, a[100];
        scanf("%d", &l);
        for (int i = 0; i < l; i++)
            scanf("%d", &a[i]);
        
        printf("%d\n", findmax(a, 0, l-1));
    }
    return 0;
}

int findmax(int a[], int left, int right) {
    int half;

    if (left == right)
        return a[left];
    else {
        half = (left + right) / 2;
        return MAX(findmax(a, left, half), findmax(a, half + 1, right));
    }
}