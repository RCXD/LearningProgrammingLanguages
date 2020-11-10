#include<stdio.h>
#include<string.h>
int main() {
	
	char str[10];
	char c;
	printf("영단어 1개 입력: ");
	scanf("%s", str); // 배열명==&배열[0]
	// str==&str[0]
	printf("영문자 1개 입력: ");
	scanf(" %c", &c);
	int cnt = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			cnt++;
		}
	}
	printf("%s에 %c는 %d개입니다.\n\n", str, c, cnt);
	
	return 0;
}