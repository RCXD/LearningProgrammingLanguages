#include<stdio.h>
int main() {

	FILE* fp = fopen("input.txt","r");
	// ������ �������������� ������ �߻�!
	
	FILE* fp2 = fopen("output.txt", "w");

	// ��ȿ�� �˻�
	if (fp == NULL) {
		printf("���Ͽ������!\n");
	}
	else {
		printf("���Ͽ��⼺��!\n");
	}

	int a;
	double b;
	char c;
	char d[10];
	fscanf(fp,"%d %lf %c %s", &a, &b, &c, d);
	fprintf(fp2, "%d %lf %c %s\n", a, b, c, d);
	fprintf(fp2, "���ϳ����ۼ�����!\n");

	fclose(fp);
	fclose(fp2);

	return 0;
}