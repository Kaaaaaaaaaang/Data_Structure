// 선형 큐

#include <stdio.h>
#define MAX 8
int queue[MAX] = {0, }, front = 0, rear = -1;

int ADD(int data){
  if(rear == MAX-1){
    printf("Queue is full!\n");
    return -1;
  }
  queue[++rear] = data;
  return 0;
}

int DELETE(){
  if(front>rear){
    printf("Queue is empty!\n");
    return -1;
  }
  return queue[front++];
}

int main(void){
  ADD(10); ADD(20); ADD(30);
  printf("%d\n", DELETE()); printf("%d\n", DELETE());
  return 0;
}

