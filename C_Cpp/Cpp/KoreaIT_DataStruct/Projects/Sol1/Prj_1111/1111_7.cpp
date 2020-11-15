//1. ������ �����͵��� Ʈ���� ����
//2. ������ȸ ����� output.txt�� ���(��������)
//
//�� �ܿ�°� �߿��Ѱ�??

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* l;
	struct node* r;
}N;

N* create(N* node, int data) {
	if (node == NULL) {
		node = (N*)malloc(sizeof(N));
		node->l = NULL;
		node->r = NULL;
		node->data = data;
	}
	else {
		if (node->data > data) {
			node->l = create(node->l, data);
		}
		else {
			node->r = create(node->r, data);
		}
	}
	return node;
}

void inOrder(N* node, FILE* out) {
	if (node != NULL) {
		inOrder(node->l, out);
		//printf("%d ", node->data);
		fprintf(out, "%d ", node->data); //��� ������.... ��̷� �Ϸ��� ��� �ؾ��ϳ�?
		inOrder(node->r, out);
	}
}


void main() {

	FILE* in = fopen("../../../TEST/input.txt", "r");
	FILE* out = fopen("../../../TEST/output.txt", "w");

	N* root = NULL;
	
	while (!feof(in)) {
		int data;
		fscanf(in, "%d", &data);
		root = create(root, data);
	}

	inOrder(root, out);

	fclose(in);
	fclose(out);
}

#ifdef TEACHER
// 1. Ʈ���� ����
// 2. ������ȸ ��� -> output.txt
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data;
	struct NODE* L;
	struct NODE* R;
}N;
N* create(N* node, int data) {
	if (node == NULL) {
		node = (N*)malloc(sizeof(N));
		node->data = data;
		node->L = NULL;
		node->R = NULL;
	}
	else {
		if (node->data > data) {
			node->L = create(node->L, data);
		}
		else {
			node->R = create(node->R, data);
		}
	}
	return node;
}
void inorder(N* node, FILE* out) {
	if (node != NULL) {
		inorder(node->L, out);
		fprintf(out, "%d ", node->data);
		inorder(node->R, out);
	}
}

int main() {

	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	N* root = NULL;

	while (!feof(in)) {
		int data;
		fscanf(in, "%d", &data);
		root = create(root, data);
	}
	inorder(root, out);

	fclose(in);
	fclose(out);

	return 0;
}
#endif
