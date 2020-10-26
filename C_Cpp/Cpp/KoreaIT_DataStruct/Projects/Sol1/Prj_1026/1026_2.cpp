/*
1. 영단어 모음집 (구조체로 선언)
2. apple _____ 100//가려진 공간으로 단어맞추기 게임 구현
  //점수는 기본 100점, 한개 틀릴 때마다 10점씩 감점
3. 문자 1개 입력 -> 존재 O, X 판단 / 존재하지 않으면 -10점
4. 총점 출력
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"
#define MYSELF
//#define TEACHER
#ifdef TEACHER
void main() {


	return;
}

#endif


#ifdef MYSELF

typedef struct {
	char word[10]; //'apple'
	char ans[10];  //'_____'
	int score;
}Word;

void main() {
	while (1)
	{
		//Greeting
		printf("영단어 맞추기 프로그램\n");

		//Init Setting
		printf("영단어를 몇 개 입력하시겠습니까?\n");
		int n;
		scanf(" %d", &n);
		Word* book = (Word*)malloc(sizeof(Word) * n);

		/*
		char arr[] = { 'a', 'p', 'p', 'l', 'e' };	//순수한 문자의 배열이다. 널문자는 없다.
		char str[] = "apple";						//문자열. 널문자 1바이트가 맨 끝에 추가되어 있다.
		char str2[] = { 'a', 'p', 'p', 'l', 'e', '\0' }; //문자열의 기능을 하는 문자 배열
		*/

		for (int i = 0; i < n; i++) {
			printf("영단어 입력: ");
			scanf("%s", book[i].word);
			//book[i].ans = "_____"; VSC에서는 불가능.
			for (int j = 0; j < strlen(book[i].word); j++) { //for문을 이용해서 입력해야 한다.
				book[i].ans[j] = '_';
			}
			book[i].ans[strlen(book[i].word)] = '\0'; //널문자가 반드시 추가되어야 한다. 중요.
			book[i].score = 100;
			//printf("%s %s %d\n", book[i].word, book[i].ans, book[i].score);	//확인용 코드
		}

		///Mission///
		/// 1. 잘못 입력되는 경우 점수 깍기
		/// 2. 0점일 때 진행 불가능 시키기

		//단어 갯수를 랜덤으로 구현할 수도 있다. 해볼 것. ???

		//단어게임 구현
		char c;
		int total=0;
		for (int i = 0; i < n; i++) {
			book[i].score = 100;
			while (strcmp(book[i].ans, book[i].word)) {//(book[i].ans == book[i].word) { 스트링은 이렇게 비교하면 안됨
				if (book[i].score == 0) {
					printf("맞추지 못하였습니다. "); //나가면 정답이 뭔지랑 연결됨.
					break; //진행 불가능
				}
				printf("현재 점수 : %d점\t", book[i].score); printf("%s: ", book[i].ans);
				scanf(" %c", &c);

				int check = 0; //check off
				for (int j = 0; j < strlen(book[i].word); j++) { //입력단어를 정답단어와 비교하기위해 스캔
					if (c == book[i].word[j]) { //입력(c)단어를 하나라도 맞추면(포함되면)
						book[i].ans[j] = c; //맞춘 문자 대체
						check = 1; //check on
					}
				}
				if (check==0) {
					printf("%c는 없습니다!\n", c);
					book[i].score -= 10;
				}
			}
			printf("정답은 %s입이다!\n", book[i].word);
			total += book[i].score;
		}
		printf("===========================\n");
		printf("게임이 끝났습니다.\n");
		printf("총점: %d\n", total);
		printf("===========================\n");
		printf("다시 하시겠습니까?\n1. 예 / 2. 아니오");
		c = '\0';
		scanf(" %c", &c);
		if (c == 1) continue;
		else if (c == 2) {
			printf("게임이 종료되었습니다.");
			return;
		}
		/*
		* 옵션으로도 구현해보자. 시간나면.
		//Options
		printf("1. 단어 제시");
		printf("2. 점수 확인하기");
		printf("3. 나가기");
		

		char choice;
		scanf(" %c", &choice);

			if (choice==1)

		*/
	}

	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */