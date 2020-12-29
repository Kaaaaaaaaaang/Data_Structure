// 삽입 정렬
// 데이터를 한 칸씩 이동시켜 키 값을 적절한 위치에 삽입하는 정렬. 초기 데이터가 정렬되어 있을수록 시간은 단축된다.
/*
[오름차순 정렬 순서]
(1) 키 값보다 좌측의 값이 더 크면 우측으로 한 칸씩 이동한다.
(2) 키 값보다 좌측의 값이 작거나 같으면 바로 우측에 키 값을 삽입한다.
(3) 키 값을 두 번째부터 마지막까지 변경하면서 이 과정을 반복한다.
*/

#include <stdio.h>

void InsertionSort(int a[], int n){
  int i, j, key;
  for(i=1; i<n; i++){
    key = a[i];
    for(j=i-1; j>=0; j--){
      if(key>=a[j]) break;
      a[j+1] = a[j];
    }
    a[j+1] = key;
  }
}

int main(void){
  int a[] = {7, 12, 6, 11, 3, 8, 5, 2};
  int i, n = sizeof(a)/sizeof(int);
  
  printf("정렬 전 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  InsertionSort(a, n);
  printf("\n삽입 정렬 후 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  return 0;
}
