#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data; // �����ͺ�
	struct NODE* next; // �ּҺ�==��ũ��
}N; // �ڱ���������ü==���
int main() {

	// head==root : �����ͺθ� �̿���������
	N* head = (N*)malloc(sizeof(N));
	head->next=NULL; // head.next xxx

	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 1234;
	node1->next = NULL; // ������

	// ����Ʈȭ
	head->next = node1; // ��忬��

	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 321;
	node2->next = NULL;
	///
	node1->next = node2;

	// ����Ʈ ��� -> ��ȸ��������==�湮��������
	N* p = head->next;
	while (p!=NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

	return 0;
}