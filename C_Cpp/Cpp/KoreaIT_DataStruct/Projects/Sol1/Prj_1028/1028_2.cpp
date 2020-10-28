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

//1. ���� �������Դϴ�!
//2. �ߺ� �������Դϴ�!
//3. �������� ����
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
	printf("%d ������ �߰� �Ϸ�\n",data);
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
			add(head, data); //C�����Ϸ��� �̸� ���ǵ� �Լ��ϰŶ�?
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
	free(head);
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
 *			head	10	20	30	NULL	
 *	next	10		20	30	NULL	
 *
 */