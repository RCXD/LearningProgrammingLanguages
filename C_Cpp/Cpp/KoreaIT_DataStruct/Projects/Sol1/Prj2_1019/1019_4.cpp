#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "time.h"

#define MYSELF
//#define TEACHER
#ifdef TEACHER
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void inputNum(int* p) {
	int num;
	printf("������ ���� ��Դϱ�?  ");
	scanf("%d", &num);
	*p = num;
}
void show(int* data, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main() {

	int num;
	inputNum(&num);
	int* lotto = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		lotto[i] = rand() % 50 + 1;
   }
	show(lotto, num);

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
	if (num / 2 <= point) { //���� �Ѵ� �����ϴ� �̰� �� �����Ŵ�...!
		printf("�����մϴ�!");
	}
	printf("\n");

	return 0;
}


#endif


#ifdef MYSELF
void inputNum(int* num) { //�ڵ� �����ʿ�. num ������
	int input;
	printf("������ ���� ��Դϱ�?  ");
	scanf(" %d", &input);
	*num = input;
} //��ȯ�ϴ� ���� 1���̸� �Լ� ��ȯ������ ó���ϴ°� ����.
void show(int* data, int size) { //���ǰ� �����ֱ�
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

void main() {
	while (1) {
		int num;
		inputNum(&num);
		if (num == 99) break; //Ż��!
		int* lotto = (int*)malloc(num * sizeof(int));

		int cntOdd = 0;
		srand(time(NULL)); //�����Ҷ����� �ٲ�� �ϴ� ��
		for (int i = 0; i < num; i++) {
			lotto[i] = rand() % 50 + 1; //������ �ʴ� ��������. �����Ҷ����� �ٲ�� ����.
			//1~50�� ������ ��
			if (lotto[i] % 2) cntOdd++; //Ȧ�� ���� : %2 == 1
		}

		if (num == 5 && cntOdd >= 3) printf("�����մϴ�!\n");
		else if (num == 10 && cntOdd >= 5) printf("�����մϴ�!\n");
		show(lotto, num);

		//���� ������ ���� Ȧ����� +1�� ����
		//num = 5  -> 3�� �̻� [�����մϴ�!] //Ȧ���� 5���� 3�� �̻��̸�
		//num = 10 -> 5�� �̻� [�����մϴ�!] //Ȧ���� 10�� �� 5�� �̻��̸�
	}
	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *	
 *
 *
 */