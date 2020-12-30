// 피보나치 검색
// 정렬된 데이터에서 피보나치(Fibonacci) 수열을 이용하는 방법. 피보나치수열이란 F(0) = 0, F(1) = 1, (F2) = F(0) + F(1), ... , F(i) = F(i-2)+F(i-1)
// 즉 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
/*
[검색 순서]
(1) fiboNum[k]<n을 만족하는 가장 큰 k를 구한다.
(2) 비교위치(pos) = index + fiboNum[--k] //index 초기값은 0
(3) pos 위치에 찾을 값이 있으면 완료
(4) pos가 찾을 범위를 벗어나거나 pos 위치의 값보다 찾을 값이 작으면 (2) 수행
    pos 위치의 값보다 찾을 값이 크면 index는 pos로 변경, k는 1 감소 후 (2) 수행
(5) k=0 일 때까지 (3)을 만나지 못하면 '없는 데이터'
*/

#include <stdio.h>
#include <limits.h>

int fiboSearch(int a[], int n, long s_value){
  int index = 0, pos, k = 0;
  static int fibo[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
  4181, 6465, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,39088169, 63245986, 102334155,
  165580141, 267914296, 433494437, 701408733, 1134903170, 183611903, INT_MAX};
  
  while(fibo[k]<n) k++;
  
  while(k>0){
    pos = index + fibo[--k];
    if(pos>=n||s_value<a[pos]);
    else if(s_value>a[pos]){ //찾고자 하는 값이 큰 경우
      index = pos;
      k--;
    }
    else return pos;
  }
  return -1;
}

int main(void){
  int a[] = {5, 12, 17, 20, 25, 33, 38, 41, 59, 65, 68, 70, 75, 87, 92, 95, 99};
  int n, search_data, i, pos;
  n = sizeof(a)/sizeof(int);
  
  for(i=0; i<n; i++){
    printf("%d  ", a[i]);
  printf("\n");
  printf("찾고자 하는 값 입력 : ");
  scanf_s("%d", &search_data);
  pos = fiboSearch(a, n, search_data);
  if(pos>=0)
    printf("\nfound %d at %d\n", search_data, pos);
  else
    printf("\nnot found.\n");
  return 0;
}
