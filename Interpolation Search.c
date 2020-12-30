// 보간 검색
// 오름차순 정렬된 데이터에서 근접 위치를 구하여 찾는 방법
/*
[검색 순서] 찾고자 하는 값 key
(1) 검색 대상의 첫 번째를 left, 마지막을 right로 한다.
(2) 비교 위치를 다음과 같이 구하여 middle로 한다.
    middle = left + (right-left)*(key-a[left)/(a[right]-a[left])
(3) key == a[middle]이면 검색 완료,
    key > a[middle]이면 left = middle+1,
    key < a[middle]이면 right = middle-1로 범위 수정하여 반복 검색
*/

#include <stdio.h>
int interpolationSearch(int a[], int n, int key){
  int left=0, right=n-1, middle;
  while(left<=right){
    if(a[left]<a[right]){ //나눗셈의 분모, 0 방지
    middle = left+(right-left)*(key-a[left])/(a[right]-a[left]);
    if(middle>right) middle=right;
    if(middle<left) middle=left;
  }
    else middle=left;
  
    if(key==a[middle]) return middle;
    else if(key>a[middle]) left = middle+1;
    else right = middle-1;
  }
  return -1;
}

int main(void){
  int i, key, index, n;
  int a[] = {3, 7, 10, 12, 14, 18, 21, 33, 35, 48};
  n = sizeof(a)/sizeof(int);
  
  printf("찾을 대상 : ");
  for(i=0; i<n; i++) printf("%5d  ", a[i]);
  printf("\n");
  
  printf("찾을 값 : "); scanf_s("%d", &key);
  index = interpolationSearch(a, n, key);
  
  if(index<0) printf("\n찾고자 하는 값이 없다...\n");
  else printf("\n%d은(는) %d에서 찾음\n", key, index);
}
