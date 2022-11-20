#include <stdio.h>

int factorial(int n);

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        if (n<7) printf("%d\n", factorial(n));
        else printf("%03d\n", factorial(n) % 1000);
    }
    
    return 0;
}

int factorial(int n) {
    if (n == 0) return 1;
    else {
        n *= factorial(n-1);
        while (n % 10 == 0)
            n /= 10;
        if (n > 100000)
            n %= 100000;
        return n;
    }
}