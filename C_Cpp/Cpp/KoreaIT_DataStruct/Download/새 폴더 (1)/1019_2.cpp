#include<stdio.h>
#include<stdlib.h>
int main() {
	
	// 정수 1개 입력: 5
	// 입력한 정수만큼 미어캣의 키를 입력: 5 3 7 1 9
	//  => 6

	int n;
	printf("정수 1개 입력: ");
	scanf("%d", &n);

	int *cat=(int*)malloc(n*sizeof(int));
	printf("입력한 정수만큼 미어캣의 키를 입력: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &cat[i]);
	}
	///
	int cnt = 0;
	for (int i = 0; i < n;i++) {
		// i가 0일때, [0] 키가 5인 미어캣친구
		for (int j = i +1; j < n; j++) {
			// j가 1일때, 즉 현재 비교대상은 [1] 키가 3인 친구
			cnt++;
			if (cat[i] < cat[j]) {
				break;
			}
		}
	}

	printf("cnt=%d\n", cnt);

	free(cat);

	return 0;
}