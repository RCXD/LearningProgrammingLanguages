#include <stdio.h>

int main() {
	FILE* in = fopen("../../../TEST/input.txt", "r");
	FILE* out = fopen("../../../TEST/output.txt", "w"); //����Ʈ: �����... �̸��� �� �ۼ��ؾ� �Ѵ�!!
	//����� ������ ������ �ҽ��� �����Ϸ��� � �ڵ尡 �ִ°�?

	int data[5];
	for (int i = 0; i < 5; i++) {
		fscanf(in, "%d", &data[i]);
	}

	//��������... �ϱ��ؾ��ϳ�?
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