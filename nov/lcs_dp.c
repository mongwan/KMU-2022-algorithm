#include <stdio.h>
#define MAX_LENGTH 101

int lcs(char *dst, char *s1, char *s2);
void getLCS(char *dst, char *s1, char *s2, int S[][MAX_LENGTH], int m, int n);
int len(char *s);
int max(int a, int b);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        char s1[MAX_LENGTH], s2[MAX_LENGTH];
        char rs[MAX_LENGTH] = {'\0',};
        int length;
        scanf("%s %s", s1, s2);
        length = lcs(rs, s1, s2);
        printf("%d %s\n", length, rs);
    }

    return 0;
}

int lcs(char *dst, char *s1, char *s2) {
    int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];
    int m = len(s1);
    int n = len(s2);

    for(int i = 0; i <= m; i++)
        L[i][0] = 0;
    for(int i = 0; i <= n; i++)
        L[0][i] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            } else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
                if (L[i][j] == L[i][j-1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }

    getLCS(dst, s1, s2, S, m, n);
    return L[m][n];
}

void getLCS(char *dst, char *s1, char *s2, int S[][MAX_LENGTH], int m, int n) {
    if (m == 0 || n == 0)
        return;
    if (S[m][n] == 0) {
        getLCS(dst, s1, s2, S, m-1, n-1);
        dst[len(dst)] = s1[m-1];
    } else if (S[m][n] == 1)
        getLCS(dst, s1, s2, S, m, n-1);
    else if (S[m][n] == 2)
        getLCS(dst, s1, s2, S, m-1, n);
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int len(char *s) {
    for (int i = 0; ; i++) {
        if (s[i] == '\0') return i;
    }
}