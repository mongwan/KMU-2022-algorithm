#include <stdio.h>
#define MAX_SIZE 1000

void selectionSort(int a[], int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        scanf("%d", &a[j]);
        selectionSort(a, num);
    }
    return 0;
}

/* Selection Sort 함수 */
void selectionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    
    for(int i = 0; i < n - 1; i++) {
        int minNumPos = 0;
        int cmpNum = a[i];
        for(int j = i + 1; j < n; j++) {
            countCmpOps++;
            if(a[j] < cmpNum) {
                minNumPos = j;
                cmpNum = a[j];
            }
        }
        if(minNumPos > 0) {
            countSwaps++;
            int tmp = a[minNumPos];
            a[minNumPos] = a[i];
            a[i] = tmp;
        }
    }
    
    printf("%d %d\n", countCmpOps, countSwaps);
    
}