#include<stdio.h>
int main() {

	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("abc.txt", "w");
	// 덮어쓰기: 디폴트설정
	// 파일존재하지않으면 새로 생성해준다!

	int data[5];
	for (int i = 0; i < 5; i++) {
		fscanf(in, "%d", &data[i]);
	}

	for (int a = 0; a < 5; a++) {
		for (int i = 0; i < 4; i++) {
			if (data[i] > data[i + 1]) {
				int tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		fprintf(out, "%d ", data[i]);
	}

	fclose(in);
	fclose(out);

	return 0;
}