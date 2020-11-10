//트리 공부 TIP: 
//1) 꼭 그림을 그려야 함.
//2) 의미 반드시 파악
//3) Alternative Strategy도 해봐야함!


//트리를 출력하는 방법
//전위순회 / 중위순회 / 후위순회 방식.
//전위: 루트 -> 왼쪽 -> 오른쪽


#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right; //트리는 연결부가 두개 임.
} N;
N* create(N* node, int data) {
	if (node == NULL) {
		node = (N*)malloc(sizeof(N)); //정의가 필요없음. 유의
		node->left = NULL;
		node->right = NULL;
		node->data = data;
	}
	else { //뭔가 데이터가  있을 경우
		if (node->data > data) {
			printf("왼쪽에 추가됨.\n");
			node->left = create(node->left, data);
		}
		else {
			printf("오른쪽에 추가됨.\n");
			node->right = create(node->right, data);
		}
	}
	return node;
}
//10 5 20 1 7 15 30순으로 입력할 때
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
//1 7 5 15 30 20 10  (리프 먼저 다 뽑고 그다음 부모 ...)
void postOrder(N* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf("%d ", node->data);
	}
}

///중요 알고리즘!
/*
p = c;
c = data < c->data ? c->left : c->right; //조건...!! 
아래보다 위가 더 나은 형태
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

//삭제가 무지 어렵다고 함.
//case 0: 찾는 노드가 없거나
//case 1: 찾는 노드가 자식이 없거나
//case 2: 찾는 노드가 자식이 1개이거나
	//왼쪽만 있으면, 원래 자리로 올려붙이면 된다.
//case 3: 찾는 노드가 자식이 2개일 경우
	//오른쪽 서브트리에서 가장 작은 값을 찾는다. (가장 왼쪽이 가장 작다! 필연적으로.)
		//오른쪽 서브트리에서는 sub c, sub p를 만들어서 찾을 예정. c자리가 sub-p.
			//책마다 다른 전략도 있다. 왼쪽 서브트리에서 가장 큰값을 찾을 수도 있다.
void del(N* node, int data) {
	N* c= node; //current
	N* p= NULL; //parent
	//int dir = 0;
	while (c != NULL && c->data != data) { // c==NULL이 되지 못한다?!(확인바람), 일부 조건문은 서순이 중요!
		p = c;
		c = data < c->data ? c->left : c->right; //조건...!!
	}
	if (c == NULL)
	{
		printf("해당 노드는 없습니다.");
		return;
	}
	if (c->left==NULL && c->right==NULL) { //리프노드 == 단말노드... 단말노드 조건: 좌/우 노드 NULL
		if (p->left == c) {
			p->left = NULL;
		}
		else {
			p->right = NULL;
		}
		printf("데이터 삭제 완료!.\n", c->data);
		free(c);
	}
	//단말노드가 아래 조건에 속하므로 조건에 유의
	//여기 조건 다시좀 생각해보자.
	else if (c->left == NULL || c->right == NULL) { //삭제할 노드가 하나의 서브트리를 가진 경우
		N* f = c;
		printf("%d 삭제 완료\n", c->data);
		if (p->left == c) {
			c = c->left == NULL ? c->right : c->left;//살아남아야하는것 찾게해주기
			p->left == c;
		}
		else {
			c = c->left == NULL ? c->right : c->left;
			p->right == c;
		}
		free(f);											
	}
	else { //삭제할 노드가 두 개의 서브트리를 가진 경우
		//여러가지 
		N* subp = c;
		N* subc = c->right;
		while (subc->left != NULL)
		{
			subp = subc;
			subc = subc->left;
		}
		//while문이 실행되지 않을 때 데이터 소실 발생.
		if (c == subp) {
			c->right = subc->right;
		} //이거 이해 안감.ㅡ,.ㅡ
		else { //기존코드 활용
			subp->left = subc->right; 
			//subc->right이 NULL이어도 커버됨. 가장 작은녀석은 필연적으로 자식이 오른쪽 or 아예 없음
		}
		printf("%d 데이터 삭제완료!\n", c->data);
		c->data = subc->data;
		free(subc);
	}
}

//층별순회도 구현해보고싶다..?

int main()
{
	N* root = NULL;
	while (1) {
		int act;
		printf("1. 노드생성 2. 전위 3. 중위 4. 후위 5. 노드삭제 6. 종료\n");
		scanf(" %d", &act);
		if (act == 1) {
			int data;
			printf("데이터 입력: ");
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
			printf("삭제 데이터 입력");
			scanf(" %d", &data);
			del(root, data);
		}
		else {
			printf("프로그램 종료...\n");
			return 0;
		}
	}
	return 0;
}