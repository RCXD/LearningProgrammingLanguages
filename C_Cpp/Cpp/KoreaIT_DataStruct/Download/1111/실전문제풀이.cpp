// 1. ����� ���߱�
// 2. �˰���: ����Ǯ��
// 3. �ڵ� �ۼ�
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
				// ����ǹ��� �������
				data[b - 1]--;
				b = x;
				data[b - 1]++;
			}
			else {
				// ����ǹ��� ������
				b = x;
				data[b - 1]++;
			}
			// ����ʿ�
		}
		else {
			// ����ʿ�x
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