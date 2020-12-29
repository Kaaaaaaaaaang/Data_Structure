//쉘 정렬
// Donald Shell이 1958년에 고안한 정렬 알고리즘
// 이동하는 빈도수가 많은 삽입정렬을 개선한 알고리즘
// 일정한 간격의 데이터끼리 삽입정렬하여 데이터 이동횟수를 줄임
/*
[오름차순 정렬 순서]
(1) 일정한 간격 t끼리 묶어 삽입정렬을 수행(t = n/2)
(2) 간격을 줄여나가면서 삽입정렬을 반복(t = t/2)
(3) 간격이 1이 될 때까지 반복수행
*/

#include <stdio.h>

void ShellSort(int a[], int n){
  int i, j, t;
  int temp;
  for(t=n/2; t>=1; t/=2;){
    for(i=t; i<n; i++){
      temp = a[i];
      for(j=i-t; j>=0; j-=t){
        if(temp<a[j]) a[j+t] = a[j];
        else break;
      }
      a[j+t] = temp;
    }
  }
}

int main(void){
  int a[] = {17, 8, 20, 11, 5, 12, 15, 7};
  int i, n = sizeof(a)/sizeof(int);
  
  printf("정렬 전 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  ShellSort(a, n);
  printf("\n쉘 정렬 후 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  return 0;
}
