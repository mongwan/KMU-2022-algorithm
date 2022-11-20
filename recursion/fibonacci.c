#include <stdio.h>

int fibonacci(int n);

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", fibonacci(n));
    }

    return 0;
}

int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}