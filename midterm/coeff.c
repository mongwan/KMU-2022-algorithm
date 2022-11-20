#include <stdio.h>

int coeff(int n, int k, int *m);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int m[10001] = {0, };
        printf("%d\n", coeff(n, k, m)%1000);
    }
}


int coeff(int n, int k, int *m) {
    if (k == 0 || k == n) return 1;
    int m1, m2;
    if (*(int*)(m + 100*(n-1) + (k-1)) == 0) {
        m1 = coeff(n-1, k-1, m);
        *(int*)(m + 100*(n-1) + (k-1)) = m1;
    } else m1 = *(int*)(m + 100*(n-1) + (k-1));
    if (*(int*)(m + 100*(n-1) + (k)) == 0) {
        m2 = coeff(n-1, k, m);
        *(int*)(m + 100*(n-1) + (k)) = m2;
    } else m2 = *(int*)(m + 100*(n-1) + (k));
    return (m1 + m2) % 1000;
}