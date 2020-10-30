/* Mission
���� 1�� �Է�: 10
10 30 50 40 0 0 70 0 0 60
* 0�� �Է��Ҷ����� ������ �Է��� ������ ������Ұ� ��. pop�̳� �׳�
* �� �Է��ϸ� 10, 60�� ����
* 70 / 35.00 //����, ��� ���
* Keypoint: ���� ��� => Stack!!!
*/ 

#define MYSELF
#ifdef MYSELF
#include<stdio.h>
#include<stdlib.h>
#define MAX = 100

//int stack[MAX];
//int index;


void main()
{
	while (1)
	{
		int len;
		int index = -1;
		printf("�������� �� ����(���� 1��) �Է�: \n");
		scanf(" %d", &len);
		int* stack = (int*)malloc(len * sizeof(int));
		for (int i = 0; i < len; i++) {
			printf("0���� ū ���� �Է� or ���� ���(0)\n");
			int input;
			scanf("%d", &input);
			if (input == 0) {
				printf("���� ���\n");
				//show();
				if (index > -1) {
					printf("%d ������.\n", stack[index--]);
				}
				else {
					printf("������ ����ֽ��ϴ�.\n");
				}
			}
			else {
				stack[++index] = input;
				printf("%d �߰���\n", input);
			}
		}
		//����
		if (index == -1) {
			printf("�ƹ��͵� �Էµ��� �ʾҽ��ϴ�.\n");
			break;
		}
		printf("����: ");
		int sum = 0;
		for (int i = 0; i <= index; i++) {
			printf("%d ", stack[i]);
			sum += stack[i];
		}
		printf("\n");
		//���
		double avg = sum / (index + 1);
		printf("����, ���: \n");
		printf("%3d / %.2lf\n", sum, avg);
		free(stack);
	}
	return;
}
#endif