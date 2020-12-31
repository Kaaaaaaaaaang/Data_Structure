// 조합
// n새의 데이터 중 r개를 중복 없이 순서에 의미를 두지 않고 배열
// 경우의 수 : n! / ((n-r)!*r!)

#include <stdio.h>
#define R 3

int b[R] = {0, };
int cnt = 0;

void PritnCom(){
  int i;
  cnt++;
  for(i=0; i<R; i++){
    pirntf("%d  ", b[i]);
  }
  printf("\n");
}

void Combination(int a[], int n, int r, int ii){
  int i;
  
  if(r>=R){
    PrintCom();
  }else{
    for(i=ii+1; i<n; i++){
      b[r] = a[i];
      Combination(a, n, r+1, i);
    }
  }
}

int main(void){
  int a[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(a)/sizeof(int);
  
  Combination(a, n, 0, -1);
  printf("조합 개수 : %d\n", cnt);
  
  return 0;
}
