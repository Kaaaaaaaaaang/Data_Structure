// 중복 순열
// n개의 데이터 중 r개를 중복을 허용하여 배열하는 경우. 예를 들어, 주사위 던지기
// 경우의 수 : n의 r제곱

// 데이터 교환을 하지 않는 방법
#include <stdio.h>
#define R 3

int b[R] = {0, };
int cnt = 0;

void PrintRePer(){
	int i;
	cnt++;
	
	for(i = 0; i < R; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
}

void Repermutation(int a[], int n, int r){
	int i;
	
	if(r>=R) PrintRePer();
	else for(i=0; i<n; i++){
		b[r] = a[i];
		RePermutation(a, n, r+1);
	}
}

int main(void){
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a)/sizeof(int);
	
	RePermutation(a, n, 0);
	printf("중복순열 개수 : %d\n", cnt);
	
	return 0;
}
