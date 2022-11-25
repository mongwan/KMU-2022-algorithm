#include <stdio.h>
#include <string.h>
#define LENGTH 1001

int fail(char str[], int n);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        char text[LENGTH], pattern[LENGTH];
        int n, m;
        scanf("%s %s", pattern, text);
        n = strlen(text);
        m = strlen(pattern);

        for (int i = 0; i < m; i++)
            printf("%d ", fail(pattern, i));
        printf("\n");

        int j = 0, r = 0;
        
        for (int i = 0; i < n; i++) {
            while (j > 0 && text[i] != pattern[j])
                j = fail(pattern, j-1);
            if (text[i] == pattern[j])
                if (j == m-1) { 
                    r++;
                    j = fail(pattern, j);
                }
            else
                j++;
        }

        printf("%d\n", r);
    }

    return 0;
}

int fail(char str[], int k) {
    if (k == 0) return 0;
    int j = 0;
    int failarr[LENGTH] = {0, };

    for(int i = 1; i <= k; i++) {
        while (j > 0 && str[i] != str[j]) {
            j = fail(str, j-1);
        }
        if (str[i] == str[j]) {
            failarr[i] = ++j;
        }
    }
    
    return failarr[k];
}