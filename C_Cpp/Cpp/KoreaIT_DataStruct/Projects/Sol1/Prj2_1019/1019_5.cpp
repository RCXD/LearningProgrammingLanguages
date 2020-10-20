#include "stdio.h"
#include "iostream"
#include "stdlib.h" //malloc

//#define MYSELF
#define TEACHER
#ifdef TEACHER
#define SET3
void main() {
	//학생 수 : 3
	//중간고사[]
	//기말고사[]
	//평균[] -> .2 => 1등 점수 구경

#ifdef SET1
	int n;
	printf("학생수: ");
	scanf("%d", &n);
	int* score1 = (int*)malloc(n * sizeof(int));
	int* score2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("%d번 학생의 점수: ", i+1);
		scanf("%d%d", &score1[i], &score2[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d번 학생의 점수: %.2lf\n", i + 1, (score1[i] + score2[i]) / 2.0f); //연산자 우선순위는 실수 빈번하게 하는 파트
	} //typeError 주의. 값에 영향을 주지 않는 *1.0을 추가하거나 정수를 소수로 나타내는것이 좋다고 함.
#endif
	

#ifdef SET2
	//2차원배열 동적할당하기도 가능하다!
	int a, b;
	int num = 10;
	scanf("%d%d", &a, &b);
	int** data = (int**)malloc(a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		//a = 3일 경우: data[0], data[1], data[2]에 배열을 할당할 수 있게 된다.
		data[i] = (int*)malloc(b * sizeof(int));
		for (int j = 0; i < b; j++) {
			data[i][j] = num++; //10, 11, 12, ...로 채우기. i와 j를 바꾸면 Transpose할 수 있겠지.
		}
	}

	//Show
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
#endif

#ifdef SET3
	int n;
	printf("학생수: ");
	scanf("%d", &n);
	int** data = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		data[i] = (int*)malloc(2 * sizeof(int));
		printf("%d번 학생의 점수: ", i + 1);
		for (int j = 0; j < 2; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d번 학생의 평균점수=", i + 1);
		double avg = 0.0;
		for (int j = 0; j < 2; j++) {
			avg += data[i][j];
		}
		printf("%.2lf점\n", avg/2.0);
	}
#endif
	return;

	/* Lecture 
	정방형 배열. legged 배열? 레기드?
	legid?
	rigid?
	정방형, 비정방형 배열을 만들 수 있다. 
	동적할당을 이용하면 비정방형 배열을 만들수는 있다고 함. 권장은 아니라고 함.
	*/
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