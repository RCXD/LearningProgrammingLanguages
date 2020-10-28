// ������������ ������ �߰��ϱ�!
// 4��(����) => ����Ʈ�� ��� ��带 free()�ϴ� �Լ� FREE() << �� �����ϱ�!
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
	N* p = root; // ����Ʈ�� ��������带 ã�� ��ȸ��������
	while (p->next != NULL) {
		p = p->next;
		if (p->data == data) {
			printf("�ߺ� �������Դϴ�!\n");
			return;
		}
	}
	p->next = node;
	printf("%d ������ �߰��Ϸ�!\n", data);
}
void del(N* root, int data) {
	N* p = root;
	int sw = 1; // ����ġ���� ON
	while (p->next != NULL) {
		if (p->next->data == data) {
			sw = 0; // ����ġ���� OFF
			N* f=p->next; // ������ ��带 ����ų ������
			p->next = p->next->next;
			free(f);
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("���� �������Դϴ�!\n");
	}
	else {
		printf("%d ������ �����Ϸ�!\n", data);
	}
}
void show(N* root) {
	printf("show(): ");
	N* p = root->next;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->next;
		if (p != NULL) {
			printf("->");
		}
	}
	printf("\n");
}
int main() {

	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int act;
	while (1) {
		printf("1.����߰� 2.������ 3.����Ʈ��� 4.����\n");
		printf("��ȣ�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			int data;
			printf("�����Է�: ");
			scanf("%d", &data);
			add(head, data);
		}
		else if (act == 2) {
			int data;
			printf("�����Է�: ");
			scanf("%d", &data);
			del(head, data);
		}
		else if (act == 3) {
			show(head);
		}
		else if (act == 4) {
			printf("���α׷� ����\n");
			break;
		}
		else {
			printf("�߸������̽��ϴ�.�ٽ� �Է��ϼ���.\n");
		}
	}
	//FREE(head);

	return 0;
}