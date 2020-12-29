// 기수 정렬
// 기수는 기본 숫자(0~9)를 의미함. 기수 정렬은 숫자를 0~9까지 10개의 버킷에 분배, 회수를 반복하면서 정렬하는 방법. 초기 데이터는 정렬시간과 무관함
/*
[오름차순 정렬 순서]
(1) 정렬 대상 중 가장 큰 수를 구한다.
(2) 전체 데이터를 1자리 값에 따라 0~9까지의 해당 버킷에 넣는다.
(3) 0 버킷부터 넣은 순서대로 회수한다.
(4) (2),(3) 과정을 10자리, 100자리, ... , 가장 높은 자리까지 반복한다.
*/

#include <stdio.h>
#include <stdlib.h>

void RadixSort(int *a, int n){
  int i, max = a[0], digit_base = 1;
  int digit_cnt[10] = {0, };
  int *bucket = (int *)malloc(sizeof(int)*n);
  
  for(i=0; i<n; i++)
    if(a[i]>max) max=a[i];
    
  while(digit_base<=max){
    for(i=0; i<n; i++)
      digit_cnt[a[i]/digit_base%10]++;
    for(i=1; i<10; i++)
      digit_cnt+=digit_cnt[i-1];
    for(i=n-1; i>=0; i--)
      bucket[--digit_cnt[a[i]/digit_base%10]] = a[i];
    for(i=0; i<n; i++)
      a[i] = bucket[i];
    for(i=0; i<10; i++)
      digit_cnt[i] = 0;
    printf("\n%6d 자리 정렬 : ", digit_base);
    for(i=0; i<n; i++)
      printf("  %d", a[i]);
    digit_base *= 10;
  }
  free(bucket);
}

int main(void){
  int a[] = {10, 258, 125, 3684, 50, 15, 654, 85476, 300, 525, 67, 9207, 2631, 728, 35026, 6027, 430};
  int i, n;
  
  n = sizeof(a)/sizeof(int);
  RadixSort(a, n);
  printf("\n정렬 후 : ");
  for(i=0; i<n; i++)
    printf("  %d", a[i]);
  printf("\n");
  return 0;
}
