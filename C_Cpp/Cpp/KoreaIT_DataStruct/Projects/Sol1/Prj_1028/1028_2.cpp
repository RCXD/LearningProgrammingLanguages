#include "stdio.h"
#include "iostream"
#include "stdlib.h"


///
/// �׸� �ݵ�� �� �׸���, ���� �� �̸� Ǯ��� ��
/// 

//#define MYSELF
#define TEACHER
#ifdef TEACHER
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
void del(N* root, int data) {
	N* p = root;
	int sw = 1; // ����ġ���� ON
	while (p->next != NULL) {
		if (p->next->data == data) {
			sw = 0; // ����ġ���� OFF
			N* f = p->next; // ������ ��带 ����ų ������
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
void FREE(N* root) {
	printf("FREE()������...\n");
	N* p = root->next;
	N* f = root->next;
	while (p != NULL) {
		p = p->next; // ��ȸ�������� p�� �����̵�
		printf("%d���� ", f->data);
		free(f);
		f = p; // ���������������� f�� p�� ���� �̵�
	}
	printf("\nFREE()����Ϸ�\n");
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
	FREE(head);
	free(head);

	return 0;
}

#endif


#ifdef MYSELF
typedef struct NODE {
	int data;
	struct NODE* next;
}N;

//1. ���� �������Դϴ�!
//2. �ߺ� �������Դϴ�!
//3. �������� ���� //���� �ִ����� �� ũ�ٸ�, insert�ϸ� ��.
//4. 4��(����) => ����Ʈ�� ��� ��带 free()�ϴ� FREE(head) �Լ� �����

void add(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	//node->next -> root; //�̰Ÿ� �ڷ� �����ϴ°��ΰ�?
	//root->next = node; //�� �ڿ� �ϳ��� �������� �����ؾ��ϴµ�, �̷��� ��� ���ŵǾ������.

	N* p = root; //��Ʈ ��ü�� �ش�.
	while (p->next != NULL) { //������ ����Ű�°� NULL�̸� ������ �����.
		if (p->next->data == data) { //p->data==data�� ������ �����. ��, p=p->next �ڿ� ���� �̻����
			printf("�ߺ��� �������Դϴ�!\n");
			return;
		}
		p = p->next;
		//Teacher solution : ���⿡ if(p->data == data) �˻�. ������ �߿�!

		//show�� ��ȸ�����Ϳ� ���� �ٸ���. ��·�� �������� ã�°� �ƴѰ�?
	}
	p->next = node; //��ȸ�� �����Ͱ� ������ ���� �ٰ�����, �̸� ���� ���� ���� ��������
	printf("%d ������ �߰� �Ϸ�\n", data);
}
//���� : �׻� ������������ �߰��� �� �ֵ��� �ٲ����! ���������� ���� ��.

void show(N* root) {
	printf("show(): "); //show ȣ�� ���
	N* p = root->next; //root�� �ƴ�, root->next���� ����.
	while (p != NULL) { //p�� NULL�̸� ������ ������.
		if (p->next != NULL)
			printf("%d->", p->data);
		else if (p->next == NULL)
			printf("%d", p->data);
		p = p->next;
		//teacher solution: if(p == NULL) printf("->");
	}
	printf("\n");
}

void ascAdd(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;

	N* p = root;
	while (p->next != NULL) {
		if (p->next->data > data) {
			//�������� �������� �ɷ�����.
			break; //��ġ ã��
		}
		else if (p->next->data == data) {
			printf("�ߺ��� �������Դϴ�!\n");
			return;
		}
		p = p->next;
	}
	node->next = p->next->next; //�̰� ���� ����� p->next�� �Ҿ������ ����
	p->next = node;
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

void FREE(N* root) {
	printf("FREE() ���� ��...\n");
	N* p = root->next;
	while (p != NULL) {
		N* tmp = p;
		if (p->next == NULL) {
			printf("%d ����", p->data);
			free(p);
		}
		p = p->next;
	}
}

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int act;
	while (1) {
		//�������� ���� ��������
		printf("1. ����߰� 2. ������ 3. ����Ʈ��� 4. ����\n");
		printf("��ȣ�Է�: ");
		scanf("%d", &act);

		if (act == 1) {
			int data;
			printf("�����Է�: ");
			scanf("%d", &data);
			//add(head, data); //C�����Ϸ��� �̸� ���ǵ� �Լ��ϰŶ�?
			ascAdd(head, data);
		}
		else if (act == 2) {
			//��� ����
			int data;
			printf("���� �Է�: ");
			scanf("%d", &data);
			del(head, data); //remove()�� cpp�� �̹� �ִٰ� ��.
		}
		else if (act == 3) {
			//����Ʈ ���
			show(head);
		}
		else if (act == 4) {
			printf("���α׷� ����");
			break;
		}
		else {
			printf("�߸� �������ϴ�. �ٽ� �Է��ϼ��� \n");
		}
	}

	FREE(head);
	free(head);
	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *			head	10	20	30	NULL	
 *	next	10		20	30	NULL	
 *
 */