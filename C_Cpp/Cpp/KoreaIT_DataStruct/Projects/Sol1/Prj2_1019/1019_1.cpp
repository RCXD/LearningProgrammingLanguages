#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	//정수 1개 입력
	// 입력한 정수만큼 미어캣의 키를 입력 : 5 1 3 7 9
	// => 6

	int n;
	printf("정수 1개, 입력: ");
	scanf("%d", &n);

	int cnt = 0;
	int *cat=(int*) malloc(n*sizeof(int));
	printf("입력한 정수만큼 미어캣의 키를 입력: ");
	for (int i = 0; i < n; i++){
			scanf("%d", &cat[i]);
	}
	for(int i = 0; i < n; i++){
		//i가 0일때 [0] 키가 5인 미어캣 친구
		for(int j= i+1; j < n ; j++){ //i+1, i+2, i+3, ...
			if (cat[i] < cat[j]) {//너머를 못보는 경우
				cnt++; //너머를 못봐도, 큰놈 하나는 보이니까 카운트해야 함.(중요!)
				break;
			}
			else { //볼 수 있는게 있다면 누적
				cnt++;
			}
		}
		printf("cnt=%d\n", cnt);
	}
	printf("answer = %d\n", cnt);

	//for문은 입력부-수행부를 나눠서 중첩하지 않고 코딩하는것이 가장 좋다고 함.

	free(cat);

	return;
}

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* Debugging Table
 *	Line
 *	
 *
 *
 */