#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	/*Mission*/
	//사용자 정수 1개 입력 : 5
	//입력한 개수만큼 미어캣의 키를 입력 : 5, 3, 7, 1, 9
	//볼 수 있는 마리수의 합을 출력 => (2, 1, 2, 1, 0) = 6
	//**키가 작은 미어캣은 다음의 키가 큰 미어캣 뒤에 무엇이 있는지 볼 수 없다.**
	//각 미어캣이 볼 수 있는 미어캣의 마리 수를 출력. 단, 동일하면 너머를 볼 수 있는것으로 간주

	int in1 = 0;
	printf("사용자 정수 1개 입력 :");
	scanf(" %d", &in1);
	printf("각 미어캣의 키를 입력 : ");
	int* arr = (int*)malloc(in1 * sizeof(int));

	for (int i = 0; i < in1; i++) {
		scanf(" %d", &arr[i]);
	}
	printf("%s", arr);

	free(arr);

	return;
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