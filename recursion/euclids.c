#include <stdio.h>

int gcd(int a, int b);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _t = 0; _t < t; _t++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    
    return 0;
}

int gcd(int a, int b) {
    while(b != 0) {
        int t = a;
        a = b;
        b = t % b;
    }
    return a;
}