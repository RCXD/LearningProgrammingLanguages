#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER


//����ü
//����ü�� ���ϱ�
/*
struct stu {
	char name[10];
	int num;
};
*/

//����ü: ��ü byte�� ��� �� ������ ���� ū ��ӿ��� �����ִ�, 
//			����ü�� �����ϴ� Ű����
typedef union{
	int i; //4����Ʈ... ���� ū ������ ����
	char c; //1����Ʈ
}u;
void main() {
	
	//u aaa = { 65, 'A' }; ����üó�� �ʱ�ȭ�� �� ����.
	u aaa;
	aaa.i = 65;
	aaa.c = 'A';
	printf("%d %c\n", aaa.i, aaa.c);

	aaa.i = 97; //�ҹ��� a�� �ǹ��ϴ� ��. c�� A���� a�� �ٲ����.
	printf("%d %c\n", aaa.i, aaa.c);

	//�� ����� �ٲ�µ� �ٸ� ����� �ٲ����.
	//����: ���� �ս��� �Ͼ�ٰ� �� �� �ִ�.
	//����: �޸𸮰����� ���� �Ƴ� �� �ִ�.

	//���蹮�� �ƴϰ��� �ȽἭ ��� ������ ���絵 �𸥴ٳ�. �˰��򿡵� ���� �ʿ��������?
	//����(%~)�� �ٲ㵵 �ڷ����� �ٲ�Ƿ� ���� ����ü�� �� �ʿ� ���ٰ�.
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