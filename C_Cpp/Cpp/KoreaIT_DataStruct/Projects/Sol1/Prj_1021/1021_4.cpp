#include "stdio.h"
#include "iostream"
#include<stdlib.h>

//#define MYSELF
#define TEACHER
#ifdef TEACHER
	//문제
	//정수 2개 입력 : 7 3
	//[1 2 3 4 5 6 7]
	//[1   4   5]
	//결과: 3 6 2 7 5 1 4

	//5 2
	//[1 2 3 4 5] 배열 생성
	//2 4 1 5 3: 두번째 입력한 값만큼 '점프'해서 추출하고 삭제하는 코드 : 숙제
	//삭제가 안되니 다른 문자나 숫자(0같은거)로 대체하는것도 하나의 해법.
	//무한반복문을 쓰는게 좋다고 함.


int check(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] != 0) {
			return 1; // 즉시종료
		}
	}
	return 0;
}
int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	int* data = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++) {
		data[i] = i + 1;
	}

	int cnt = 0;
	int i = 0;
	while (check(data, a)) {
		if (data[i] == 0) {
			i++;
			if (i == a) { // 배열이용시, 인덱스범위확인!!!
				i = 0;
			}
			continue;
		}
		cnt++;
		if (cnt == b) {
			printf("%d ", data[i]);
			data[i] = 0;
			cnt = 0;
		}
		i++;
		if (i == a) {
			i = 0;
		}
	}
	// 정수 2개 입력 : 7 3
	// [1 2 3 4 5 6 7]
	//  => 3 6 2 7 5 1 4

	// 5 2
	// [1 2 3 4 5]
	//  => 2 4 1 5 3

	배열 VS 리스트

		인덱싱방식->검색(), 탐색()에 유리
		제한, 한정적->삽입(), 삭제()에 불리

		검색(), 탐색()에 불리
		삽입(), 삭제()에 유리
		제한적이지않음 == 동적임->공간효율이 좋음

		노드(NODE)
		데이터부 + 주소부(== 링크부)
		주소부 = > 다음노드를 가리키는 포인터가 존재함

		return 0;
}


#endif

//원래 이 문제는 배열의 한계를 느끼고 리스트로 해결해야 하는 문제라고 함.
#ifdef MYSELF
void main() {
	//max, sep <- input
	//max = 7, sep = 3이면
	//1 2 3 4 5 6 7
	//출력: arr[sep(3)], arr[sep+sep(6)], arr[sep+sep+sep(2)], arr[sep+sep+sep+sep+jump+jump+(7)]
	//3 -> cnt 0
	//6 -> cnt 1
	//2 = 9%7 -> cnt 2
	//7 -> cnt 3

	int max, sep;
	printf("수열의 길이와 간격을 입력하세요: ");
	scanf("%d %d", &max, &sep);
	int* arr = (int*)malloc(sizeof(int) * max);
	
	for (int i = 1; i <= max; i++) {
		arr[i - 1] = i;
		printf("%d ", arr[i - 1]);
	}
	printf("\n");
	
	
	... 마저 해보자.

	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */