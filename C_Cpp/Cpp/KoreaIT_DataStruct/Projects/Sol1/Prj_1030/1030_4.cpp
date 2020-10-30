/* Mission
정수 1개 입력: 10
10 30 50 40 0 0 70 0 0 60
* 0을 입력할때마다 이전에 입력한 정보가 실행취소가 됨. pop이네 그냥
* 위 입력하면 10, 60이 남음
* 70 / 35.00 //총합, 평균 출력
* Keypoint: 실행 취소 => Stack!!!
*/ 

#define MYSELF
#ifdef MYSELF
#include<stdio.h>
#include<stdlib.h>
#define MAX = 100

//int stack[MAX];
//int index;


void main()
{
	while (1)
	{
		int len;
		int index = -1;
		printf("데이터의 총 개수(정수 1개) 입력: \n");
		scanf(" %d", &len);
		int* stack = (int*)malloc(len * sizeof(int));
		for (int i = 0; i < len; i++) {
			printf("0보다 큰 숫자 입력 or 실행 취소(0)\n");
			int input;
			scanf("%d", &input);
			if (input == 0) {
				printf("실행 취소\n");
				//show();
				if (index > -1) {
					printf("%d 삭제됨.\n", stack[index--]);
				}
				else {
					printf("스택이 비어있습니다.\n");
				}
			}
			else {
				stack[++index] = input;
				printf("%d 추가함\n", input);
			}
		}
		//총합
		if (index == -1) {
			printf("아무것도 입력되지 않았습니다.\n");
			break;
		}
		printf("스택: ");
		int sum = 0;
		for (int i = 0; i <= index; i++) {
			printf("%d ", stack[i]);
			sum += stack[i];
		}
		printf("\n");
		//평균
		double avg = sum / (index + 1);
		printf("총합, 평균: \n");
		printf("%3d / %.2lf\n", sum, avg);
		free(stack);
	}
	return;
}
#endif