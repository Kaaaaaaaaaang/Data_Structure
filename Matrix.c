// 행렬 알고리즘
/*
행렬의 합 : 두 행렬의 크기는 같아야 함
행렬의 차 : 두 행렬의 크기는 같아야 함
행렬의 곱 : 행렬 A의 크기가 (m, n)이고 행렬 B의 크기가 (n, 0)일 때, A * B = C에서 행렬 C의 크기는 (m, 0)
*/

#include <stdio.h>

void Matrix_Addition(int a1[3][2], int a2[3][2]){
  int i, j, c[3][2];
  for(i=0; i<3; i++){
    for(j=0; j<2; j++) 
      c[i][j] = a1[i][j] + a2[i][j];
  }
  
  printf("행렬의 합\n\n");
  for(i=0; i<3; i++){
    for(j=0; j<2; j++) 
      printf("%d\t", c[i][j]);
    printf("\n");
  }printf("\n\n");
}

void Matrix_Subtraction(int a1[3][2], int a2[3][2]){
  int i, j, c[3][2];
  for(i=0; i<3; i++){
    for(j=0; j<2; j++)
      c[i][j] = a1[i][j] - a2[i][j];
  }
  printf("행렬의 차\n\n");
  for(i=0; i<3; i++){
    for(j=0; j<2; j++)
      printf("5d\t", c[i][j]);
    printf("\n");
  }printf("\n\n");
}

void Matrix_Multiflication(int a1[3][2], int a2[2][4]){
  int i, j, k, c[3][4] = {0, };
  for(i=0; i<3; i++){
    for(j=0; j<4; j++){
      for(k=0; k<2; k++){
        c[i][j] += a1[i][k] * b[k][j];
      }
    }
  }
  printf("행렬의 곱\n\n");
  for(i=0; i<3; i++)
    for(j=0; j<4; j++)
      printf("%d\t", c[i][j]);
    printf("\n");
  }printf("\n");
}

int main(void){
  int a1[3][2] = {{5, 3}, {-2, 4}, {2, 3}};
  int a2[3][2] = {{3, 0}, {1, 6}, {2, 2}};
  int b[2][4] = {{3, 3, -1, 2}, {5, 7, 1, 0}};
  
  Matrix_Addition(a1, a2);
  Matrix_Subtraction(a1, a2);
  Matrix_Multiflication(a1, b);
  
  return 0;
}
