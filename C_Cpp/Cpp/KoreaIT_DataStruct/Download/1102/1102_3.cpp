// 1.���� 2.���� 3.����

// 1) ��⿭ ť�� ��� 1���߰�
// ���: �̸�,���Ź�ȣ,��ȭ����
// � ��ȭ�� ���ðڽ��ϱ�? 2
//  [1.aaa 2.bbb 3.ccc]
// ������ �����Է�: ȫ�浿
// ���Ź�ȣ�� �������� ���� ��� 1001~9999
// "ȫ�浿��, bbb��ȭ [1234]�Դϴ�."

// 2) �������? (ť�� ������� �� ū�Է½�, �Ұ����ϴٴ� �ȳ����!)
// ȫ�浿��, ���Ź�ȣ��? 1234
// bbb ��ſ� �����Ǽ���~!!
// �Ӳ�����, ���Ź�ȣ��? 1111
// ����Ұ�!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
typedef struct Per {
	int data;
	char movie[15];
	char name[15];
}P;
typedef struct NODE {
	P data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size;
}Q;
char MT[MAX][15] = { "����","�ٸ���","�Ҹ���" };
int main() {

	rand() % 8999 + 1001;

	return 0;
}