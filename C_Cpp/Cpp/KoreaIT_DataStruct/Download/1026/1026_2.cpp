/*
1. 영단어 모음집
2. apple _____ 100
3. 문자 1개 입력 -> O,X
4. 총점 출력
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct EWORD {
	char word[10]; // "apple"
	char ans[10]; // "_____"
	int score;
}W;
int main() {

	int n;
	printf("영단어 몇개 입력하시겠습니까? ");
	scanf("%d", &n);
	// 300점 -> 150점이상 획득하면,

	/*
	char arr[] = { 'a','p','p','l','e' }; // 문자배열
	char str[] = "apple"; // 문자열
	char str2[] = { 'a','p','p','l','e','\0' }; // 문자열
	*/

	W *book=(W*)malloc(n*sizeof(W));
	for (int i = 0; i < n; i++) {
		printf("영단어입력: ");
		scanf("%s", book[i].word);
		// book[i].ans = "_____"; xxx
		for (int j = 0; j < strlen(book[i].word); j++) {
			book[i].ans[j] = '_';
		}
		book[i].ans[ strlen(book[i].word) ] = '\0'; // ☆★
		book[i].score = 100;
		//printf("%s %s %d\n", book[i].word, book[i].ans, book[i].score);
	}

	/// 1. 없는 문자 입력시, 10점 감점
	/// 2. 0점일때, 진행 불가능
	/// 3. 총점 출력 -> 80+20 => 100 (1번출력)

	char c;
	int sum = 0;

	// 랜덤으로 단어 1개 선택

	for (int i = 0; i < n; i++) {
		while (strcmp(book[i].ans, book[i].word) && book[i].score) {
			printf("%s : ", book[i].ans);
			scanf(" %c", &c);
			int check = 0; // check변수 OFF
			for (int j = 0; j < strlen(book[i].word); j++) {
				if (c == book[i].word[j]) {
					book[i].ans[j] = c;
					check = 1; // check변수 ON
				}
				/*
				else {
					printf("이자리\n");
				}
				*/
			}
			if (check==0) {
				printf("%c는 없습니다!\n", c);
				book[i].score -= 10;
			}
		}
		printf("정답은 %s입니다!\n", book[i].word);
		sum += book[i].score;
	}

	printf("총점은 %d점입니다!\n", sum);
	// 상품을 드리겠습니다!!!

	return 0;
}