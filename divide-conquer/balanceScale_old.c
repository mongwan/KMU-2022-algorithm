#include <stdio.h>
#define ABS(a) (a) < 0 ? -(a) : (a)

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, a, b, tmp;
        scanf("%d %d %d", &n, &a, &b);
        for (int i = 0; i < n - 2; i++) {
            scanf("%d", &tmp);
            if (a <= b) a += tmp;
            else b += tmp; 
        }
        
        tmp = 0;
        a = ABS(a - b);
        while (a >= 100) { a -= 100; tmp++; }
        while (a >= 50) { a -= 50; tmp++; }
        while (a >= 20) { a -= 20; tmp++; }
        while (a >= 10) { a -= 10; tmp++; }
        while (a >= 5) { a -= 5; tmp++; }
        while (a >= 2) { a -= 2; tmp++; }
        while (a >= 1) { a -= 1; tmp++; }

        printf("%d\n", tmp);
    }
    return 0;
}