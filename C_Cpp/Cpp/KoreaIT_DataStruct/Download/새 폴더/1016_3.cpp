// 포인터
#include<stdio.h>
void swap(int *a,int *b) { // 사용자정의함수에서 수행한 결과가 main()에게도 영향이 있을때
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void show(int *arr) { // 함수의 인자로 배열을 받을때
	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void f(int *arr,int *a,int len) {
	printf("%d\n", sizeof(arr));

	// [최대값찾기]알고리즘
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	//printf("max=%d\n", max);
	*a = max;
}
int main() {
	/*
	int x = 10;
	int y[] = { 1,2,3 };
	printf("%d %d %d\n", sizeof(x), sizeof(y), sizeof(y[0]));
	printf("y배열의 크기는 %d입니다.\n", sizeof(y) / sizeof(y[0]));
	*/

	int arr[] = { 17,4,99,25,33 };
	int a = 0;
	f(arr,&a,sizeof(arr)/sizeof(arr[0])); // &arr[0]
	printf("arr배열에서 가장큰수는 %d입니다.\n", a);

	/*
	int a = 10;
	int b = 20;
	// [교환]알고리즘 -> 임시저장변수
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);

	int arr[] = { 1,2,3 };
	show(arr); // arr==&arr[0]
	*/
	return 0;
}