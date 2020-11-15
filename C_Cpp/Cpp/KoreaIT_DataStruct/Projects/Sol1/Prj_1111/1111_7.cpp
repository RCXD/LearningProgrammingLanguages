//1. 임의의 데이터들을 트리에 저장
//2. 중위순회 결과를 output.txt에 출력(오름차순)
//
//다 외우는게 중요한가??

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
		fprintf(out, "%d ", node->data); //요건 몰랐네.... 어레이로 하려면 어떻게 해야하나?
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
// 1. 트리에 저장
// 2. 중위순회 결과 -> output.txt
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
