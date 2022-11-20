#include <stdio.h>
#define MAX_SIZE 1000
#define SHRINK_FACTOR 1.3

void combSort(int a[], int n);

int main() {
  int numTestCases;
  scanf("%d", &numTestCases);
  for (int i = 0; i < numTestCases; ++i)
  {
    int num;
    int a[MAX_SIZE];
    scanf("%d", &num);
    for (int j = 0; j < num; j++)
      scanf("%d", &a[j]);
    combSort(a, num);
  }
  return 0;
}

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* comb sort 함수 */
void combSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수
  
  bool sorted = false;
  int gap = n;
  while (!sorted) {
    gap /= SHRINK_FACTOR;
    if (gap <= 1) {
      gap = 1;
      sorted = true;
    }

    for (int i = 0; i + gap < n; i++) {
      countCmpOps++;
      if (a[i] > a[i + gap]) {
        countSwaps++;
        swap(&a[i], &a[i + gap]);
        sorted = false;
      }
    }
  }

  printf("%d %d\n", countCmpOps, countSwaps);
}