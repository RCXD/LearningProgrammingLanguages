/*
1. ���ܾ� ������ (����ü�� ����)
2. apple _____ 100//������ �������� �ܾ���߱� ���� ����
  //������ �⺻ 100��, �Ѱ� Ʋ�� ������ 10���� ����
3. ���� 1�� �Է� -> ���� O, X �Ǵ� / �������� ������ -10��
4. ���� ���
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
		printf("���ܾ� ���߱� ���α׷�\n");

		//Init Setting
		printf("���ܾ �� �� �Է��Ͻðڽ��ϱ�?\n");
		int n;
		scanf(" %d", &n);
		Word* book = (Word*)malloc(sizeof(Word) * n);

		/*
		char arr[] = { 'a', 'p', 'p', 'l', 'e' };	//������ ������ �迭�̴�. �ι��ڴ� ����.
		char str[] = "apple";						//���ڿ�. �ι��� 1����Ʈ�� �� ���� �߰��Ǿ� �ִ�.
		char str2[] = { 'a', 'p', 'p', 'l', 'e', '\0' }; //���ڿ��� ����� �ϴ� ���� �迭
		*/

		for (int i = 0; i < n; i++) {
			printf("���ܾ� �Է�: ");
			scanf("%s", book[i].word);
			//book[i].ans = "_____"; VSC������ �Ұ���.
			for (int j = 0; j < strlen(book[i].word); j++) { //for���� �̿��ؼ� �Է��ؾ� �Ѵ�.
				book[i].ans[j] = '_';
			}
			book[i].ans[strlen(book[i].word)] = '\0'; //�ι��ڰ� �ݵ�� �߰��Ǿ�� �Ѵ�. �߿�.
			book[i].score = 100;
			//printf("%s %s %d\n", book[i].word, book[i].ans, book[i].score);	//Ȯ�ο� �ڵ�
		}

		///Mission///
		/// 1. �߸� �ԷµǴ� ��� ���� ���
		/// 2. 0���� �� ���� �Ұ��� ��Ű��

		//�ܾ� ������ �������� ������ ���� �ִ�. �غ� ��. ???

		//�ܾ���� ����
		char c;
		int total=0;
		for (int i = 0; i < n; i++) {
			book[i].score = 100;
			while (strcmp(book[i].ans, book[i].word)) {//(book[i].ans == book[i].word) { ��Ʈ���� �̷��� ���ϸ� �ȵ�
				if (book[i].score == 0) {
					printf("������ ���Ͽ����ϴ�. "); //������ ������ ������ �����.
					break; //���� �Ұ���
				}
				printf("���� ���� : %d��\t", book[i].score); printf("%s: ", book[i].ans);
				scanf(" %c", &c);

				int check = 0; //check off
				for (int j = 0; j < strlen(book[i].word); j++) { //�Է´ܾ ����ܾ�� ���ϱ����� ��ĵ
					if (c == book[i].word[j]) { //�Է�(c)�ܾ �ϳ��� ���߸�(���ԵǸ�)
						book[i].ans[j] = c; //���� ���� ��ü
						check = 1; //check on
					}
				}
				if (check==0) {
					printf("%c�� �����ϴ�!\n", c);
					book[i].score -= 10;
				}
			}
			printf("������ %s���̴�!\n", book[i].word);
			total += book[i].score;
		}
		printf("===========================\n");
		printf("������ �������ϴ�.\n");
		printf("����: %d\n", total);
		printf("===========================\n");
		printf("�ٽ� �Ͻðڽ��ϱ�?\n1. �� / 2. �ƴϿ�");
		c = '\0';
		scanf(" %c", &c);
		if (c == 1) continue;
		else if (c == 2) {
			printf("������ ����Ǿ����ϴ�.");
			return;
		}
		/*
		* �ɼ����ε� �����غ���. �ð�����.
		//Options
		printf("1. �ܾ� ����");
		printf("2. ���� Ȯ���ϱ�");
		printf("3. ������");
		

		char choice;
		scanf(" %c", &choice);

			if (choice==1)

		*/
	}

	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */