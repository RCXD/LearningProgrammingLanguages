#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#define StuNum 5 //기호상수(사용자 정의상수)를 잘 사용할 것! 오류, 오타 가능성 최소화해줌.

#define MYSELF
//#define TEACHER
#ifdef TEACHER
// 구조체 << 하나의 자료형!
// 1. 함수의 인자
// 2. 배열 -> 구조체 배열
// 3. 포인터
// 4. 동적메모리할당

// typedef -> 가독성증가
#include<stdio.h>
#define SU 5 // 기호상수==사용자정의상수
typedef struct stu {
	char name[10];
	int num; // 이 값이 유일한지 판단하기위해 지정!
	int score[2];
	double avg;
	char grade;
}S;
int main() {

	// 1. 학생추가
	// 2. 학생의 학점을 출력
	// 3. 학생의 정보 수정-> 성적,이름
	// 4. 학생삭제
	// 5. 1등한 학생 이름을 출력
	// 6. 전체 학생부 상태 출력
	// 7. 종료

	//printf("몇명까지 사용하시겠습니까?  "); <<동적메모리
	S book[SU];
	int index = 0;
	int num = 1001;

	int act;
	while (1) {
		printf("=====학생부 프로그램=====\n");
		printf("1.학생추가\n");
		printf("2.학생정보출력\n");
		printf("3.학생정보수정\n");
		printf("4.학생삭제\n");
		printf("5.1등 확인\n");
		printf("6.학생부 출력\n");
		printf("7.종료\n");
		printf(" : ");
		scanf("%d", &act);
		if (act == 1) {
			if (index > ? ? ? ? ? ? ) {
				printf("학생부가 가득찼습니다!\n\n");
				continue;
			}

			printf("학생이름입력: ");
			scanf("%s", book[index].name);
			book[index].num = num++;
			for (int i = 0; i < 2; i++) {
				printf("시험%d성적입력: ", i + 1);
				scanf("%d", &book[index].score[i]);
			}
			int sum = 0;
			for (int i = 0; i < 2; i++) {
				sum += book[index].score[i];
			}
			book[index].avg = sum / 2.0; // *1.0
			/*
			book[index].avg = 0.0;
			for (int i = 0; i < 2; i++) {
			   book[index].avg += book[index].score[i];
			}
			book[index].avg /= 2.0;
			*/
			if (book[index].avg >= 50.0) {
				book[index].grade = 'A';
			}
			else if (book[index].avg >= 10.0) {
				book[index].grade = 'B';
			}
			else {
				book[index].grade = 'C';
			}
			printf("%s 입력완료!\n\n", book[index++].name);
		}
		else if (act == 2) {
			int n;
			while (1) {
				printf("정보를 보고싶은 학생의 번호입력: ");
				scanf("%d", &n);
				if (n <= 1000 || n >= 2000) {
					printf("올바른 범위가 아닙니다!\n");
					//continue;
				}
				else {
					break;
				}
			}
			for (int i = 0; i < index; i++) {
				// 없는번호를 입력했을때,
				// 해당학생은 존재하지않습니다! << 출력해주세요!~~
				if (n == book[i].num) {
					printf(" %d번 %s %c %.2lf점\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
					break;
				}
			}
			printf("\n");
		}
		else if (act == 3) {
			// 2번액션과 유사하게 진행해주세요!
			// 정보를 수정하고싶은 학생의 번호입력:
			// 1. 이름 / 2. 성적
		}
		else if (act == 4) {
			if (index == 0) {
				printf("삭제 불가능!\n\n");
				continue;
			}
			printf("%s 학생정보삭제됨!\n\n", book[--index].name); // 디버깅표로 확인하기!!!★☆★☆
		}
		else if (act == 5) {
			if (index == 0) {
				printf("학생부에 학생이 존재하지않습니다!\n\n");
				continue;
			}
			double max = book[0].avg;
			int maxIndex = 0;
			for (int i = 1; i < index; i++) {
				if (max < book[i].avg) {
					max = book[i].avg;
					maxIndex = i;
				}
			}
			printf("1등은 %s입니다!\n\n", book[maxIndex].name);
		}
		else if (act == 6) {
			printf("===학생부===\n");
			for (int i = 0; i < index; i++) {
				printf(" %d.%-5s %c %5.2lf점\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
			}
			printf("\n");
		}
		else if (act == 7) {
			printf("\n프로그램 종료\n\n");
			break;
		}
		else {
			printf("유효하지않은 번호입니다!\n");
			printf("다시입력하세요!\n\n");
		}
	}

	return 0;
}

#endif


#ifdef MYSELF

typedef struct point {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;

void main() {
	//1. 학생 추가
	//2. 학생의 정보 출력
	//3. 학생의 정보 수정 -> 성적, 이름
	//4. 학생 삭제
	//5. 1등한 학생 이름을 출력
	//6. 전체 학생부 상태 출력
	//7. 종료

	printf("===========학생부 프로그램===========\n\n");

	int n;
	printf("학생부에 몇명까지 입력하겠습니까?");
	scanf("%d", &n);
	S* book = (S*)malloc(n * sizeof(S));
	//S book[StuNum]; //전처리기 활용하여 오류 줄이기
	int index = 0; //stack!
	int num = 1001; //부여될 학생번호의 초기값

	while (1)
	{
		int input;
		printf("1. 학생 추가\n"); //빈공간이 있으면 집어넣기로. (push)
		printf("2. 학생의 정보 출력\n");
		printf("3. 학생의 정보 수정\n");
		printf("4. 학생 삭제\n"); //일단, 묻지않고 가장 마지막 값을 삭제하기로. (pop)
		printf("5. 1등 확인\n");
		printf("6. 전체 학생부 출력\n");
		printf("7. 전체 학생부 출력\n");

		scanf(" %d", &input);


		if (input == 1) {
			printf("학생 이름을 입력하세요.\n");
			scanf("%s", book[index].name);
			book[index].num = num++;
			printf("중간고사 점수를 입력하세요.\n");
			scanf(" %d", &book[index].score[0]);
			printf("기말고사 점수를 입력하세요.\n");
			scanf(" %d", &book[index].score[1]);
			book[index].avg = (book[index].score[0] + book[index].score[1]) / 2.0;
			
			//학점 판단
			if (book[index].avg >= 50.0) {
				book[index].grade = 'A';
			}
			else if (book[index].avg >= 30.0) {
				book[index].grade = 'B';
			}
			else {
				book[index].grade = 'C';
			}
			printf("%s 입력 완료!\n", book[index].name);
			index++; //매우 중요한 부분
		}

		else if (input == 2) {
			//나중에 검색 알고리즘을 배우면 더 멋드러지게 하고
			//지금은 간단하게 구현

			int n;
			while (1) { //올바른 정보를 언제까지 입력할지 모르니 반복문 만듦
				printf("정보를 보고싶은 학생의 번호 입력: \n");
				scanf("%d", &n);
				if (n <= 1000 || n >= 2000) {
					printf("올바른 범위가 아닙니다!\n");
				}
				else {
					break;
				}
				for (int i = 0; i < index; i++) {
					//없는 번호를 입력했을 때
					//해당 학생은 존재하지 않습니다! << 문구 출력하기. (숙제)
					if (n == book[i].num) {
						printf("%d번 %-5s %c %5.2lf점\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
						break;
					}
				}
				for (int i = 0; i <= index; i++) {

				}
			}
		}
		else if (input == 3) { //정보 수정
			//숙제
			//2번과 유사하게 진행
			//정보를 수정하고싶은 학생의 번호 입력:
			//1. 이름 / 2. 성적 (선택해서 수정하기)
		}
		else if (input == 4) { //학생 삭제
			//맨 끝을 삭제하고, 누가 삭제되었는지 알려주기
			//index 하나 줄이기
			//index 관리 잘 해서 잘 지우기.
			//if (index == *0*답 or 1 or -1) { //과제!
			//	printf("삭제 불가능!\n");
			//	continue; //유지보수할 때에 유용하다
			//}
			printf("%s 학생정보 삭제됨\n", book[index-1].name); //index-1이 아니면 삭제된 쓰레기값이 읽어진다고?
			//디버깅표 그리기!!!!
		}
		//TEACHER
		else if (input == 5) {
			//학생이 0명일 때
			if (index == 0) {
				printf("학생부에 학생이 존재하지 않습니다!\n\n");
				continue;
			}

			double max;
			int maxIndex = 0;
			for (int i = 1; i < index; i++) {
				if (max < book[i].avg) {
					max = book[i].avg;
					maxIndex = 1;
				}
			}
			printf("1등은 %s입니다!\n", book[maxIndex].name);
		}
		else if (input == 6) {
			//...
		}
		else if (input == 7) break;
		else {
			printf("유효하지 않은 정보입니다.\n"); //유효성 검사
			continue;
		}
	}
	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */