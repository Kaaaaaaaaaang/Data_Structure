// 힙 정렬
// 최대 힙(Max Heap) 또는 최소 힙(Min Heap)을 구성하여 정렬해나가는 방법. 최대 힙은 모든 노드에 대하여 부모 노드(Parent Node)는 자식 노드(Child Node)보다 크거나 같은 값을 가진다.
/ 최소 힙은 반대로 모든 노드에 대하여 부모 노드(Parent Node)는 자식 노드(Child Node)보다 작거나 같은 값을 가진다.
/*
[오름차순 정렬 순서]
(1) 최대 힙을 구성한다.
(2) root 값과 마지막 노드 값 교한하고 범위를 1 감소
(3) 최대 힙 다시 구성
(4) 과정 (2), (3)을 범위 1이 될 때까지 반복한다.
*/

#include <stdio.h>

void HeapSort(int a[], int n){
  int i, parent, child, value, m=n;
  //최대 힙 구성
  for(i=n/2; i>=1; i--){
    value = a[i];
    parent = i;
    while((child = parent*2) <= n){
      if(child+1 <= n && a[child] < a[child+1]) child++1;
      if(value>=a[child]) break;
      a[parent] = a[child];
      parent = child;
    }
    a[parent] = value;
  }
  
  // 힙 정렬
  while(n>1){
    value = a[n];
    a[n--] = a[1];
    parent = 1;
    while((child = parent*2)<=n){
      if(child+1 <= n && a[child] < a[child+1]) child++;
      if(value>=a[child]) break;
      a[parent] = a[child];
      parent = child;
    }
    a[parent] = value;
    for(i=1; i<=m; i++)
      printf("  %d", a[i]);
    printf("\n");
  }
}

int main(void){
  int a[] = {NULL, 10, 7, 1, 18, 6, 3, 15, 11, 12, 25}; // a[0]은 사용하지 않음
  int i, n = sizeof(a)/sizeof(int);
  printf("정렬 전 : ");
  for(i=1; i<n; i++) printf("%d  ", a[i]);
  HeapSort(a, n-1);
  printf("\n힙 정렬 후 : ");
  for(i=1; i<n; i++) printf("%d  ", a[i]);
  return 0;
}
