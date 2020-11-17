#include<stdio.h>
int main() {

	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	
	int sum = 0;
	int cnt = 0;
	while (!feof(in)) {
		int i;
		fscanf(in, "%d", &i);
		sum += i;
		cnt++;
	}
	fprintf(out,"√—«’=%d\n∆Ú±’=%.2lf\n", sum,sum*1.0/cnt);

	fclose(in);
	fclose(out);

	return 0;
}