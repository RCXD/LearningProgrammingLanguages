#include "stdio.h"
#include "string.h" //strlen()함수 활용
//Reference : https://modoocode.com/76 : string.h

/* Mission 
 * 영단어 1개 입력 : apple
 * 영문자 1개 입력 : p
 * apple에 p는 2개입니다.
 */

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	char str[10];
	char c;
	printf("영단어 1개 입력: ");
	scanf("%s", str); //배열명 == &배열[0]
	//str==&str[0]
	printf("영문자 1개 입력: ");
	scanf(" %c", &c); //버퍼문제? %c앞을 한칸 꼭 띄워줘야 한다! 
	//왜인지 좀 찾아보자. 문자열 제대로 안배운듯.
	//단일문자 1개 입력받을 때에는 앞에 한 칸 뗄 것!
	//무조건 떼도 된다.
	int cnt = 0;

	//for (int i = 0; i < 10; i++) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			cnt++;
		}
	}
	//코드 마무리 완성하면서 복습좀...?
	printf("%s에 %c는 %d개입니다.\n\n", str, c, cnt);
	return;
}

/* Lecture
 * scanf(" %c", ...);에서 %c앞의 빈 공백은, 가급적
 * 
 */
#endif


#ifdef MYSELF
void main() {
	printf("영단어 1개 입력: ");
	int i = 0;
	char arr[10] = {};
	while (1) {
		scanf("%c", &arr[i]);
		//printf("%c", arr[i]);
		if (arr[i++] == '\0') //빠져나오는거 실패함...
			break;
	}

	printf("\n");

	char in1 = '\0';
	printf("영단어 1개 입력: ");
	scanf("%c", &in1);

	printf("\n");

	int cnt = 0;
	arr[10] = {};
	while (1) {
		printf("%c", arr[i]);
		if (arr[i] == in1) cnt++;
		if (arr[i++] == '\0')
			break;
	}
	printf("에 %c는 %d개입니다.", in1, cnt);
	

	

	return;
}
#endif

/* 디버깅표 그리기
 *	Line	
 *			
 *				
 *				
 */