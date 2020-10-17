#include "stdio.h"
#include "iostream"

/* Title : Pointer */


//#define MYSELF
#define TEACHER
#ifdef TEACHER
void swap_p(int* a, int* b) { //연산 결과가 main()에도 영향이 있을 때
	int tmp = *a; //* 없으면 그냥 주소값임
	*a = *b;
	*b = tmp;
}

void show(int* arr) { //함수의 인자로 배열을 받을 때
	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
#ifdef MYSELF
void f(int *arr, int *max) { //Mission
	//int len = sizeof arr / sizeof arr[0];
	int len = sizeof arr;
	//printf("%d\n", len);
	//printf("%d\n", sizeof arr);
	//printf("%d\n", sizeof arr[0]);
	*max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > *max) *max = arr[i];
	}
}
#endif
#ifndef MYSELF
void f(int *arr, int *a, int len) {
	//최대값 찾기 알고리즘
	//알고리즘 해답을 찾을 때에는, 그림을 먼저 그리고 설계하라!
	//printf("%d\n", sizeof(arr)); //비정상적. 그냥 int의 크기.
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	*a = max; //마지막에 전달해주는게 더 낫겠다. 안정성 생각하면.
	printf("max = %d\n", max);
}
#endif

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
	//a, b의 값이 바뀌지 않음. 주소값을 받아오지 않기 때문
}

void main() {
	/*
	int x = 10;
	int y[] = { 1, 2, 3 };
	printf("%d %d %d\n\n", sizeof(x), sizeof(y), sizeof(y[0]));
	printf("y 배열의 크기는 %d입니다.\n", sizeof(y)/sizeof(y[0]));

	printf("\n\n");
	*/

	/* Mission */
	int arr_2[] = { 17, 4, 99, 25, 33 };
	//printf("%d\n", sizeof arr_2); //정상적인 배열 크기(배열 개수 * 자료형 크기)
	//printf("%d\n", sizeof arr_2[0]); //정상적인 배열 1개의 자료형의 크기
	int max = 0;
#ifdef MYSELF
	f(arr_2, &max);
#endif
#ifndef MYSELF
	f(arr_2, &max, sizeof(arr_2)/sizeof(arr_2[0])); //여기서 배열크기를 보내줘야하네... 쩝.
#endif
	printf("arr배열에서 가장 큰 수는 %d입니다.\n", max);
	printf("\n");
	/* end of mission*/

	int a = 10;
	int b = 20;
	//교환 알고리즘
	//a = b; 그냥 넣으면 a가 사라져서 문제가 생김.
	int tmp = a;
	a = b;
	b = tmp;
	printf("a = %d b = %d\n", a, b);
	swap(a, b);
	printf("a = %d b = %d\n", a, b); //안바뀜
	swap_p(&a, &b);
	printf("a = %d b = %d\n", a, b); //바뀜. 리턴없이 처리하고싶으면 C에서는 포인터를 활용.

	int arr[] = { 1, 2, 3 };
	show(arr); //arr == &arr[0]이므로, arr은 일반 자료형으로는 받을 수 없다.

	return;
}

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* 디버깅표 그리기
 *	Line		a	b
 *				10	20
 *	a = b		20	20
 *	b = a		20	20	//의미없는 동작
 */