#include "stdio.h"
#include "iostream"
#include "stdlib.h" /* malloc�� ���� ����!*/ 
// malloc : memory allocator
// �Ҵ�(allocation) : ���� ���� ���� �������� ����.
#define MAX 5 //��ó���⿡ ������ ����� ��ȣ���. �������α׷����� �ƴ�.

//Title: ���� �޸� �Ҵ�!!!!
//���� ���α׷��� : ���α׷��� ����Ǳ� ���� �Ϻ��ϰ� ���õǾ��ִ� ���
//�迭�� �����̴�.
//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	int n;
	printf("�迭 ���� �Է�: \n");
	scanf("%d", &n);
	//int arr[n]; //�迭������ �����̴�. �˰� �ִ� ��츸 �����ϴ�.
	/* ���� �迭 �����ϴ� ��� */
	int* arr = (int*)malloc(n * sizeof(int));
	//arr�̶�� �����Ͱ� �� ����(�ʵ�)�� ����Ű�� ����. ũ��� n���� ������.
	//(int*)�� �ڷ����� �����ѵ�? sizeof(int)�� �ڷ����� �����Ѱǰ�?
	//*arr�� �Ҵ���� �޸��� �ݳ��� free()�� �ݳ��Ѵ�.
	/* �� */
	//TIP : �����ʹ� ���ѵ� ��쿡�� ����� ��. 
	//�뵵 1. ��������� �Լ����� ������ ����� main���� ������ ��ĥ ��
	//�뵵 2. �迭�� ���ڷ� ���� ��
	//�뵵 3. ���� �޸𸮸� �Ҵ��� �� ���.

	printf("�迭 ���� �Է�: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr); //�Ҵ���� �޸� �ݳ�. �޸� �뷮�� ������� �ݳ��� �� ���ִ°� ���ٰ� ��.
	//�Ҵ���� �޸𸮸� ���߿� �ٽ� ����� �� �ֵ��� ��.
	//��ǻ�Ϳ����� �������� ������� �ʴ� �޸𸮴� �ڵ����� �ݳ��Ǳ�� �Ѵٰ� ��.
	//Reference : https://modoocode.com/244

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