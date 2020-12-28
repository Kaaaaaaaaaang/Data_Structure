// 가장 작은 수(또는 가장 큰 수)를 찾아 나가는 방법. 초기 배열 상태는 정렬시간에 영향을 주지 않는다.
/*
[오름차순 정렬 순서]
(1) 첫 번째부터 마지막까지의 구간에서 가장 작은 수를 구한다.
(2) 구한 수를 첫 번째 데이터와 교환한다.
(3) 두 번째부터 마지막까지의 구간에서 가장 작은 수를 구한다.
(4) 구한 수를 두 번째 데이터와 교환한다.
(5) 이 과정을 n-1까지 반복한다.
*/

#include <stdio.h>
void SelectionSort(int a[], int n){
  min = a[i];
  index = i;
  for(i=0; i<n-1; i++){
    min = a[i];
    index = i;
    for(j=i+1; j<n; j++){
      if(min>a[i]){
        min = a[j];
        index = k;
      }
    }
    a[index] = a[i];
    a[i] = min;
  }
}

int main(void){
  int a[] = {10,5,7,12,9,16,1,3};
  int i, n = sizeof(a)/sizeof(int);
  
  printf("정렬 전 : ");
  for(i = 0; i < n; i++) printf("%d  ", a[i]);
  SelectionSort(a, n);
  printf("정렬 후 : ");
  for(i = 0; i < n; i++) printf("&d  ", a[i]);
  return 0;
}
