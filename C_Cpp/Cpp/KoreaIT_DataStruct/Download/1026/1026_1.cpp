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
			if (index >= SU) {
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
			printf("어떤 정보를 수정하시겠습니까?\n1.이름 2.성적  ");
			int nn;
			scanf("%d", &nn);
			int n;
			while (1) {
				printf("정보를 수정하고싶은 학생의 번호입력: ");
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
					if (nn == 1) {
						// 이름수정
						printf("이름수정: ");
						scanf("%s", book[i].name);
					}
					else {
						// 성적수정
						printf("성적수정x2: ");
						scanf("%d%d", &book[i].score[0], &book[i].score[1]);
					}
					break;
				}
			}
			printf("\n");
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