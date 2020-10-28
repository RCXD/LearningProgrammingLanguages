#include<stdio.h>
int main() {
	
	// 프로젝트->속성->C->전처리기
	// _CRT_SECURE_NO_WARNINGS
	
	int a, b;
	printf("1.두개의 정수를 입력: ");
	scanf("%d%d", &a, &b);
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	printf("%d의 %d승 = %d\n\n", a, b, res);

	printf("2.3개의 실수를 입력하세요.\n");
	double arr[3];
	int cnt=0;
	for (int i = 0; i < 3; i++) {
		printf("%d번: ", i+1);
		scanf("%lf", &arr[i]);
		if (arr[i] < 0.0) {
			cnt++;
		}
	}
	printf("이 중 음수는 %d개\n", cnt);

	return 0;
}