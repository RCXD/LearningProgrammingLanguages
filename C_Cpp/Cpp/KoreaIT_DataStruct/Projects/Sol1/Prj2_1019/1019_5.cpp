#include "stdio.h"
#include "iostream"
#include "stdlib.h" //malloc

//#define MYSELF
#define TEACHER
#ifdef TEACHER
#define SET3
void main() {
	//�л� �� : 3
	//�߰����[]
	//�⸻���[]
	//���[] -> .2 => 1�� ���� ����

#ifdef SET1
	int n;
	printf("�л���: ");
	scanf("%d", &n);
	int* score1 = (int*)malloc(n * sizeof(int));
	int* score2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("%d�� �л��� ����: ", i+1);
		scanf("%d%d", &score1[i], &score2[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d�� �л��� ����: %.2lf\n", i + 1, (score1[i] + score2[i]) / 2.0f); //������ �켱������ �Ǽ� ����ϰ� �ϴ� ��Ʈ
	} //typeError ����. ���� ������ ���� �ʴ� *1.0�� �߰��ϰų� ������ �Ҽ��� ��Ÿ���°��� ���ٰ� ��.
#endif
	

#ifdef SET2
	//2�����迭 �����Ҵ��ϱ⵵ �����ϴ�!
	int a, b;
	int num = 10;
	scanf("%d%d", &a, &b);
	int** data = (int**)malloc(a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		//a = 3�� ���: data[0], data[1], data[2]�� �迭�� �Ҵ��� �� �ְ� �ȴ�.
		data[i] = (int*)malloc(b * sizeof(int));
		for (int j = 0; i < b; j++) {
			data[i][j] = num++; //10, 11, 12, ...�� ä���. i�� j�� �ٲٸ� Transpose�� �� �ְ���.
		}
	}

	//Show
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
#endif

#ifdef SET3
	int n;
	printf("�л���: ");
	scanf("%d", &n);
	int** data = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		data[i] = (int*)malloc(2 * sizeof(int));
		printf("%d�� �л��� ����: ", i + 1);
		for (int j = 0; j < 2; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d�� �л��� �������=", i + 1);
		double avg = 0.0;
		for (int j = 0; j < 2; j++) {
			avg += data[i][j];
		}
		printf("%.2lf��\n", avg/2.0);
	}
#endif
	return;

	/* Lecture 
	������ �迭. legged �迭? �����?
	legid?
	rigid?
	������, �������� �迭�� ���� �� �ִ�. 
	�����Ҵ��� �̿��ϸ� �������� �迭�� ������� �ִٰ� ��. ������ �ƴ϶�� ��.
	*/
}

#endif


#ifdef MYSELF
void main() {
	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */