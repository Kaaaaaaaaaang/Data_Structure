// 이진 트리 검색
// 이진 트리를 구성하여 검색하는 방법
/*
[검색 순서]
(1) 루트에서 출발
(2) 같으면 '완료', 작으면 왼쪽 자노드로 이동, 크면 오른쪽 자노드로 이동
(3) NULL을 만날 때까지 (2)를 반복하였다면 '없는 값'
*/

#include <stdio.h>
#include <stdlib.h>
#define NEW (struct node *) malloc(sizeof(struct node))

struct node{
  struct node *link;
  int data;
  struct node *rlink;
}

struct node *BinaryTree(int a[], int low, int high){
  int mid;
  struct node *p = NULL;
  
  if(low<=high){
    mid = (low+high)/2;
    p = NEW;
    p->data = a[mid];
    p->link = BinaryTree(a, low, mid-1);
    p->rlink = BinaryTree(a, mid+1, high);
  }
  return p;
}

void search_data(struct node *p){
  int cnt=0, value;
  
  printf("\n찾을 데이터 : ");
  scanf_s("%d", &value);
  while(p!=NULL){
    cnt++;
    if(value==p->data) break;
    if(value<p->data) p = p->link;
    else p = p->rlink;
  }
  if(p!=NULL) printf("%d을(를) %d번 비교하여 찾음!\n", value, cnt);
  else printf("%d은(는) 없는 데이터!\n", value);
}

void DeleteAll(struct node *DelNode){
  if(DelNode!=NULL){
    DeleteAll(DelNode -> link);
    DeleteAll(DelNode -> rlink);
    printf("%d  ", DelNode -> data);
    free(DelNode);
  }
}

int main(void){
  int a[10] = {3, 5, 7, 10, 15, 17, 20, 25, 28, 31};
  struct node *root;
  
  root = BinaryTree(a, 0, 9);
  search_data(root);
  printf("삭제 순서 : "); DeleteAll(root);
  return 0;
}
