#include <stdio.h>

int travel(int stage[8][8], int m, int n, int s, int t);

int main(void) {
    int test;
    scanf("%d", &test);
    for(int _t = 0; _t < test; _t++) {
        int m, n, s, t;
        scanf("%d %d %d %d", &m, &n, &s, &t);
        // 2 <= m, n <= 8, 1 <= s <= m, 1 <= t <= n
        
        int stage[8][8] = {0,};
        int a = travel(stage, m, n, s-1, t-1);
    }
    return 0;
}

int travel(int stage[8][8], int m, int n, int s, int t) {
    
}
