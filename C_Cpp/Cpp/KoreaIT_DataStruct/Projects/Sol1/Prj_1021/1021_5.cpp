#include "stdio.h"
#include "iostream"
#include "string.h" //string copy

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	//문자열(예습)
	//원하는 학생의 번호가 아닌, 이름을 입력했다면...
	
	char str1[10];
	char str2[10];
	char str3[10];
	//현재 만들어진 문자열들은 중구난방임. 묶어서 관리하려면

	char str[3][10]; //문자열 배열은 '필연적으로' 2차원 배열의 형태.
	//str[0] = "apple";
	//str[1] = "kiwi";
	//str[2] = "banana";
	strcpy(str[0], "apple");
	strcpy(str[1], "kiwi");
	strcpy(str[2], "banana");

	for (int i = 0; i < 3; i++) {
		printf("%d번 문자열 입력: ", i + 1);
		scanf("%s", str[i]);
	}
	printf("\n");
	printf("보고싶은 문자열 입력: ");
	char word[10];
	scanf("%s", word);
	for (int i = 0; i < 3; i++) {
		//if (word==str[i]) //C에서는 문자열끼리는 비교연산자로 비교할 수 없다.
		if (strcmp(word, str[i])==0) {
			printf("%d번 단어 %s\n", i + 1, str[i]);
			break;
		}
		//else { //뭘 해결하라고?
		if(/*조건*/){
			printf("%s는 없는 단어입니다!\n", word);
			//hint : 조건문으로 나올때, 안나올때를 고려해서 생각할 것
		}
		printf("%d번 단어 %s\n", i + 1, str[i]);
		break;
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