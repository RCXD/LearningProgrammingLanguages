#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
typedef struct NODE {
	int data; // �����ͺ�
	struct NODE* next; //�ּҺ� == ��ũ��
}N; //�ڱ���������ü ==��� //���� ������� �׳� ����ڷ����� ����Ű�� ������ �ϳ� �����Ѱ� ���ΰŰ�����?
//�޸� ũ�⸦ �̸� ����ϴ� �����Ϸ� ���ؿ����� �Ű��� �Ϸ���.(�ƴҰ� ���� �ϴ�.)

//����Ʈ�� �����ϰ��ִ� ����: ���


void main() {

	//head==root
	N* head = (N*)malloc(sizeof(N)/* *1 */); //ũ�� 1����°� ����. head�� 1ĭ¥�� ������ ����Ű�� �ȴ�.
	head->next = NULL; //head.next�� �ƴ�! ����ü ������ٿ�������. ������ ��������� ->�� ���

	//��� ����
	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 10;
	node1->next = NULL;

	//����Ʈȭ ���� �ʿ�.
	head->next = node1;

	//��� ����
	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 20;
	node2->next = NULL;

	//����
	node1->next = node2;

	//����Ʈ '�湮��' ������==��ȸ�� ������
	N* curr = head->next;
	//����Ʈ ������ ���
	while (curr !=NULL) //curr->next == NULL�� �������� curr == NULL�� ��
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	return;
}

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */