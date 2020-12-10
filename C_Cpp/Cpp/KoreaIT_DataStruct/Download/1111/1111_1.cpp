#include<stdio.h>
int main() {

	FILE* fp = fopen("input.txt","r");
	// 파일이 존재하지않으면 에러가 발생!
	
	FILE* fp2 = fopen("output.txt", "w");

	// 유효성 검사
	if (fp == NULL) {
		printf("파일열기실패!\n");
	}
	else {
		printf("파일열기성공!\n");
	}

	int a;
	double b;
	char c;
	char d[10];
	fscanf(fp,"%d %lf %c %s", &a, &b, &c, d);
	fprintf(fp2, "%d %lf %c %s\n", a, b, c, d);
	fprintf(fp2, "파일내용작성성공!\n");

	fclose(fp);
	fclose(fp2);

	return 0;
}