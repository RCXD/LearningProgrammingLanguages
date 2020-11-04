//[정렬] 버블정렬, 삽입정렬, 선택정렬, 퀵정렬(가장 빠르다나)-> 기본!... 합병정렬, 도수정렬, 셀정렬
//배열의 데이터를 오름차순으로 정리(재배치)하는 알고리즘을 정렬이라고 함.
//언제, 어디서 쓰는지를 알아야 일을 할 수 있다. 배우는게 다가 아님! 요즘 면접 트렌드.

//정렬... 언제 쓰는가? 
//검색()(==탐색())을 효율적으로 하기 위해서 정렬을 한다.

//버블정렬: 인근 데이터끼리 비교해서 큰것을 뒤로 보내는 정렬임. 이걸 적절히 반복






#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
#include <stdio.h>
void bubble_sort(int *a, int len) {
	for (int x = 0; x < len; x++) {
		for (int i = 0; i < len - 1; i++) { //주의: 데이터 숫자보다 한개 적게 비교해야 쓰레기값을 취하지 않음.
			if (a[i] > a[i + 1]) {
				//교환
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		} 
	}
}

int main() {
	int data[] = { 5, 4, 7, 1, 2 };

	printf("정렬 전: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	bubble_sort(data, 5); //배열 자체를 보냄

	printf("정렬 후: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
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