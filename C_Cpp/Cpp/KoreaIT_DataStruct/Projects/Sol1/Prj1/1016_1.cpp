#include "stdio.h"
#include "iostream"

#define TEACHER
#ifdef TEACHER
void main() {
	int a, b;
	printf("1. 2개의 정수를 입력: ");
	scanf("%d %d", &a, &b);
	int res = 1;
	for (int i = 1; i <= b; i++) {
		res *= a; //1부터 b까지, 즉 b개수만큼 곱해주면 그게 제곱임.
	} //Lecture : 반복횟수가 애매하면 while문 사용
	printf("%d의 %d승 = %d\n\n", a, b, res);

	double arr[3];
	int cnt=0; //음수의 갯수를 세어 줄 변수
	printf("2, 3개의 실수를 입력하세요.\n"); //뭐시기 어디 빠졌는데, 일단 스킵. 원본코드 참조
	for (int i = 0; i < 3; i++) {
		printf("%d번:", i + 1);
		scanf("%lf", &arr[i]);
		if (arr[i] < 0.0) {
			cnt++;
		}
	}
	printf("이 중 음수는 %d개\n", cnt);

	return;
}

#endif


#ifdef MYSELF
int in1, in2 = 0;
float inf1, inf2, inf3 = 0;

void main() {
	//프로젝트 -> 속성 -> C -> 전처리기
	//_CRT_SECURE_NO_WARNINGS
	//참고문헌 : https://stackoverflow.com/questions/16883037/remove-secure-warnings-crt-secure-no-warnings-from-projects-by-default-in-vis

	printf("1. 2개의 정수를 입력: ");
	scanf("%d%d", &in1, &in2); //scanf_s는 사용하지 말자. VCpp만 되는것이니 잘못된거라고 함.
	printf("\n%d의 %d승 = %d\n\n", in1, in2, (int)powf(in1, in2));

	printf("2, 3개의 실수를 입력하세요.");
	scanf("%f%f%f", &inf1, &inf2, &inf3);
	printf("\n1번 : %1.1f", inf1);
	printf("\n2번 : %1.1f", inf2);
	//...


	return;
}
#endif

/* 디버깅표 그리기
 *	Line	a	b	res	i
 *			10	2	1	0
 *					10	1
 *					100	2
 */