#include <stdio.h>

int len(char *s);
int max(int a, int b);
int lcs(char s1[11], char s2[11], int m, int n);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        char s1[11], s2[11];
        scanf("%s %s", s1, s2);
        printf("%d\n", lcs(s1, s2, len(s1), len(s2)));
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

int lcs(char s1[11], char s2[11], int m, int n) {
    if (m == 0 || n == 0) {
        return 0;   
    } else if (m > 0 && n > 0 && s1[m-1] == s2[n-1]) {
        return lcs(s1, s2, m-1, n-1) + 1;
    } else {
        return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
    }
}