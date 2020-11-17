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
void inorder(N *node, FILE* out) {
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