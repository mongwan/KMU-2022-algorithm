#include <stdio.h>
#include <string.h>

void knight(int stage[8][8], int m, int n, int s, int t, int step);

int main(void) {
    int z;
    scanf("%d", &z);
    for(int _z = 0; _z < z; _z++) {
        int m, n, s, t;
        scanf("%d %d %d %d", &m, &n, &s, &t);
        int stage[8][8] = {0,};
        knight(stage, m, n, s-1, t-1, 1);
    }
    return 0;
}

void knight(int stage[8][8], int m, int n, int s, int t, int step) {
    // (s, t): current position
    if (stage[s][t] != 0) return;

    stage[s][t] = step++;

    if (s - 1 >= 0 && t - 2 >= 0) {
        knight(stage, m, n, s - 1, t - 2, step);
        stage[s - 1][t - 2] = 0;
    }
    if (s - 2 >= 0 && t - 1 >= 0) {
        knight(stage, m, n, s - 2, t - 1, step);
        stage[s - 2][t - 1] = 0;
    }
    if (s - 2 >= 0 && t + 1 < n) {
        knight(stage, m, n, s - 2, t + 1, step);
        stage[s - 2][t + 1] = 0;
    }
    if (s - 1 >= 0 && t + 2 < n) {
        knight(stage, m, n, s - 1, t + 2, step);
        stage[s - 1][t + 2] = 0;
    }
    if (s + 1 < m && t - 2 >= 0) {
        knight(stage, m, n, s + 1, t - 2, step);
        stage[s + 1][t - 2] = 0;
    }
    if (s + 2 < m && t - 1 >= 0) {
        knight(stage, m, n, s + 2, t - 1, step);
        stage[s + 2][t - 1] = 0;
    }
    if (s + 2 < m && t + 1 < n) {
        knight(stage, m, n, s + 2, t + 1, step);
        stage[s + 2][t + 1] = 0;
    }
    if (s + 1 < m && t + 2 < n) {
        knight(stage, m, n, s + 1, t + 2, step);
        stage[s + 1][t + 2] = 0;
    }
}