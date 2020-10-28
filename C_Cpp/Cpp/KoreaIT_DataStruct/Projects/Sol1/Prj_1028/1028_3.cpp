#include "stdio.h"
#include "stdlib.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER

typedef struct stu {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;
typedef struct NODE {
	S data;
	struct NODE* next;
}N;
void add(N* root) {
	static int num = 1001;
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;
	printf("�л��̸�: ");
	scanf("%s", node->data.name);
	node->data.num = num++;
	for (int i = 0; i < 2; i++) {
		printf("����%d����: ", i + 1);
		scanf("%d", &node->data.score[i]);
	}
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void del(N* root, int num) {
	N* p = root;
	int sw = 1;
	while (p->next != NULL) {
		if (p->next->data.num == num) {
			sw = 0;
			N* f = p->next;
			p->next = p->next->next;
			free(f);
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("���� �л��Դϴ�!\n");
	}
	else {
		printf("���� �Ϸ�!\n");
	}
}
void modi(N* root, int num) {
	N* p = root->next;
	int sw = 1;
	while (p != NULL) {
		if (p->data.num == num) {
			sw = 0;
			printf("�л��̸�: ");
			scanf("%s", p->data.name);
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("���� �л��Դϴ�!\n");
	}
	else {
		printf("���� �Ϸ�!\n");
	}
}
void show(N* root) {
	N* p = root->next;
	while (p != NULL) {
		printf("%d. %-5s�л�\n", p->data.num, p->data.name);
		p = p->next;
	}
}
int main() {

	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int act;
	while (1) {
		printf("===�л���===\n");
		printf("1.�߰� 2.���� 3.���� 4.��� 5.����\n");
		printf("��ȣ�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			add(head);
		}
		else if (act == 2) {
			int num;
			printf("�������л��� ��ȣ�Է�: ");
			scanf("%d", &num);
			if (num <= 1000 || num >= 2000) {
				printf("�Է¹����� �ƴմϴ�!\n");
				continue;
			}
			del(head, num);
		}
		else if (act == 3) {
			int num;
			printf("�������л��� ��ȣ�Է�: ");
			scanf("%d", &num);
			if (num <= 1000 || num >= 2000) {
				printf("�Է¹����� �ƴմϴ�!\n");
				continue;
			}
			modi(head, num);
		}
		else if (act == 4) {
			show(head);
		}
		else {
			break;
		}
	}

	return 0;
}


#endif


#ifdef MYSELF
typedef struct stu {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;
typedef struct NODE {
	S data; //������ �����а� ����. ������ٵ� ����
	struct NODE* next;
}N;

void add(N* root) {
	static int num = 1001; //main�� ���������� add�� ����������.
	//�������� ������ �ߺ������Ǵ��� ���ʿ��Ҽ���.
	//�Լ� ����Ƚ�� ���� �� static������ ���� ����!
	//Ȯ���ϰ� num�� add������ �� �����̶�� ���. �������̹Ƿ� ���� �� �ٸ� �ɼǿ����� ������.
	//������ ���� ��ٷӴٴ°�.
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;
	printf("�л��̸�: ");
	scanf("%s", node->data.name);
	node->data.num = num++;
	for (int i = 0; i < 2; i++) {
		printf("����%d�� ����: ", i + 1);
		scanf("%s", &node->data.score[i]);
	}
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}

void show(N* root) {
	N* p = root->next; //head���� �����Ͱ� �����Ƿ� ���� root���� �� �ʿ� ����.
	while (p != NULL) {
		printf("%d. %-5s �л�\n", p->data.num, p->data.name); //���������ڷ� ����~!
		p = p->next;
	}
}

void del(N* root, int num) { //Ƽó �ڵ� Ȯ�ιٶ�
	int sw = 1;
	N* p = root; //������ �����ͺ��� �տ� �־����.
	while (p->next != NULL) {
		if (p->next->data.num == num) {
			sw = 0;
			N* f = p->next;
			p->next = p->next->next;
			free(f);
			//
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("���� �л��Դϴ�!\n");
	}
	else {
		printf("���� �Ϸ�!\n");//? free(f)�ؿ��� �ϰ������
	}
}

void modi(N* root, int num) {
	//�̸��ٲٱ�, �����ٲٱ� �� �̸��ٲٱ⸸ �ϴ� ����
	N* p = root->next; //������ ���� �� �ʿ� �����Ƿ� showó��.
	while (p != NULL) {
		if (p->data.num == num) {
			printf("�л��̸�: ");
			scanf("%s", &p->data.name);
			//�� �Ʒ����� Ƽó �ڵ� Ȯ�ιٶ�
			p->next = p->next->next;

			//
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("���� �л��Դϴ�!\n");
	}
	else {
		printf("���� �Ϸ�!\n");//? free(f)�ؿ��� �ϰ������
	}
}

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL; //�ǹ̾��� ���� NULLó���� �� ���־�� ��. �׷��� ������ ������� ������ �� ����

	//int num = 1001;//main���� �����ϴ���, static���� �Լ� ������ ������.

	int act;
	while (1) {
		printf("===�л���===\n");
		printf("1.�߰� 2. ���� 3. ���� 4. ��� 5. ����\n");
		printf("��ȣ �Է�: ");
		scanf(" %d", &act);

		if (act == 1) {
			add(head);
		}
		else if (act == 2) {
			int num;
			printf("������ �л��� ��ȣ �Է�: ");
			scanf("%d", &num);
			//���� �����ϱ�
			if (num <= 1000 || num >= 2000) {
				printf("�ӷ¹����� �ƴմϴ�!\n");
				continue;
			}
			del(head, num);
		}
		else if (act == 3) {
			modi(head, num);
		}
		else if (act == 4) {
			show(head);
		}
		else if (act == 5) {

		}
		else {
		}
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