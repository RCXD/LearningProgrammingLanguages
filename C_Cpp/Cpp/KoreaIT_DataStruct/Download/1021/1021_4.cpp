#include<stdio.h>
#include<string.h>
int main() {

	char str[3][10]; // ���ڿ��迭 -> 2�����迭�� ����
	//str[0] = "apple";
	strcpy(str[0], "apple");
	for (int i = 0; i < 3; i++) {
		printf("%d�� ���ڿ��Է�: ", i + 1);
		scanf("%s", str[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%d. %s\n", i + 1, str[i]);
	}
	printf("\n");
	printf("������� ���ڿ��Է�: ");
	char word[10];
	scanf("%s", word);
	for (int i = 0; i < 3; i++) {
		if (strcmp(word,str[i])==0) {
			printf("%d�� �ܾ� %s\n", i+1, str[i] );
			break;
		}
		
	}
	if () {
		printf("%s�� ���� �ܾ��Դϴ�!\n", word);
	}

	return 0;
}