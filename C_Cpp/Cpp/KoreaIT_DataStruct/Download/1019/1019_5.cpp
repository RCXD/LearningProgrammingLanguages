#include<stdio.h>
#include<stdlib.h>
int main() {
	/*
	// 학생수 : 3
	// 중간고사[]
	// 기말고사[]
	// 평균[] -> .2 => 1등 점수 구경
	int n;
	printf("학생수: ");
	scanf("%d", &n);
	int *score1 = (int*)malloc(n * sizeof(int));
	int *score2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("%d번 학생의 점수: ",i+1);
		scanf("%d%d", &score1[i], &score2[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d번 학생의 점수: %.2lf\n", i + 1, (score1[i] + score2[i]) / 2.0); // *1.0
	}
	
	int a, b;
	int num = 10;
	scanf("%d%d", &a, &b);
	int **data = (int**)malloc(a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		data[i] = (int*)malloc(b * sizeof(int));
		for (int j = 0; j < b; j++) {
			data[i][j] = num++;
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	*/

	int n;
	printf("학생수: ");
	scanf("%d", &n);
	int **data = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		data[i] = (int*)malloc(2 * sizeof(int));
		printf("%d번 학생의 점수: ", i + 1);
		for (int j = 0; j < 2; j++) {
			scanf("%d", &data[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d번 학생의 평균점수=", i + 1);
		double avg = 0.0;
		for (int j = 0; j < 2; j++) {
			avg+=data[i][j];
		}
		printf("%.2lf점\n",avg/2.0);
	}

	return 0;
}