// 중복 조합
// 경우의 수 : {r+(n-1)}! / ((n-1)!*r!)

#include <stdio.h>
#define R 3

int b[R] = {0, };
int cnt = 0;

void PritnReCom(){
  int i;
  cnt++;
  for(i=0; i<R; i++){
    pirntf("%d  ", b[i]);
  }
  printf("\n");
}

void ReCombination(int a[], int n, int r, int ii){
  int i;
  
  if(r>=R){
    PrintReCom();
  }else{
    for(i=ii+1; i<n; i++){
      b[r] = a[i];
      ReCombination(a, n, r+1, i);
    }
  }
}

int main(void){
  int a[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(a)/sizeof(int);
  
  ReCombination(a, n, 0, -1);
  printf("중복 조합 개수 : %d\n", cnt);
  
  return 0;
}
