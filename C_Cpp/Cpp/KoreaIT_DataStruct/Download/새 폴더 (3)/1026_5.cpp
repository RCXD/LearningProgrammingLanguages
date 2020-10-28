#include<stdio.h>
#include<stdlib.h>
int check(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] != 0) {
			return 1; // 즉시종료
		}
	}
	return 0;
}
int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	int *data = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++) {
		data[i] = i + 1;
	}

	int cnt = 0;
	int i = 0;
	while (check(data,a)) {
		if (data[i] == 0) {
			i++;
			if (i == a) { // 배열이용시, 인덱스범위확인!!!
				i = 0;
			}
			continue;
		}
		cnt++;
		if (cnt == b) {
			printf("%d ", data[i]);
			data[i] = 0;
			cnt = 0;
		}
		i++;
		if (i == a) {
			i = 0;
		}
	}
	// 정수 2개 입력 : 7 3
	// [1 2 3 4 5 6 7]
	//  => 3 6 2 7 5 1 4

	// 5 2
	// [1 2 3 4 5]
	//  => 2 4 1 5 3

	배열 VS 리스트

		인덱싱방식->검색(), 탐색()에 유리
		제한, 한정적->삽입(), 삭제()에 불리

		검색(), 탐색()에 불리
		삽입(), 삭제()에 유리
		제한적이지않음 == 동적임->공간효율이 좋음

		노드(NODE)
		데이터부 + 주소부(== 링크부)
		주소부 = > 다음노드를 가리키는 포인터가 존재함

	return 0;
}