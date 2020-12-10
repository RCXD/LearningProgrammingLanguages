#include<stdio.h>
int main() {

	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	printf("사용자의 이름을 입력하세요.\n");
	char name[10];
	scanf("%s", name);

	int data, n, cnt = 0;
	fscanf(in, "%d", &data);
	while (1) {
		printf("데이터입력: ");
		scanf("%d", &n);
		cnt++;
		if (n == data) {
			printf("정답!\n");
			break;
		}
		else if (n > data) {
			printf("DOWN!\n");
		}
		else {
			printf("UP!\n");
		}
	} // 이진탐색
	fprintf(out, "%s님, %d번만에 정답!\n", name, cnt);

	fclose(in);

	return 0;
}