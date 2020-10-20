#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	int n = 0;
	printf("정수 1개 입력: \n");
	scanf(" %d", &n);
	printf("1에서 입력한 정수만큼 데이터 입력: \n");
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf(" %d", &arr[i]);
	}

	//int sw = 0;
	for (int i = 0; i < n - 1; i++) { //순환의 첫끝과 뒤끝을 쓸 때 주의해야 한다.
		if (arr[i] > arr[i + 1]) {
			printf("ERROR!\n");
			//sw = 1;
			return;
		}
	}
	for (int i = 0; i < n; i++) { //for문의 중첩은 처리속도를 고민해야하지만, 병렬은 괜찮다고 한다.
		if (arr[i] < 0) {
			printf("Error!\n");
			return;
		}
	}

	//if (sw) {
		//printf("Error!\n"); //스위치 변수를 이용하는 경우.

	int res = 0;
	int min = arr[1] - arr[0];
	for (int i = 1; i < n - 1; i++) { //처음꺼는 초기화에서 처리했으니 불필요하므로 제외
		if (min > arr[i + 1] - arr[i]) {
			min = arr[i + 1] - arr[i];
		}
	}
	printf("[%d] \n", res);

	return;
}

#endif


#ifdef MYSELF
void main() {
	while (1) {
		int num = 0;
		printf("정수 1개 입력: \n");
		scanf(" %d", &num);
		printf("1에서 입력한 정수만큼 데이터 입력: \n");
		int* arr = (int*)malloc(num * sizeof(int));
		int comp = 0;
		for (int i = 0; i < num; i++) {
			scanf(" %d", &arr[i]);
			if (comp > arr[i]) { //에러 조건: 이전값보다 작은 값이 들어올 때
				printf("[ERROR! not ascending numbers]\n\n");
				continue;
			}
			else if (arr[i] < 0) {
				printf("[ERROR! Negative Integer]\n\n");
				continue;
			}
			else {
				comp = arr[i];	//안걸리면 저장
			}
		}
		if (num < 2) {
			printf("num이 너무 작습니다.\n\n");
			continue;
		}
		comp = arr[1] - arr[0]; //첫 쌍으로 초기화
		int diff = 0;
		for (int i = 1; i < num - 1; i++) { //문제 해결
			diff = arr[i + 1] - arr[i];
			if (comp > diff) {
				comp = diff;
			}
		}
		printf("[%d]\n\n", comp);
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