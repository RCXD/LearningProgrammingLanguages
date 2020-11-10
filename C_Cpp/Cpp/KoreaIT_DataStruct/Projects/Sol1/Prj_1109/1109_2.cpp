//Ʈ�� ���� TIP: 
//1) �� �׸��� �׷��� ��.
//2) �ǹ� �ݵ�� �ľ�
//3) Alternative Strategy�� �غ�����!


//Ʈ���� ����ϴ� ���
//������ȸ / ������ȸ / ������ȸ ���.
//����: ��Ʈ -> ���� -> ������


#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right; //Ʈ���� ����ΰ� �ΰ� ��.
} N;
N* create(N* node, int data) {
	if (node == NULL) {
		node = (N*)malloc(sizeof(N)); //���ǰ� �ʿ����. ����
		node->left = NULL;
		node->right = NULL;
		node->data = data;
	}
	else { //���� �����Ͱ�  ���� ���
		if (node->data > data) {
			printf("���ʿ� �߰���.\n");
			node->left = create(node->left, data);
		}
		else {
			printf("�����ʿ� �߰���.\n");
			node->right = create(node->right, data);
		}
	}
	return node;
}
//10 5 20 1 7 15 30������ �Է��� ��
/*
	       10
	5			20
1		7	15		30
*/

//10 5 1 7 20 15 30
void preOrder(N* node) {
	if (node != NULL) {
		printf("%d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}
//1 5 7 10 15 20 30
void inOrder(N* node) {
	if (node != NULL) {
		inOrder(node->left);
		printf("%d ", node->data);
		inOrder(node->right);
	}
}
//1 7 5 15 30 20 10  (���� ���� �� �̰� �״��� �θ� ...)
void postOrder(N* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf("%d ", node->data);
	}
}

///�߿� �˰���!
/*
p = c;
c = data < c->data ? c->left : c->right; //����...!! 
�Ʒ����� ���� �� ���� ����
if (c->data > data) {
	p = c;
	c = c->left;
	dir = 0;
}
else {
	p = c;
	c = c->right;
	dir = 1;
}
*/

//������ ���� ��ƴٰ� ��.
//case 0: ã�� ��尡 ���ų�
//case 1: ã�� ��尡 �ڽ��� ���ų�
//case 2: ã�� ��尡 �ڽ��� 1���̰ų�
	//���ʸ� ������, ���� �ڸ��� �÷����̸� �ȴ�.
//case 3: ã�� ��尡 �ڽ��� 2���� ���
	//������ ����Ʈ������ ���� ���� ���� ã�´�. (���� ������ ���� �۴�! �ʿ�������.)
		//������ ����Ʈ�������� sub c, sub p�� ���� ã�� ����. c�ڸ��� sub-p.
			//å���� �ٸ� ������ �ִ�. ���� ����Ʈ������ ���� ū���� ã�� ���� �ִ�.
void del(N* node, int data) {
	N* c= node; //current
	N* p= NULL; //parent
	//int dir = 0;
	while (c != NULL && c->data != data) { // c==NULL�� ���� ���Ѵ�?!(Ȯ�ιٶ�), �Ϻ� ���ǹ��� ������ �߿�!
		p = c;
		c = data < c->data ? c->left : c->right; //����...!!
	}
	if (c == NULL)
	{
		printf("�ش� ���� �����ϴ�.");
		return;
	}
	if (c->left==NULL && c->right==NULL) { //������� == �ܸ����... �ܸ���� ����: ��/�� ��� NULL
		if (p->left == c) {
			p->left = NULL;
		}
		else {
			p->right = NULL;
		}
		printf("������ ���� �Ϸ�!.\n", c->data);
		free(c);
	}
	//�ܸ���尡 �Ʒ� ���ǿ� ���ϹǷ� ���ǿ� ����
	//���� ���� �ٽ��� �����غ���.
	else if (c->left == NULL || c->right == NULL) { //������ ��尡 �ϳ��� ����Ʈ���� ���� ���
		N* f = c;
		printf("%d ���� �Ϸ�\n", c->data);
		if (p->left == c) {
			c = c->left == NULL ? c->right : c->left;//��Ƴ��ƾ��ϴ°� ã�����ֱ�
			p->left == c;
		}
		else {
			c = c->left == NULL ? c->right : c->left;
			p->right == c;
		}
		free(f);											
	}
	else { //������ ��尡 �� ���� ����Ʈ���� ���� ���
		//�������� 
		N* subp = c;
		N* subc = c->right;
		while (subc->left != NULL)
		{
			subp = subc;
			subc = subc->left;
		}
		//while���� ������� ���� �� ������ �ҽ� �߻�.
		if (c == subp) {
			c->right = subc->right;
		} //�̰� ���� �Ȱ�.��,.��
		else { //�����ڵ� Ȱ��
			subp->left = subc->right; 
			//subc->right�� NULL�̾ Ŀ����. ���� �����༮�� �ʿ������� �ڽ��� ������ or �ƿ� ����
		}
		printf("%d ������ �����Ϸ�!\n", c->data);
		c->data = subc->data;
		free(subc);
	}
}

//������ȸ�� �����غ���ʹ�..?

int main()
{
	N* root = NULL;
	while (1) {
		int act;
		printf("1. ������ 2. ���� 3. ���� 4. ���� 5. ������ 6. ����\n");
		scanf(" %d", &act);
		if (act == 1) {
			int data;
			printf("������ �Է�: ");
			scanf(" %d", &data);
			//if (isLeft(&root, data));
			root = create(root, data);
		}
		else if (act == 2) {
			preOrder(root);
			printf("\n");
		}
		else if (act == 3) {
			inOrder(root);
			printf("\n");
		}
		else if (act == 4) {
			postOrder(root);
			printf("\n");
		}
		else if (act == 5) {
			int data;
			printf("���� ������ �Է�");
			scanf(" %d", &data);
			del(root, data);
		}
		else {
			printf("���α׷� ����...\n");
			return 0;
		}
	}
	return 0;
}