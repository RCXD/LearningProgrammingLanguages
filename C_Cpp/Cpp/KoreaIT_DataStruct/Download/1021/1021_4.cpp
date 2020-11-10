#include<stdio.h>
#include<string.h>
int main() {

	char str[3][10]; // 문자열배열 -> 2차원배열의 형태
	//str[0] = "apple";
	strcpy(str[0], "apple");
	for (int i = 0; i < 3; i++) {
		printf("%d번 문자열입력: ", i + 1);
		scanf("%s", str[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%d. %s\n", i + 1, str[i]);
	}
	printf("\n");
	printf("보고싶은 문자열입력: ");
	char word[10];
	scanf("%s", word);
	for (int i = 0; i < 3; i++) {
		if (strcmp(word,str[i])==0) {
			printf("%d번 단어 %s\n", i+1, str[i] );
			break;
		}
		
	}
	if () {
		printf("%s는 없는 단어입니다!\n", word);
	}

	return 0;
}