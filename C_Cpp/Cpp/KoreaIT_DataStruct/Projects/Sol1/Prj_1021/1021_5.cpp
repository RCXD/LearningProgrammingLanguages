#include "stdio.h"
#include "iostream"
#include "string.h" //string copy

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	//���ڿ�(����)
	//���ϴ� �л��� ��ȣ�� �ƴ�, �̸��� �Է��ߴٸ�...
	
	char str1[10];
	char str2[10];
	char str3[10];
	//���� ������� ���ڿ����� �߱�������. ��� �����Ϸ���

	char str[3][10]; //���ڿ� �迭�� '�ʿ�������' 2���� �迭�� ����.
	//str[0] = "apple";
	//str[1] = "kiwi";
	//str[2] = "banana";
	strcpy(str[0], "apple");
	strcpy(str[1], "kiwi");
	strcpy(str[2], "banana");

	for (int i = 0; i < 3; i++) {
		printf("%d�� ���ڿ� �Է�: ", i + 1);
		scanf("%s", str[i]);
	}
	printf("\n");
	printf("������� ���ڿ� �Է�: ");
	char word[10];
	scanf("%s", word);
	for (int i = 0; i < 3; i++) {
		//if (word==str[i]) //C������ ���ڿ������� �񱳿����ڷ� ���� �� ����.
		if (strcmp(word, str[i])==0) {
			printf("%d�� �ܾ� %s\n", i + 1, str[i]);
			break;
		}
		//else { //�� �ذ��϶��?
		if(/*����*/){
			printf("%s�� ���� �ܾ��Դϴ�!\n", word);
			//hint : ���ǹ����� ���ö�, �ȳ��ö��� ����ؼ� ������ ��
		}
		printf("%d�� �ܾ� %s\n", i + 1, str[i]);
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

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */