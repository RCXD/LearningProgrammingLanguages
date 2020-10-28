#include<stdio.h>
#include<stdlib.h>
typedef struct point {
	int x;
	int y;
}P;
P f(P a,P b) {
	P res;
	res.x = (a.x + b.x) / 2;
	res.y = (a.y + b.y) / 2;
	return res;
}
void input(P *p) {

	P pp;
	printf("점의 x좌표입력: ");
	scanf("%d", &pp.x);
	printf("점의 y좌표입력: ");
	scanf("%d", &pp.y);

	*p = pp;
}
int main() {

	/*
	P p1 = { 1,1 };
	P p2;
	input(&p2);

	P p3 = f(p1, p2);
	printf("p3의 좌표는 (%d,%d)입니다.\n", p3.x, p3.y);
	*/

	int n;
	printf("점의 개수를 입력하세요.  ");
	scanf("%d", &n);
	P *p = (P*)malloc(n * sizeof(P));
	for (int i = 0; i < n; i++) {
		printf("%d번 점의 x좌표입력: ",i+1);
		scanf("%d", &p[i].x);
		printf("%d번 점의 y좌표입력: ", i + 1);
		scanf("%d", &p[i].y);
		printf("p%d(%d,%d)\n\n", i + 1, p[i].x, p[i].y);
	}
	int x=0, y=0;
	for (int i = 0; i < n; i++) {
		x += p[i].x;
		y += p[i].y;
	}
	printf("x좌표의 합은 %d이고, y좌표의 합은 %d입니다.\n", x, y);


	return 0;
}