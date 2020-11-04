//삽입정렬

#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
#include <stdio.h>
//뭘 잘못만든거지???
void insertion_sort(int* a, int len) {
	for (int i = 1; i < len; i++) {
		for (int j = 0; i < i; j++) {
			if (a[i] > a[j]) {
				//교환
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		//정렬과정 보기
		for (int j = 0; j < len; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

/*원본소스
* void insertion_sort(int *a, int len) {
   for (int i = 1; i < len; i++) {
      for (int j = 0; j < i; j++) {
         if (a[i] < a[j]) {
             // [교환]
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
         }
      }
      for (int j = 0; j < len; j++) {
         printf("%d ", a[j]);
      }
      printf("\n");
   }
}
*/

int main() {
	int data[] = { 5, 4, 7, 1, 2 };

	printf("정렬 전: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	insertion_sort(data, sizeof(data)/sizeof(data[0])); //배열 자체를 보냄

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