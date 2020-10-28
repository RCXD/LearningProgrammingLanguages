#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//#define MYSELF
#define TEACHER
#ifdef TEACHER

typedef struct NODE {
	int data;
	struct NODE* next;
}N;

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;
	
	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 100;
	node1->next = NULL;

	head->next = node1;

	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 200;
	node2->next = NULL;

	node1->next = node2;
	
	//�湮�� ������==��ȸ�� ������
	N* p = head->next; 
	//����� �����ʹ� ��������Ƿ� ����Ű�°� �ǹ̰� ����.
	//����� ����, �� node1�� ���� ����Ŵ
	//head�� �̿��ؼ� node1�� ����Ű�� ������, 
	//node1, 2�� ���̻� ��������� ����ų �� ���� �����̱� �����ε�.
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

	free(head);
	free(node1);
	free(node2);
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