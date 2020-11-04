//선택정렬: 기초!!
//5 4 7 1 2에서, 가장 작은 1과 5을 교환
//1 _4_ 7 5 2 //4와 가장 작은 2를 교환
//1 2 7 5 4
//1 2 _7_ 5 4 //7과 가장 작은 4를 교환



#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER


void selection_sort(int* a, int len) {
	for (int x = 0; x < len; x++) {
		int min = a[x];
		int minIndex = x;
		for (int i = x + 1; i < len; i++) {
			if (min > a[i]) {
				min = a[i];
				minIndex = i;
			}
		}
		// min 가장작은값 -> 0과 minIndex 값을 교환
		int tmp = a[x];
		a[x] = a[minIndex];
		a[minIndex] = tmp;
	}
}

void main...
//마저 만들라...
#endif


#ifdef MYSELF
//미완성... 실수 확인바람!
int data[] = { 5, 4, 7, 1, 2 };

void main() {
	
	
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++) {
		int min = data[i];
		for (int j = i+1; j < size; j++) {
			if (min > data[j]) {
				int tmp = min;
				min = data[j];
				data[j] = tmp;
			}
		}
		for (int i = 0; i < size; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
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