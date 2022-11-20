#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    
    int fibo[1500] = {0, 1};
    for(int i = 2; i < 1500; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= 1000;
    }

    for(int _t = 0; _t < t; _t++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", fibo[n%1500]);
    }
    return 0;
}