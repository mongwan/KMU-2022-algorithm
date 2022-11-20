#include <stdio.h>
#include <string.h>

void swap (char* a, char* b);
void reverseArray(char a[], int i, int j);

int main(void) {
    int t = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int count = 0;
        char str[101] = "";
        scanf("%s", str);
        reverseArray(str, 0, strlen(str)-1);
        printf("%s\n", str);
    }
    return 0;
}

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseArray(char a[], int i, int j) {
    if (i < j) {
        swap(&a[i], &a[j]);
        reverseArray(a, i + 1, j - 1);
    }
}