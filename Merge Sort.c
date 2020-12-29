// 병합 정렬
// 데이터를 병합하면서 정렬하는 방법. 초기 데이터가 정렬되어 있을수록 약간의 시간은 단축되나 크게 영향은 없다.
// 두 그룹을 하나로 병합해 나가는 방법을 2-Way Merge Sort라 한다. 3 그룹을 하나로 병합해 나가면 3-Way, k 그룹을 하나로 병합해 나가면 k-Way Merge Sort이다.
// 내부 정렬에서는 일반적으로 2-Way Merge Sort 방법을 사용한다.
/*
[2-Way Merge Sort 순서, 오름차순]
(1) 데이터를 하나가 될 때까지 분할한다.
(2) 하나로 분할된 데이터를 오름차순으로 병합한다.
(3) 정렬된 두 그룹을 병합한다.
(4) 한 그룹으로 병합될 때까지 (1)~(3)을 반복한다.
*/

#include <stdio.h>
#include <stdlib.h>

int n;

void Merge(int a[], int left, int mid, ine right){
  int *b = (int*)malloc(sizeof(int)*(right-left+1));
  int i = left, j = mid+1, k=0;
  
  while(i<=mid&&j<=right)
    if(a[i]<=a[j]) b[k++] = a[i++];
    else b[k++] = a[j++];
    
  if(i<=mid) while(i<=mid) b[k++] = a[i++];
  else while(j<=right) b[k++] = a[j++];
  k = 0;
  for(i=left; i<=right; i++) a[i] = b[k++];
  free(b);
}

void Division(int a[], int left, int right){
  int mid;
  
  if(left<right){
    mid = (left+right)/2;
    Division(a, left, mid);
    Division(a, mid+1, right);
    Merge(a, left, mid, right);
  }
}

int main(void){
  int a[] = {5, 33, 27, 12, 41, 25, 10, 56, 35, 18, 7};
  int i, n = sizeof(a)/sizeof(int);
  
  Division(a, 0, n-1);
  for(i=0; i<n; i++) printf("%d  ", a[i]);
  printf("\n");
  
  return 0;
}
