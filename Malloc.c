#include <stdio.h>
#include <stlib.h>

int main(void){
  struct node{
    char data;
    struct node *link;
  };
  struct node *p;
  p = (struct node*)malloc(sizeof(struct node));
  p->data = 'A';
  p->link = (struct node*)malloc(sizeof(struct node));
  p->link->data = 'B';
  p->link->link = (struct node*)malloc(sizeof(struct node));
  p->link->link->data = 'C';
  p->link->link->link = NULL;
  return 0;
}
