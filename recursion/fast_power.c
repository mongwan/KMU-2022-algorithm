#include <stdio.h>

int power(int a, int n);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _t = 0; _t < t; _t++) {
        int a, n;
        scanf("%d %d", &a, &n);
        printf("%d\n", power(a, n));
    }
    return 0;
}

int power(int a, int n) {
    if (n == 0) return 1;
    
    int t = power(a, n/2);
    if (n % 2 == 0) return (t*t)%1000;
    else return (t*t*a)%1000;
}