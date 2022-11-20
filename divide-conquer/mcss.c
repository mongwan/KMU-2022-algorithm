#include <stdio.h>
#define MAX_SIZE 100

typedef struct _Rtn {
    int sum;
    int left;
    int right;
} Rtn;

Rtn mcss(int a[], int left, int right);
int getmax(int a, int b, int c);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int n, a[MAX_SIZE];
        Rtn rtn;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        
        rtn = mcss(a, 0, n-1);
        if (rtn.sum == 0 && rtn.left == rtn.right)
            rtn.left = rtn.right = -1;
        
        printf("%d %d %d\n", rtn.sum, rtn.left, rtn.right);
        
    }
    return 0;
}

Rtn mcss(int a[], int left, int right) {
    Rtn rtn;
    rtn.left = left;
    rtn.right = right;
    
    if (left == right) {
        rtn.sum = a[left];
        return rtn;
    }
    
    int half = (left + right) / 2;
    Rtn l, r;
    int sleft, sright, tmp, max;
    l = mcss(a, left, half);
    r = mcss(a, half + 1, right);
    
    max = -1;
    sleft = -1;
    tmp = 0;
    for (int i = half; i >= left; i--) {
        tmp += a[i];
        max = getmax(sleft, tmp, -1);
        if (sleft != max) {
            sleft = max;
            rtn.left = i;
        }
    }

    max = -1;
    sright = -1;
    tmp = 0;
    for (int i = half + 1; i <= right; i++) {
        tmp += a[i];
        max = getmax(sright, tmp, -1);
        if (sright != max) {
            sright = max;
            rtn.right = i;
        }
    }

    rtn.sum = sleft + sright;

    max = getmax(l.sum, r.sum, rtn.sum);
    if (max == l.sum) return l;
    else if (max == r.sum) return r;
    else return rtn;
}

int getmax(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}
