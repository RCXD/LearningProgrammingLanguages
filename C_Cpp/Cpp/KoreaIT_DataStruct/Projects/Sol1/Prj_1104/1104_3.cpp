//��������

#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
#include <stdio.h>
//�� �߸��������???
void insertion_sort(int* a, int len) {
	for (int i = 1; i < len; i++) {
		for (int j = 0; i < i; j++) {
			if (a[i] > a[j]) {
				//��ȯ
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		//���İ��� ����
		for (int j = 0; j < len; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

/*�����ҽ�
* void insertion_sort(int *a, int len) {
   for (int i = 1; i < len; i++) {
      for (int j = 0; j < i; j++) {
         if (a[i] < a[j]) {
             // [��ȯ]
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
         }
      }
      for (int j = 0; j < len; j++) {
         printf("%d ", a[j]);
      }
      printf("\n");
   }
}
*/

int main() {
	int data[] = { 5, 4, 7, 1, 2 };

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	insertion_sort(data, sizeof(data)/sizeof(data[0])); //�迭 ��ü�� ����

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
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