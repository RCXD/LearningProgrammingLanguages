#include<stdio.h>
int main() {

	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	printf("������� �̸��� �Է��ϼ���.\n");
	char name[10];
	scanf("%s", name);

	int data, n, cnt = 0;
	fscanf(in, "%d", &data);
	while (1) {
		printf("�������Է�: ");
		scanf("%d", &n);
		cnt++;
		if (n == data) {
			printf("����!\n");
			break;
		}
		else if (n > data) {
			printf("DOWN!\n");
		}
		else {
			printf("UP!\n");
		}
	} // ����Ž��
	fprintf(out, "%s��, %d������ ����!\n", name, cnt);

	fclose(in);

	return 0;
}