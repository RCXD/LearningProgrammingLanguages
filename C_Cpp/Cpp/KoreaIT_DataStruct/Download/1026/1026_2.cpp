/*
1. ���ܾ� ������
2. apple _____ 100
3. ���� 1�� �Է� -> O,X
4. ���� ���
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
	printf("���ܾ� � �Է��Ͻðڽ��ϱ�? ");
	scanf("%d", &n);
	// 300�� -> 150���̻� ȹ���ϸ�,

	/*
	char arr[] = { 'a','p','p','l','e' }; // ���ڹ迭
	char str[] = "apple"; // ���ڿ�
	char str2[] = { 'a','p','p','l','e','\0' }; // ���ڿ�
	*/

	W *book=(W*)malloc(n*sizeof(W));
	for (int i = 0; i < n; i++) {
		printf("���ܾ��Է�: ");
		scanf("%s", book[i].word);
		// book[i].ans = "_____"; xxx
		for (int j = 0; j < strlen(book[i].word); j++) {
			book[i].ans[j] = '_';
		}
		book[i].ans[ strlen(book[i].word) ] = '\0'; // �١�
		book[i].score = 100;
		//printf("%s %s %d\n", book[i].word, book[i].ans, book[i].score);
	}

	/// 1. ���� ���� �Է½�, 10�� ����
	/// 2. 0���϶�, ���� �Ұ���
	/// 3. ���� ��� -> 80+20 => 100 (1�����)

	char c;
	int sum = 0;

	// �������� �ܾ� 1�� ����

	for (int i = 0; i < n; i++) {
		while (strcmp(book[i].ans, book[i].word) && book[i].score) {
			printf("%s : ", book[i].ans);
			scanf(" %c", &c);
			int check = 0; // check���� OFF
			for (int j = 0; j < strlen(book[i].word); j++) {
				if (c == book[i].word[j]) {
					book[i].ans[j] = c;
					check = 1; // check���� ON
				}
				/*
				else {
					printf("���ڸ�\n");
				}
				*/
			}
			if (check==0) {
				printf("%c�� �����ϴ�!\n", c);
				book[i].score -= 10;
			}
		}
		printf("������ %s�Դϴ�!\n", book[i].word);
		sum += book[i].score;
	}

	printf("������ %d���Դϴ�!\n", sum);
	// ��ǰ�� �帮�ڽ��ϴ�!!!

	return 0;
}