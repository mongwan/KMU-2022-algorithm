#include <stdio.h>
#define MAX_SIZE 1000

void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main() {
  int numTestCases;
  scanf("%d", &numTestCases);
  for (int i = 0; i < numTestCases; ++i) {
    int num;
    int a[MAX_SIZE], b[MAX_SIZE];
    scanf("%d", &num);
    for (int j = 0; j < num; j++)
      scanf("%d", &b[j]);
    copyArray(a, b, num);
    bubbleSort(a, num);
    copyArray(a, b, num);
    bubbleSortImproved1(a, num);
    copyArray(a, b, num);
    bubbleSortImproved2(a, num);
    printf("\n");
  }
  return 0;
}

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* BubbleSort 함수 */
void bubbleSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  for (int i = n; i > 1; i--) {
    for (int j = 1; j < i; j++) {
      countCmpOps++;
      if (a[j-1] > a[j]) {
        countSwaps++;
        swap(&a[j-1], &a[j]);
      }
    }
  }

  printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  for (int i = n; i > 1; i--) {
    bool swapped = false;
    for(int j = 1; j < i; j++) {
      countCmpOps++;
      if (a[j-1] > a[j]) {
        countSwaps++;
        swap(&a[j-1], &a[j]);
        swapped = true;
      }
    }

    if(!swapped) break;
  }

  printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  int swappedPos = 0;
  for(int i = n; i > 0; i = swappedPos) {
    swappedPos = 0;
    for(int j = 1; j < i; j++) {
      countCmpOps++;
      if (a[j-1] > a[j]) {
        countSwaps++;
        swap(&a[j-1], &a[j]);
        swappedPos = j;
      }
    }
  }

  printf("%d %d ", countCmpOps, countSwaps);
}

void copyArray(int a[], int b[], int n) {
  for (int i = 0; i < n; i++)
  a[i] = b[i];
}
