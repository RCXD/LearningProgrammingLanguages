//�Ʒ� �ִ°͵��� ���ĳ�Ʈ�� ��������.
//ȿ�������� ������ ����� �����ؼ� ������ �����غ���.
//Ʈ�� Tree

//�ּҺ�(�����)�� 2���� ��ũ�� ����Ʈ�� Ȱ���� ����

//���丮���� �����̶�?

//Ʈ���� �����͸� �ִ� ���
//���丮ó�� §�ٸ� �����͸� �˻��ϴ°� �Ҹ��ϴ�.
//ũ�⸦ ���ؼ� ����Ž��Ʈ���� �����, �˻��� �ſ� �����ϴ�.

//Ʈ���� ��纸�� �� �����ϴ°��� �߿�
//�θ���/�ڽĳ��
//����Ž��Ʈ�������� 1���� ���� 2���� �ڽĸ� ���� �� ����. �θ�� 1���� ���� �� ����.
//�ֻ��� ����� �̸�: ��Ʈ ���
//������ ����� �̸�: ���� ���(������ �������� ����-�� ���� �Ųٷ� �׸� �ʿ䵵 ���°Ű�����.)

//Ʈ��tree
//Binary tree
//���丮�� ����Ʈ���� �̿����� ����.


#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//#define MYSELF
#define TEACHER
#ifdef TEACHER

typedef struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right; //Ʈ���� ����ΰ� �ΰ� ��.
} N;

//Ʈ��������, ��Ʈ��忡 �����͸� ������. ������ ���� ��ũ�帮��Ʈ�ʹ� ���̸� ��!

void main() {

	int data;
	printf("���� ��Ʈ���� 10�Դϴ�.\n");
	printf("�ڽĳ�忡 �� �����͸� �Է��ϼ���.\n");
	scanf(" %d", &data); //"%d "�� �ƴ϶� " %d"�ΰ���. �̸� ���� �޴� ����!

	N* root = (N*)malloc(sizeof(N));
	root->left = NULL;
	root->right = NULL;
	root->data = 10;
	
	N* node = (N*)malloc(sizeof(N));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	if (root->data > node->data) {
		printf("���� �ڽ��Դϴ�.\n");
		root->left = node;
	}
	else {
		printf("������ �ڽ��� �˴ϴ�.\n");
		root->right = node;
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


