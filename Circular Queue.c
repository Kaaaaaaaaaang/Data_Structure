#include <stdio.h>
#define MAX 6

int rear = -1, front = 0;
int cqueue[MAX];
int cnt = 0;

int ADD(int item){
  if(cnt == MAX){
    printf("Circular Queue is Full\n");
    return -1;
  }
  cnt ++;
  cqueue[++rear&MAX] = item;
  return 0;
}

int DELETE(){
  if(cnt==0){
    printf("Circular Queue is Empty!\n");
    return -1;
  }
  cnt--;
  // front 1증가는 DELETE() 호출문 종료 직후
  return cqueue[front++%MAX];
}

int main(void){
  ADD(10); ADD(20);
  ADD(30); ADD(40);
  ADD(50); ADD(60);
  ADD(70);
  printf("%d\n", DELETE());
  printf("%d\n", DELETE());
  ADD(80); ADD(90);
  
  return 0;
}
