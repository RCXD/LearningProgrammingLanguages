#include "stdio.h"
#include "iostream"
#include "string.h" //strcpy

//#define MYSELF
#define TEACHER
#ifdef TEACHER

struct stu {
	char name[10]; //�ʵ� or �Ӽ�(attribute) or ������ �θ�.
	int age; //.�� ���/�޼ҵ� ���� ������
	double avg;
};
void main() {
	struct stu s1 = { "kim", 30, 11.2 };//stu��ü�� �ϳ��� �ڷ����̶�� �����ϸ� �ȴ�.
	//struct stu s2 = { "lee", 30, 22.2 }; 
	struct stu s2;
	//s2.name = "lee"; //Visual studio������ ������ �ʴ´�.
	strcpy(s2.name, "lee"); //s2.name = "lee"�� ����.
	s2.age = 30;
	s2.avg = 22.2;
	printf("%s�� ���̴� %d, ������ %.2lf�� \n", s1.name, s1.age, s1.avg);
	printf("%s�� ���̴� %d, ������ %.2lf�� \n", s2.name, s2.age, s2.avg);

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