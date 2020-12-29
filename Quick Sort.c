// 퀵 정렬
// 기준 값보다 작으면 왼쪽, 크면 오른쪽에 배치하는 방법으로 정렬. 데이터가 정렬되어 있을수록 시간은 오히려 많이 소요된다.
/*
[오름차순 정렬 순서]
(1) 맨 처음 데이터를 키(key)로 한다.
(2) 좌측에서 우측으로 가면서 key보다 큰 값을 찾는다. 그리고 우측에서는 좌측으로 가면서 작은 값을 찾는다. 큰 값이 작은 값보다 좌측에 있으면 교환한다.
    우측에 있으면 key와 작은 값을 교환한다. 그러면 key를 기준으로 좌측에는 작은 값, 우측에는 큰 값이 배치된다.
(3) 나누어진 부분의 데이터가 2개 이상이면 재귀호출로 (2)를 반복한다.
*/

#include <stdio.h>

void QuickSort(int *a, int low, int high){
  int i, j, key, temp;
  
  if(low<high){
    key = a[low];
    i = low;
    j = high;
    while(i<j){
      while(i<high && a[i] <= key) i++;
      while(j>low && a[j] >= key) j--;
      if(i<j){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    
    a[low] = a[j];
    a[j] = key;
    
    QuickSort(a, low, j-1);
    QuickSort(a, j+1, high);
  }
}

int main(void){
  int a[] = {15, 7, 2, 20, 33, 17, 26, 5, 21, 30, 27, 29, 11, 10, 3};
  int i, n = sizeof(a)/sizeof(int);
  
  printf("정렬 전 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  QuickSort(a, 0, n-1);
  printf("\n퀵 정렬 후 : ");
  for(i=0; i<n; i++) printf("&d  ", a[i]);
  
  return 0;
}
