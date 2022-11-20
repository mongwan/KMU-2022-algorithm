#include <stdio.h>

int maxSubsequenceSum(int a[], int n, int *start, int *end);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, a[101], r;
        int left, right;
        scanf("%d", &n);
        left = 0;
        right = n;
        for (int i = 0 ; i < n; i++)
            scanf("%d", &a[i]);

        r = maxSubsequenceSum(a, n, &left, &right);
        printf("%d %d %d\n", r, left, right);
    }
    return 0;
}

int maxSubsequenceSum(int a[], int n, int *start, int *end) {
    int maxSum = 0, thisSum = 0, i = 0;
    *start = *end = -1;

    for(int j = 0; j < n; j++) {
        thisSum += a[j];

        if(a[j] == 0 && i == j) i++;

        if(thisSum > maxSum) {
            maxSum = thisSum;
            *start = i;
            *end = j;
        } else if (thisSum < 0) {
            i = j+1;
            thisSum = 0;
        }
    }

    return maxSum;
}