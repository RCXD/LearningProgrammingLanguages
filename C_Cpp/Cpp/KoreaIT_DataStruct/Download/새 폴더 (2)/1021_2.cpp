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
	printf("���� x��ǥ�Է�: ");
	scanf("%d", &pp.x);
	printf("���� y��ǥ�Է�: ");
	scanf("%d", &pp.y);

	*p = pp;
}
int main() {

	/*
	P p1 = { 1,1 };
	P p2;
	input(&p2);

	P p3 = f(p1, p2);
	printf("p3�� ��ǥ�� (%d,%d)�Դϴ�.\n", p3.x, p3.y);
	*/

	int n;
	printf("���� ������ �Է��ϼ���.  ");
	scanf("%d", &n);
	P *p = (P*)malloc(n * sizeof(P));
	for (int i = 0; i < n; i++) {
		printf("%d�� ���� x��ǥ�Է�: ",i+1);
		scanf("%d", &p[i].x);
		printf("%d�� ���� y��ǥ�Է�: ", i + 1);
		scanf("%d", &p[i].y);
		printf("p%d(%d,%d)\n\n", i + 1, p[i].x, p[i].y);
	}
	int x=0, y=0;
	for (int i = 0; i < n; i++) {
		x += p[i].x;
		y += p[i].y;
	}
	printf("x��ǥ�� ���� %d�̰�, y��ǥ�� ���� %d�Դϴ�.\n", x, y);


	return 0;
}