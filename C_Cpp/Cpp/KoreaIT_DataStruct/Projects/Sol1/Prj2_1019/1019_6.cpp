#include "stdio.h"
#include "iostream"
#include "string.h" //strcpy

//#define MYSELF
#define TEACHER
#ifdef TEACHER

struct stu {
	char name[10]; //필드 or 속성(attribute) or 멤버라고 부름.
	int age; //.은 멤버/메소드 접근 연산자
	double avg;
};
void main() {
	struct stu s1 = { "kim", 30, 11.2 };//stu자체가 하나의 자료형이라고 생각하면 된다.
	//struct stu s2 = { "lee", 30, 22.2 }; 
	struct stu s2;
	//s2.name = "lee"; //Visual studio에서만 허용되지 않는다.
	strcpy(s2.name, "lee"); //s2.name = "lee"와 같다.
	s2.age = 30;
	s2.avg = 22.2;
	printf("%s의 나이는 %d, 점수는 %.2lf점 \n", s1.name, s1.age, s1.avg);
	printf("%s의 나이는 %d, 점수는 %.2lf점 \n", s2.name, s2.age, s2.avg);

	return;
}

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */