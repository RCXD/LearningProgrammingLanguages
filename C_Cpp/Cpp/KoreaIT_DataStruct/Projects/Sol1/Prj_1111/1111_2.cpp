#include <stdio.h>

int main() {
	FILE* in = fopen("../../../TEST/input.txt", "r");
	FILE* out = fopen("../../../TEST/output.txt", "w"); //디폴트: 덮어쓰기... 이름을 잘 작성해야 한다!!
	//덮어쓰는 과정의 데이터 소실을 방지하려면 어떤 코드가 있는가?

	int data[5];
	for (int i = 0; i < 5; i++) {
		fscanf(in, "%d", &data[i]);
	}

	//버블정렬... 암기해야하나?
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
}