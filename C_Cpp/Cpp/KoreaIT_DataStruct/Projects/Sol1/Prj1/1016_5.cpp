#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	/*Mission*/
	//����� ���� 1�� �Է� : 5
	//�Է��� ������ŭ �̾�Ĺ�� Ű�� �Է� : 5, 3, 7, 1, 9
	//�� �� �ִ� �������� ���� ��� => (2, 1, 2, 1, 0) = 6
	//**Ű�� ���� �̾�Ĺ�� ������ Ű�� ū �̾�Ĺ �ڿ� ������ �ִ��� �� �� ����.**
	//�� �̾�Ĺ�� �� �� �ִ� �̾�Ĺ�� ���� ���� ���. ��, �����ϸ� �ʸӸ� �� �� �ִ°����� ����

	int in1 = 0;
	printf("����� ���� 1�� �Է� :");
	scanf(" %d", &in1);
	printf("�� �̾�Ĺ�� Ű�� �Է� : ");
	int* arr = (int*)malloc(in1 * sizeof(int));

	for (int i = 0; i < in1; i++) {
		scanf(" %d", &arr[i]);
	}
	printf("%s", arr);

	free(arr);

	return;
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