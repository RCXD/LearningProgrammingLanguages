#include "stdio.h"
#include "stdlib.h"
#include "iostream"



//#define MYSELF
#define TEACHER
#ifdef TEACHER
// [����] vs [ť]
// ����: ���ʳ������� �ڷḦ �ְų� �����ִ� ��������
//  �ֱٹ湮�� ��������, �������
//  ���Լ���==��������==FILO==LIFO
//  push() pop()
// -> "�迭"
#include<stdio.h>
#define MAX 5
int stack[MAX];
int index = -1; // stack�� �����Ͱ� ���������ʴ´�!
int isFull() {
	if (index == MAX - 1) { // ��
		return 1;
	}
	return 0;
}
int isEmpty() {
	if (index < 0) {
		return 1;
	}
	return 0;
}
void push(int data) {
	stack[++index] = data;
	printf("%d push()�Ϸ�!\n", data);
}
int pop() {
	return stack[index--];
}
int main() {

	int act;
	while (1) {
		printf("1.push() 2.pop() 3. peak() 4. size() 5.����\n"); //configure()��� �Լ�... ?? ���ο��� �� Ȯ��?
													 //peak�� pop�� �޸� ���� ���� �ε����� ���Ҹ� �˷���.
													//������ ������ peak ����
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("���ÿ� ������ �����ϴ�!\n");
				continue;
			}
			printf("�����Է�: ");
			int data;
			scanf("%d", &data);
			push(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("���ÿ� �����Ͱ� �����ϴ�!\n");
				continue;
			}
			printf("pop()����! [%d]\n", pop());
		}
		else if (act == 3) {
		}

		else if (act == 4) {
			printf("���� ���ÿ� %d�� �����մϴ�.\n", index+1); //index+1! �����ǥ..
		}
		else {
			printf("\n�����մϴ�...\n");
			break;
		}
	}

	return 0;
}
//������ �ٶ�!
#endif
#ifdef TEACHER2 //����, �����ذ� �ٶ�!
//main()���� ������ �����ϸ� �Լ��� ũ�Ⱑ Ŀ���ٰ� �Ѵ�.
//���������� ������ ȿ����.

#define MAX 100 //�迭 ������ ��ȣ����� ȿ����
int stack[MAX];
int index = -1; //������ ������ �׿����� �˷��� �ε���
//�ʱⰪ�� -1��. �迭�ε����� �ٸ� ������.

void push(int data) {
	stack[++index] = data; //���������� ���� ȿ����
	printf("%d push �Ϸ�\n", data);
}
int pop() { //���ù迭 �ڷ����� ���缭 ���
	return stack[index--]; //��ȯ �Ŀ� ó����. �ε����� 0���� ������ ��� ���������� �� ���� �ִٰ� ��.
}
int isFull() {
	//if (index == MAX) { �о�ֱ������ �ڵ��ϸ� ������ ����. �����ǥ�� �� ����.. 
		//����, ����м����� �̷��� ���� ���ٰ�..
	if (index == MAX - 1) { //�迭�ε����� MAX-1���� ����.
		return 1;
	}
	return 0;
}
int isEmpty() {
	//if (index == MAX) { �о�ֱ������ �ڵ��ϸ� ������ ����. �����ǥ�� �� ����.. 
		//����, ����м����� �̷��� ���� ���ٰ�..
	if (index == -1) { //�迭�ε����� MAX-1���� ����.
		return 1;
	}
	return 0;
}

void main() {
	int act;
	while (1) {
		printf("1.push() 2.pop() 3.����\n");
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("���ÿ� ������ �����ϴ�!\n");
				continue;
			}
			int data;
			printf("�����͸� �Է����ּ���: ");
			scanf("%d", &data);
			push(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("�����Ͱ� �����ϴ�!\n");
				continue;
			}
		}
		else {
			printf("\n�����մϴ�...\n");
			break;
		}
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
 * index -1 0 1 2 3 ... MAX
 *		 dt	dtdtdtdt ...dt
 *
 */