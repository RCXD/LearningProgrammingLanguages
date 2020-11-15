#include<stdio.h>

int main() {
	FILE* in = fopen("../../../TEST/input.txt", "r");
	FILE* out = fopen("../../../TEST/output.txt", "w");

	int sum = 0;
	int cnt = 0;
	while (feof(in)==0) {//file end of file function! ³¡³µÀ¸¸é 1
		int i;
		fscanf(in, "%d", &i); //°¡Áø°Å ´Ù ÀÐ±â
		sum += i;
		cnt++;
	}
	fprintf(out, "ÃÑÇÕ=%d\nÆò±Õ=%lf", sum, sum*1.0/cnt);

	fclose(in);
	fclose(out);
}