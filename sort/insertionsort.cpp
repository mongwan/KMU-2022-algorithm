#include <stdio.h>
#define MAX_SIZE 1000

void insertionSort(int a[], int n);

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
    insertionSort(a, num);
  }
  return 0;
}

/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수
  
  for(int sortedPos = 0; sortedPos < n-1; sortedPos++) {
    for (int i = sortedPos+1; i > 0; i--) {
      countCmpOps++;
      if (a[i-1] > a[i]) {
        countSwaps++;
        int tmp = a[i-1];
        a[i-1] = a[i];
        a[i] = tmp;
      } else break;
    }
  }
  printf("%d %d\n", countCmpOps, countSwaps);
}
