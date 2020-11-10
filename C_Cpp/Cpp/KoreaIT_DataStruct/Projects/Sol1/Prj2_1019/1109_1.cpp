//아래 있는것들은 렉쳐노트에 정리하자.
//효율적으로 정리할 방법을 생각해서 요점을 정리해보자.
//트리 Tree

//주소부(연결부)가 2개인 링크드 리스트를 활용할 예정

//디렉토리같은 개념이라나?

//트리에 데이터를 넣는 방법
//디렉토리처럼 짠다면 데이터를 검색하는건 불리하다.
//크기를 비교해서 이진탐색트리를 만들면, 검색에 매우 유리하다.

//트리는 모양보다 잘 저장하는것이 중요
//부모노드/자식노드
//이진탐색트리에서는 1개의 노드는 2개의 자식만 가질 수 있음. 부모는 1개만 가질 수 있음.
//최상위 노드의 이름: 루트 노드
//최하위 노드의 이름: 리프 노드(나무가 뒤집혀진 형태-뭐 굳이 거꾸로 그릴 필요도 없는거겠지만.)

//트리tree
//Binary tree
//디렉토리는 이진트리를 이용하지 않음.


#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//#define MYSELF
#define TEACHER
#ifdef TEACHER

typedef struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right; //트리는 연결부가 두개 임.
} N;

//트리에서는, 루트노드에 데이터를 저장함. 이전에 배우던 링크드리스트와는 차이를 둠!

void main() {

	int data;
	printf("현재 루트노드는 10입니다.\n");
	printf("자식노드에 들어갈 데이터를 입력하세요.\n");
	scanf(" %d", &data); //"%d "가 아니라 " %d"인가봄. 미리 비우고 받는 개념!

	N* root = (N*)malloc(sizeof(N));
	root->left = NULL;
	root->right = NULL;
	root->data = 10;
	
	N* node = (N*)malloc(sizeof(N));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	if (root->data > node->data) {
		printf("왼쪽 자식입니다.\n");
		root->left = node;
	}
	else {
		printf("오른쪽 자식이 됩니다.\n");
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

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */


