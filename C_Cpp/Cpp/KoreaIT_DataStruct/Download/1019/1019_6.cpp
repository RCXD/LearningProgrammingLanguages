// 구조체
// 향상된 배열  /  자료형을 만들수있게 해줌
// 배열: 1.서로 관련된 데이터 2.자료형이 동일
#include<stdio.h>
#include<string.h>
struct stu {
	char name[10]; // 필드,속성,멤버
	int age; // . 멤버 접근 연산자
	double avg;
};
int main() {

	struct stu s1 = { "kim",20,11.1 };
	struct stu s2;
	strcpy(s2.name, "lee"); // s2.name = "lee";
	s2.age = 30;
	s2.avg = 22.2;
	printf("%s의 나이는 %d,점수는 %.2lf점\n", s1.name, s1.age, s1.avg);
	printf("%s의 나이는 %d,점수는 %.2lf점\n", s2.name, s2.age, s2.avg);

	return 0;
}