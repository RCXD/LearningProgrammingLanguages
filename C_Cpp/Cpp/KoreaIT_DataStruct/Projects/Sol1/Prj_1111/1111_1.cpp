//���� �����
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right;
}N;

//������ �ٲ� �� ������, �� �������� �� ������� ��!
/*
* 1. ���� ���θ���� �ؽ�Ʈ���� �ϳ� �����
* TEST(����) > input.txt �����
* 2. Ȯ���ڸ� ���� �����ϱ�
* Qx. �� Ȯ��� ������ ���ϸ� ��� �Ǵ°���?
*/

int main()
{
	//FILE* fp = fopen("TEST/input.txt", "r"); //Project Folder
	//FILE* fp = fopen("../TEST/input.txt", "r"); //Solution Folder
	//FILE* fp = fopen("../../TEST/input.txt", "r"); //outer Project Folder
	FILE* fp = fopen("../../../TEST/input.txt", "r"); //My Test Folder
	FILE* fp2 = fopen("../../../TEST/input2.txt", "w");
	//\�� /�� ���� �ٲٴ� ��� ����?

	//���̽��� ������ ����ٴ���, C�� �ȱ׷�����?

	//��ȿ�� �˻�: ������ �� ���ȴ��� Ȯ��	
	if (fp == NULL) {
		//���� �����ϸ� NULL�� ��ȯ���ִµ�? �׷� ������ �־�� �ڵ带 �̷��� ¥��
		printf("���Ͽ��� ����!\n");
	}
	else {
		printf("���Ͽ��� ����!\n");
	}

	int a;
	double b;
	char c;
	char d[10];
	fscanf(fp, "%d %lf %c %s", &a, &b, &c, d);
	printf("%d, %lf, %c, %s\n", a, b, c, d);

	fscanf(fp, "%d %lf %c %s", &a, &b, &c, d);
	printf("%d, %lf, %c, %s", a, b, c, d);

	fprintf(fp2, "%d %lf %c %s\n", a, b, c, d);
	fprintf(fp2, "���ϳ��� �ۼ� ����!\n", a, b, c, d);

	fclose(fp); //���� ���� �ݳ� ��ǻ�Ͱ� �ݰ��ϳ��� ���̰� �ִٰ� ��.
	fclose(fp2);
	return 0;
}