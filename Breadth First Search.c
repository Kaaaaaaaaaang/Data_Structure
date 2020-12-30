// 그래프 알고리즘
// 너비우선탐색(BFS)
// Queue 구조를 사용하여 모든 정점을 탐색하는 방법
/*
(1) 출발 정점을 정한다.
(2) 인접한 정점을 모두 차례로 방문하고 그 순서대로 Queue에 저장한다.
(3) Queue에서 정점을 꺼내 (2)를 반복한다.
(4) 만약 Queue가 비어있다면 탐색 완료
*/

#include <stdio.h>
#define SIZE 8

int queue[SIZE];
int rear = -1, front = 0;

typedef enum { false, true } bool;

void add(int index) {
	queue[++rear] = index;
}

int delete() {
	if (rear < front) return -1;
	return queue[front++];
}

void BreadthFirstSearch(char v[], bool a[][SIZE]) {
	bool searchOk[SIZE] = { false, };
	int i, j;
	char vertex;

	printf("\n시작 정점(A~G 중 입력) : ");
	scanf_s("%c", &vertex, 1);

	for (i = 0; i < SIZE; i++) if (vertex == v[i]) break;
	printf("\n깊이우선탐색 순서 : %c", v[i]);
	searchOk[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (a[i][j] == 1 && searchOk[j] == false) {
				printf(" -> %c", v[j]);
				add(j);
				searchOk[j] = true;
			}
		}
		if (j >= SIZE) i = delete();
	} while (i >= 0);
}

int main(void) {
	int i, j;
	char v[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	bool a[SIZE][SIZE] = { {0, 1, 1, 0, 0, 0, 0, 0},
			{1, 0, 0, 1, 1, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0, 0, 0, 1},
			{0, 1, 0, 0, 0, 0, 0, 1},
			{0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 0, 1, 1, 1, 1, 0} };

	printf("\n\t\t인접 정점\n");
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	BreadthFirstSearch(v, a);

	return 0;
}
