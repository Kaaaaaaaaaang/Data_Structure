// 이분 검색
// 정렬된 자료에 대하여 검색하는 방법으로 가운데 값과 비교하여 찾는 값과 같으면 완료, 작으면 앞 부분, 크면 뒷 부분을 선택하여 같은 과정을 반복한다.
/*
[검색 순서]
(1) 가운데 데이터와 비교한다.
(2) 같으면 완료, 작으면 앞 쪽에서, 크면 뒤 쪽에서 찾는다.
(3) 이렇게 검색 범위를 절반으로 줄여 나간다. 최종적으로 검색 범위가 하나일 때도 같지 않으면 '없는 자료'이다.
*/

#include <stdio.h>

int binarySearch(int a[], int n, int key){
  int left = 0, right = n-1, middle;
  while(left<=right){
    middle = (left+right)/2;
    if(key>a[middle]) left = middle+1;
    else if(key<a[middle]) right = middle-1;
    else return middle;
  }
  return -1;
}

int main(void){
  int i, key, index, n;
  int a[] = {3, 7, 10, 12, 14, 18, 21, 33, 35, 48};
  n = sizeof(a)/sizeof(int);
  printf("찾을 대상 : ");
  for(i=0; i<n; i++) printf("%5d", a[i]);
  printf("\n 찾을 값 : ");
  scanf_s("%d", &key);
  index = binarySearch(a, n, key);
  if(index<0) printf("\n찾고자 하는 값이 없다!\n);
  else printf("\n%d을(를) %d에서 찾음!\n", key, index);
  return 0;
}
