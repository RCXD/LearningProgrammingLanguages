//1. 입출력 맟추기
//2. 알고리즘: 문제풀이
//3. 코드 작성
//Advice: 문제풀이를 먼저 해보고, 코드를 작성할 것!
//지금 이 시험이 무슨시험이지???


#include <stdio.h>

void main() {
	int cur_in = 0;
	int new_in = 0;
	int R = 0;
	FILE* in = fopen("../../../TEST/input.txt", "r");
	FILE* out = fopen("../../../TEST/output.txt", "w");

	int N, M, B;
	fscanf(in, "%d %d %d", &N, &M, &B);
	int n;
	for(int i=0; i<M; i++){
		fscanf(in, "%d %d", &n, &new_in);
		//printf("1. %d %d\n", new_in, cur_in);
		if (new_in == 1 && cur_in == 0) {
			R++;
		}
		cur_in = new_in;
		//printf("if cur_in = %d\nR=%d\n", cur_in, R);
	}
	fprintf(out, "%d", R);
	fclose(in);
	fclose(out);
}

#ifdef TEACHER
[김효경 강사][오후 9:10] // 1. 입출력 맞추기
// 2. 알고리즘: 문제풀이
// 3. 코드 작성
#include<stdio.h>
#include<stdlib.h>
int main() {

	FILE* fp = fopen("input.txt", "r");

	int n, m, b;
	scanf("%d%d%d", &n, &m, &b);
	int* data = (int*)malloc(n * sizeof(int));
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
				...
#endif 
