// 중복 순열
// n개의 데이터 중 r개를 중복을 허용하여 배열하는 경우. 예를 들어, 주사위 던지기
// 경우의 수 : n의 r제곱

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

void exchange(int *p1, int *p2){
	int temp = *p1;

	*p1 = *p2;
	*p2 = temp;
}

void RePermutation(int a[], int n, int r){
	int i;
	
	if(r >= R) PrintRePer();
	else for(i = 0; i < n; i++){
		exchange(a + 0, a + i); //exchange(&a[0], &a[i]);
		b[r] = a[0];
		RePermutation(a, n, r+1);
		exchange(a + 0, a + i);
	}
}

int main(void){
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);
	
	RePermutation(a, n, 0);
	
	printf("\nn = %d, r = %d 일때, 중복순열 개수: %d\n", n, R, cnt);
	
	return 0;
}
