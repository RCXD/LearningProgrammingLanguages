#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void inputNum(int *p) {
	int num;
	printf("������ ���� ��Դϱ�?  ");
	scanf("%d", &num);
	*p = num;
}
void show(int *data,int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main() {

	int num;
	inputNum(&num);
	int *lotto = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		lotto[i] = rand() % 50 + 1;
	}
	show(lotto,num);

	// 5
	// 1 2 3 4 5 << ��ǻ�Ͱ� ����!
	// 3�� �����մϴ�!

	// ����, ������ ���� Ȧ����� +1�� ����
	// num=5 -> 3���̻� [�����մϴ�!]
	// num=10 -> 5���̻� [�����մϴ�!]

	// ��������� ����
	int point = 0;
	for (int i = 0; i < num; i++) {
		if (lotto[i] % 2) { // lotto[i] % 2 == 1
			point++;
		}
	}
	printf("%d��! ", point);
	if (num / 2 <= point) {
		printf("�����մϴ�!");
	}
	printf("\n");

	return 0;
}