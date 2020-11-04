//퀵정렬!
//재귀함수 활용(순환호출)

#include<stdio.h>



/*
int fac(int n) {
	//종료조건 필요
	if (n == 1) {
		return 1;
	}
	return n * fac(n - 1);
}


int main() {
	printf("5!=%d\n", fac(5));

	return 0;
}
*/

//퀵정렬은 정렬속도가 빠름
//분할(Divide)->정복: 정렬(Conquer) -> 결합, 합병(Combine)... 결합, 합병은 무엇? 인터넷에서 찾아보자.,..
//3 5 7 9 1 10 6 2 8 4
//3을 Pivot, 5을 L, 4를 R
//L은 3보다 작지 않으면 stop / R은 3보다 크지 않으면 stop
//모두 stop되면 L과 R을 교환하고, 다시 안으로 이동(물으면서)
//L과 R이 교차되면 루프 종료, Pivot과 R을 교환
//R은 새로운 Pivot, Pivot 좌우를 분할하고 다시 정렬


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int l, int r) {
	int tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}
void quick_sort(int* a, int start, int end) {
	int pivot = a[start];
	int L = start + 1;
	int R = end;
	while (L <= R) {
		while (a[L] < pivot) {
			L++;
		}
		while (a[R] > pivot) {
			R--;
		}
		if (L <= R) {
			swap(a, L, R);
		}
	}
	if (start < end) {//배열크기가 1개가 될 때까지 반복
		swap(a, start, R);
		quick_sort(a, start, R - 1); //재귀 호출
		quick_sort(a, R + 1, end);
	}
}

void search() {
	//검색함수 구현!
}

#define MAX 10
int main()
{
	//데이터 10개 랜덤으로 저장
	srand((unsigned int)time(NULL));
	
	int a[MAX];
	for (int i = 0; i < MAX; i++) {
		a[i] = rand() % 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	//원하는 값 사용자가 입력하면 인덱스 위치를 알려줌
	//왜 안되지? 수리좀...???
	printf("원하는 값 입력: ");
	int input;
	scanf("%d ", &input);
	quick_sort(a, 0, 9);
	int ans = -1;
	for (int i = 0; i < MAX; i++) {
		if (input == a[i]) {
			ans = a[i];
			printf("%d는 %d 인덱스에 있습니다.", input, i);
			break;
		}
	}
	if (ans == -1) printf("해당 데이터 없음!");
	//[?]에 있습니다 vs 해당 데이터 없음!

	int data[] = { 3, 5, 7, 9 ,1, 10, 6, 2, 8 ,4 };
	printf("정렬 전:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	quick_sort(data, 0, 9);

	printf("정렬 후:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}