#include<stdio.h>
#include<stdlib.h>
int main() {
	
	// ���� 1�� �Է�: 5
	// �Է��� ������ŭ �̾�Ĺ�� Ű�� �Է�: 5 3 7 1 9
	//  => 6

	int n;
	printf("���� 1�� �Է�: ");
	scanf("%d", &n);

	int *cat=(int*)malloc(n*sizeof(int));
	printf("�Է��� ������ŭ �̾�Ĺ�� Ű�� �Է�: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &cat[i]);
	}
	///
	int cnt = 0;
	for (int i = 0; i < n;i++) {
		// i�� 0�϶�, [0] Ű�� 5�� �̾�Ĺģ��
		for (int j = i +1; j < n; j++) {
			// j�� 1�϶�, �� ���� �񱳴���� [1] Ű�� 3�� ģ��
			cnt++;
			if (cat[i] < cat[j]) {
				break;
			}
		}
	}

	printf("cnt=%d\n", cnt);

	free(cat);

	return 0;
}