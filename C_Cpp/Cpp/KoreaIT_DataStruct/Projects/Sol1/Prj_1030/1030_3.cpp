#include "stdio.h"
#include "stdlib.h"
#include "iostream"



void push(int data) {
	stack[++index] = data; //���������� ���� ȿ����
	printf("%d push �Ϸ�\n", data);
}
int pop() { //���ù迭 �ڷ����� ���缭 ���
	return stack[index--]; //��ȯ �Ŀ� ó����. �ε����� 0���� ������ ��� ���������� �� ���� �ִٰ� ��.
}
int isFull(int index, int MAX) {
	//if (index == MAX) { �о�ֱ������ �ڵ��ϸ� ������ ����. �����ǥ�� �� ����.. 
		//����, ����м����� �̷��� ���� ���ٰ�..
	//if (index == MAX - 1) { //�迭�ε����� MAX-1���� ����.
	if (index == MAX) { //�̰� �´� ������ ����??????
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

	int len;
	printf("������ ũ�⸦ �Է��ϼ���. ");
	scanf("%d", &len);
	int* stack = (int*)malloc(len*sizeof(int));
	int index = 0; //���������� ���� ���� ������ �ʱ�ȭ�� ����
	//���� 1. �Լ� ���� �������·� �ϼ��ϱ�
	

	int act;
	while (1) {
		printf("1.push() 2.pop() 3.����\n");
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull(index, len)) {
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
