#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void inputNum(int *p) {
	int num;
	printf("복권의 수는 몇개입니까?  ");
	scanf("%d", &num);
	*p = num;
}
void show(int *data,int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main() {

	int num;
	inputNum(&num);
	int *lotto = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		lotto[i] = rand() % 50 + 1;
	}
	show(lotto,num);

	// 5
	// 1 2 3 4 5 << 컴퓨터가 설정!
	// 3점 축하합니다!

	// 만약, 복권의 수가 홀수라면 +1점 득점
	// num=5 -> 3개이상 [축하합니다!]
	// num=10 -> 5개이상 [축하합니다!]

	// 점수만들기 수행
	int point = 0;
	for (int i = 0; i < num; i++) {
		if (lotto[i] % 2) { // lotto[i] % 2 == 1
			point++;
		}
	}
	printf("%d점! ", point);
	if (num / 2 <= point) {
		printf("축하합니다!");
	}
	printf("\n");

	return 0;
}