#include "stdio.h"
#include "string.h" //strlen()�Լ� Ȱ��
//Reference : https://modoocode.com/76 : string.h

/* Mission 
 * ���ܾ� 1�� �Է� : apple
 * ������ 1�� �Է� : p
 * apple�� p�� 2���Դϴ�.
 */

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	char str[10];
	char c;
	printf("���ܾ� 1�� �Է�: ");
	scanf("%s", str); //�迭�� == &�迭[0]
	//str==&str[0]
	printf("������ 1�� �Է�: ");
	scanf(" %c", &c); //���۹���? %c���� ��ĭ �� ������ �Ѵ�! 
	//������ �� ã�ƺ���. ���ڿ� ����� �ȹ���.
	//���Ϲ��� 1�� �Է¹��� ������ �տ� �� ĭ �� ��!
	//������ ���� �ȴ�.
	int cnt = 0;

	//for (int i = 0; i < 10; i++) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			cnt++;
		}
	}
	//�ڵ� ������ �ϼ��ϸ鼭 ������...?
	printf("%s�� %c�� %d���Դϴ�.\n\n", str, c, cnt);
	return;
}

/* Lecture
 * scanf(" %c", ...);���� %c���� �� ������, ������
 * 
 */
#endif


#ifdef MYSELF
void main() {
	printf("���ܾ� 1�� �Է�: ");
	int i = 0;
	char arr[10] = {};
	while (1) {
		scanf("%c", &arr[i]);
		//printf("%c", arr[i]);
		if (arr[i++] == '\0') //���������°� ������...
			break;
	}

	printf("\n");

	char in1 = '\0';
	printf("���ܾ� 1�� �Է�: ");
	scanf("%c", &in1);

	printf("\n");

	int cnt = 0;
	arr[10] = {};
	while (1) {
		printf("%c", arr[i]);
		if (arr[i] == in1) cnt++;
		if (arr[i++] == '\0')
			break;
	}
	printf("�� %c�� %d���Դϴ�.", in1, cnt);
	

	

	return;
}
#endif

/* �����ǥ �׸���
 *	Line	
 *			
 *				
 *				
 */