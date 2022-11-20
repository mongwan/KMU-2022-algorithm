#include <stdio.h>
#define MAX_LENGTH 101

int len(char *s);
int max(int a, int b);
int lcs(int L[][MAX_LENGTH], char s1[MAX_LENGTH], char s2[MAX_LENGTH], int m, int n);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        char s1[MAX_LENGTH], s2[MAX_LENGTH];
        
        int L[MAX_LENGTH][MAX_LENGTH];
        for (int i = 0; i < MAX_LENGTH; i++)
            for (int j = 0; j < MAX_LENGTH; j++)
                L[i][j] = -1;
        
        scanf("%s %s", s1, s2);
        printf("%d\n", lcs(L, s1, s2, len(s1), len(s2)));
    }

    return 0;
}

int len(char *s) {
    for (int i = 0; ; i++) {
        if (s[i] == '\0') return i;
    }
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int lcs(int L[][MAX_LENGTH], char s1[MAX_LENGTH], char s2[MAX_LENGTH], int m, int n) {
    if (m == 0 || n == 0) {
        return 0;   
    } else if (m > 0 && n > 0 && s1[m-1] == s2[n-1]) {
        if (L[m][n] == -1)
            L[m][n] = lcs(L, s1, s2, m-1, n-1) + 1;
        return L[m][n];
    } else {
        if (L[m][n] == -1)
            L[m][n] = max(lcs(L, s1, s2, m-1, n), lcs(L, s1, s2, m, n-1));
        return L[m][n];
    }
}