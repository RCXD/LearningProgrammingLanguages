//1. ����� ���߱�
//2. �˰���: ����Ǯ��
//3. �ڵ� �ۼ�
//Advice: ����Ǯ�̸� ���� �غ���, �ڵ带 �ۼ��� ��!
//���� �� ������ ������������???


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
[��ȿ�� ����][���� 9:10] // 1. ����� ���߱�
// 2. �˰���: ����Ǯ��
// 3. �ڵ� �ۼ�
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
				// ����ǹ��� �������
				data[b - 1]--;
				b = x;
				data[b - 1]++;
				...
#endif 
