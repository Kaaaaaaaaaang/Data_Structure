// 그래프 알고리즘
// 깊이 우선 탐색 DFS
// Stack 구조를 사용하여 모든 정점을 탐색하는 방법
/*
(1) 출발 정점을 정한다.
(2) 인접한 정점을 검사하여 낮은 인덱스를 전진할 정점으로 정한다.
(3) 방문표시 및 현재 정점을 Stack에 저장하고 전진한다.
(4) 전진할 정점이 없으면 Stack에 Pop하여 (2)로 간다. 만약 Stack이 비어있다면 탐색 완료
*/

#include <stdio.h>
#define SIZE 8

int stack[SIZE] = {0, };
int top = -1;

typedef enum { false, true } bool;

bool push(int index){
	stack[++top] = index;
}

int pop(){
	if(top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(char v[], bool a[][SIZE]){
	bool searchOk[SIZE] = {false, };
	int i, j;
	char vertex;

	printf("\n시작 정점(A~G 중 입력) : ");
	scanf_s("%c", & vertex, 1);

	for(i = 0; i < SIZE; i++) if( vertex == v[i]) break;
	printf("\n깊이우선탐색 순서 : %c", v[i]);
	searchOk[i] = true;
	do{
		for(j = 0; j < SIZE; j++){
			if(a[i][j] == 1 && searchOk[j] == false){
					printf(" -> %c", v[j]);
					push(i);
					searchOk[j] = true;
					i = j;
					break;
				}
		}
		if(j >= SIZE) i = pop();
	} while(i >= 0);
}

int main(void){
	int i, j;
	char v[SIZE]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	bool a[SIZE][SIZE]={{0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0, 0, 0},
			{1, 1, 0, 1, 1, 0, 1, 0},
			{0, 0, 1, 0, 0, 1, 1, 0},
			{0, 0, 1, 0, 0, 0, 1, 0},
			{0, 0, 0, 1, 0, 0, 0, 1},
			{0, 0, 1, 1, 1, 0, 0, 1},
			{0, 0, 0, 0, 0, 1, 1, 0}};
		
	printf("\n\t\t인접 정점\n");
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	DepthFirstSearch(v, a);

	return 0;
}
