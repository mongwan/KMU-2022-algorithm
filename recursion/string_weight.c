#include <stdio.h>
#include <string.h>

void swap (char* a, char* b);
void permuteString(char *str, int begin, int end, int* count);

int main(void) {
    int t = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int count = 0;
        char str[10] = "";
        scanf("%s", str);
        permuteString(str, 0, strlen(str), &count);
        printf("%d\n", count);
    }
    return 0;
}

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void permuteString(char *str, int begin, int end, int* count) {
    int range = end - begin;

    if(range == 1) {
        int sum = 0;

        for (int i = 0; i < strlen(str); i++) {
            sum += (i % 2 == 0 ? 1 : -1) * ((int)str[i] - 'a');
        }
        if (sum > 0) (*count)++;
        return;
    }
    else {
        for (int i = 0; i < range; i++) {
            swap(&str[begin], &str[begin+i]);
            permuteString(str, begin + 1, end, count);
            swap(&str[begin], &str[begin+i]);
        }
    }
}