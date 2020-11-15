//파일 입출력
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right;
}N;

//설정이 바뀔 수 있으니, 이 설정들을 잘 적어놓을 것!
/*
* 1. 폴더 새로만들고 텍스트파일 하나 만들기
* TEST(폴더) > input.txt 만들기
* 2. 확장자명 숨김 해제하기
* Qx. 이 확장명 해제를 안하면 어떻게 되는거지?
*/

int main()
{
	//FILE* fp = fopen("TEST/input.txt", "r"); //Project Folder
	//FILE* fp = fopen("../TEST/input.txt", "r"); //Solution Folder
	//FILE* fp = fopen("../../TEST/input.txt", "r"); //outer Project Folder
	FILE* fp = fopen("../../../TEST/input.txt", "r"); //My Test Folder
	FILE* fp2 = fopen("../../../TEST/input2.txt", "w");
	//\를 /로 쉽게 바꾸는 방법 없나?

	//파이썬은 문제가 생긴다던데, C는 안그런가봄?

	//유효성 검사: 파일이 잘 열렸는지 확인	
	if (fp == NULL) {
		//오픈 실패하면 NULL을 반환해주는듯? 그런 보장이 있어야 코드를 이렇게 짜지
		printf("파일열기 실패!\n");
	}
	else {
		printf("파일열기 성공!\n");
	}

	int a;
	double b;
	char c;
	char d[10];
	fscanf(fp, "%d %lf %c %s", &a, &b, &c, d);
	printf("%d, %lf, %c, %s\n", a, b, c, d);

	fscanf(fp, "%d %lf %c %s", &a, &b, &c, d);
	printf("%d, %lf, %c, %s", a, b, c, d);

	fprintf(fp2, "%d %lf %c %s\n", a, b, c, d);
	fprintf(fp2, "파일내용 작성 성공!\n", a, b, c, d);

	fclose(fp); //내가 직접 닫냐 컴퓨터가 닫게하냐의 차이가 있다고 함.
	fclose(fp2);
	return 0;
}