#include<stdio.h>

int main() {
	FILE* in = fopen("../../../TEST/input.txt", "r");
	FILE* out = fopen("../../../TEST/output.txt", "w");

	int sum = 0;
	int cnt = 0;
	while (feof(in)==0) {//file end of file function! �������� 1
		int i;
		fscanf(in, "%d", &i); //������ �� �б�
		sum += i;
		cnt++;
	}
	fprintf(out, "����=%d\n���=%lf", sum, sum*1.0/cnt);

	fclose(in);
	fclose(out);
}