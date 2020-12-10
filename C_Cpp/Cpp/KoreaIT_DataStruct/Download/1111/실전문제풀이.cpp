// 1. 입출력 맞추기
// 2. 알고리즘: 문제풀이
// 3. 코드 작성
#include<stdio.h>
#include<stdlib.h>
int main() {

	FILE* fp = fopen("input.txt", "r");

	int n, m, b;
	scanf("%d%d%d", &n, &m, &b);
	int *data=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		data[i] = 0;
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		if (y) {
			if (data[b - 1]) {
				// 현재건물에 우산있음
				data[b - 1]--;
				b = x;
				data[b - 1]++;
			}
			else {
				// 현재건물에 우산없음
				b = x;
				data[b - 1]++;
			}
			// 우산필요
		}
		else {
			// 우산필요x
			b = x;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += data[i];
	}
	printf("%d\n", cnt);

	return 0;
}