// 버블 정렬
// 인접한 데이터와 비교를 해 교환하면서 정렬하는 방법. 초기 데이터가 정렬이 되어 있을수록 시간은 단축된다.
/*
[오름차순 정렬 순서]
(1) 인접한 값보다 더 크면 교환하며 끝까지 진행한다.
(2) 범위를 맨 끝부터 하나씩 줄이면서 같은 과정을 반복한다.
(3) 더 이상 자료의 교환이 없으면 종료한다.
*/

#include <stdio.h>

void BubbleSort(int a[], int n){
  int i=0, j, temp, flag=1;
  while(flag==1){
    flag = 0;
    i++;
    for(j=0; j<n-i; j++){
       if(a[j] > a[j+1]){
         temp = a[j];
         a[j] = a[j+1];
         a[j+1] = temp;
         flag = 1;
       }
    }
  }
}

int main(void){
  int a[] = {17, 8, 20, 11, 5, 12, 15, 7};
  int i, n = sizeof(a)/sizeof(int);
  
  printf("정렬 전 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  BubbleSort(a, n);
  printf("\n버블 정렬 후 : ");
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  return 0;
}
