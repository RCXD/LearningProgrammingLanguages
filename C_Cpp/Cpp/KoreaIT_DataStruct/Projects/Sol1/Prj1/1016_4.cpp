#include "stdio.h"
#include "iostream"
#include "stdlib.h" /* malloc을 쓰기 위함!*/ 
// malloc : memory allocator
// 할당(allocation) : 몫을 갈라 양을 나눠놓는 개념.
#define MAX 5 //전처리기에 의존한 사용자 기호상수. 동적프로그래밍이 아님.

//Title: 동적 메모리 할당!!!!
//정적 프로그래밍 : 프로그램이 실행되기 전에 완벽하게 세팅되어있는 방식
//배열은 정적이다.
//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	int n;
	printf("배열 개수 입력: \n");
	scanf("%d", &n);
	//int arr[n]; //배열개수는 정적이다. 알고 있는 경우만 가능하다.
	/* 동적 배열 정의하는 방법 */
	int* arr = (int*)malloc(n * sizeof(int));
	//arr이라는 포인터가 빈 공간(필드)을 가리키는 개념. 크기는 n으로 결정됨.
	//(int*)로 자료형을 결정한듯? sizeof(int)도 자료형을 결정한건가?
	//*arr로 할당받은 메모리의 반납은 free()로 반납한다.
	/* 끝 */
	//TIP : 포인터는 제한된 경우에서 사용할 것. 
	//용도 1. 사용자정의 함수에서 실행한 결과가 main에서 영향을 미칠 때
	//용도 2. 배열을 인자로 받을 때
	//용도 3. 동적 메모리를 할당할 때 사용.

	printf("배열 원소 입력: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr); //할당받은 메모리 반납. 메모리 용량이 작을경우 반납을 잘 해주는게 좋다고 함.
	//할당받은 메모리를 나중에 다시 사용할 수 있도록 함.
	//컴퓨터에서는 오래동안 사용하지 않는 메모리는 자동으로 반납되기는 한다고 함.
	//Reference : https://modoocode.com/244

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