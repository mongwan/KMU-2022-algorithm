#include <stdio.h>
#define MAX_SIZE 1000
#define SHRINK_RATIO 2

void ShellSort(int a[], int n);

int main() {
  int numTestCases;
  scanf("%d", &numTestCases);
  for (int i = 0; i < numTestCases; ++i) {
    int num;
    int a[MAX_SIZE];
    scanf("%d", &num);
    for (int j = 0; j < num; j++)
      scanf("%d", &a[j]);
    ShellSort(a, num);
  }
  return 0;
}

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* Shell Sort 함수 */
void ShellSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수
  
  for(int gap = n/SHRINK_RATIO; gap > 0; gap /= SHRINK_RATIO) {
    for(int i = gap - 1; i < n; i++) {
      for (int j = i; j-gap >= 0; j -= gap) {
        countCmpOps++;
        if (a[j-gap] > a[j]) {
          countSwaps++;
          swap(&a[j-gap], &a[j]);
        } else break;
      }
    } 
  }
  printf("%d %d\n", countCmpOps, countSwaps);
}