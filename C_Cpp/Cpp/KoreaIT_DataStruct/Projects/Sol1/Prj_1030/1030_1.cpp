//7 3
//3 6 2 7 5 1 4
//�������깮��: �迭�� �ƴ�, ��ũ�帮��Ʈ�� ���°� �´�..

#include "stdio.h"
#include "iostream"

#define MYSELF
//#define TEACHER
#ifdef TEACHER
// 7 3
// 3 6 2 7 5 1 4
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
void add(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void add2(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
	node->next = root->next; // ����Ŭ�� ����!
}
int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	// h->1->2->3-> ... -> 7

	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;
	for (int i = 0; i < a - 1; i++) {
		add(head, i + 1);
	}
	add2(head, a);

	N* p = head;
	int cnt = 0;
	int c = 0;
	while (c != a) {
		cnt++;
		if (cnt == b) {
			c++;
			cnt = 0;
			printf("%d ", p->next->data);
			p->next = p->next->next;
			continue;
		}
		p = p->next;
	}
	printf("\n\n");
	/*
	N* p = head->next;
	while (p!=NULL) {
	   printf("%d ", p->data);
	   p = p->next;
	}
	*/

	return 0;
}

#endif

#ifdef MYSELF
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
void add(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root; // ����Ʈ�� ��������带 ã�� ��ȸ��������
	while (p->next != NULL) {
		if (p->next->data > data) {
			// ���������Է½�, ����ε� ��ġ�� ã��!
			node->next = p->next;
			break;
		}
		p = p->next;
		if (p->data == data) {
			printf("�ߺ� �������Դϴ�!\n");
			return;
		}
	}
	p->next = node;
	printf("%d ������ �߰��Ϸ�!\n", data);
}

void add2(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root; // ����Ʈ�� ��������带 ã�� ��ȸ��������
	while (p->next != NULL) {
		if (p->next->data > data) {
			// ���������Է½�, ����ε� ��ġ�� ã��!
			node->next = p->next;
			break;
		}
		p = p->next;
		if (p->data == data) {
			printf("�ߺ� �������Դϴ�!\n");
			return;
		}
	}
	p->next = node;
	node->next = root->next;//����Ŭ ����
	printf("%d ������ �߰��Ϸ�!\n", data);
}

//������ �ؾ� �� �� : ������ ���´�.
void del(N* root, int data) { //������ �ȵǰ� �ִµ�?? Ȯ����??
	//N* p = root->next; //show���� �̷� ������ root�� �����Ͱ� ���� ����.
	//root->next���� �����ϸ�, ��� �ٷ� ����(ù��°)�� �����ϰ� ���� �� �����ϱ� ���������.
	N* p = root; //
	while (p->next != NULL) { //������ ������ ���� ������ ��ȯ
		//if (���� p�� ����Ű�� ���'�� ����Ű��' �����Ͱ� ������ �������϶�) { //Sudo coding? �����ڵ�?
		if (p->next->data == data) {//�߰���, ������ ������ ��(Ÿ�� �տ� �������� ��)
			//free(p->next); //���⼭ �ϸ� next->next�� �̻��ѵ��� ������
			N* f = p->next; //��������� ����ų ������
			p->next = p->next->next; //p->next�� �����ع���!
			//free(p->next); //���⼭�� �׳��� ���� ����� ���̻� ����ų �� ����.
			free(f);
			return;
		}
		p = p->next; //Ÿ�� ��ã������ ����
	}
	printf("���� �������Դϴ�!\n");
}

void main() {
	int a, b;
	scanf("%d%d", &a, &b);
	//h->1->2->...->7

	N* head = (N*)malloc(sizeof(N));
	head->next=NULL;

	for (int i = 1; i < a/*a-1*/; i++) {
		add(head, i);
	}
	//cycle�� �ִ� ����Ʈ�� ������־�� �Ѵ�. ��������� �߰��� ���� �����ؾ� ��.
	add2(head, a);

	//N* p = head->next;
	int cnt = b+1;
	while (1) {
		if (--cnt == 0) {
			printf("%d ", p->next->data);
			N* f = p->next;
			p->next = p->next->next;
			free(f);
			cnt == b + 1;
		}
		p = p->next;
	} //���� �߸��������. 5->3->6->7->2->4->1, ���ѷ���. �����ٶ�
	///������!!
	///
	/*
	N* p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	*/
	

	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */