// 순차 검색
// 처음부터 마지막까지 순차적으로 비교하면서 찾는 방법. 따라서 자료가 정렬되어 있지 않아도 됨. 자료가 1,000개 일 때 최대 1,000번 비교한다.
/*
[검색 순서]
(1) 맨 처음 데이터와 비교한다.
(2) 같지 않으면 다음 데이터와 비교한다.
(3) 마지막까지 반복하여 찾고자 하는 값이 없으면 '없는 자료'이다.
*/

#include <stdio.h>

int seqSearch(int a[], int n, int key){
  int i;
  for(i=0; i<n; i++){
    if(a[i]==key) return i;
  return -1;
}

int main(void){
  int i, key, index, n;
  int a[] = {5, 30, 27, 11, 35, 48, 10, 21};
  n = sizeof(a)/sizeof(int);
  printf("찾을 대상 : ");
  for(i=0; i<n; i++)
    printf("%5d", a[i]);
  printf("\n");
  printf("찾을 데이터 : ");
  scanf_s("%d", &key);
  index = seqSearch(a, n, key);
  if(index>=0) printf("\n%d을(를) %d에서 찾음!\n", key, index);
  else printf("\n찾고자 하는 값이 없다!\n");
  return 0;
}
