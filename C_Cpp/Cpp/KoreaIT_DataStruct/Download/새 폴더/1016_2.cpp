#include<stdio.h>
#include<string.h>
int main() {
	
	char str[10];
	char c;
	printf("���ܾ� 1�� �Է�: ");
	scanf("%s", str); // �迭��==&�迭[0]
	// str==&str[0]
	printf("������ 1�� �Է�: ");
	scanf(" %c", &c);
	int cnt = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			cnt++;
		}
	}
	printf("%s�� %c�� %d���Դϴ�.\n\n", str, c, cnt);
	
	return 0;
}