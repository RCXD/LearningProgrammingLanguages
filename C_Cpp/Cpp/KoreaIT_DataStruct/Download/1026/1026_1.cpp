// ����ü << �ϳ��� �ڷ���!
// 1. �Լ��� ����
// 2. �迭 -> ����ü �迭
// 3. ������
// 4. �����޸��Ҵ�

// typedef -> ����������
#include<stdio.h>
#define SU 5 // ��ȣ���==��������ǻ��
typedef struct stu {
	char name[10];
	int num; // �� ���� �������� �Ǵ��ϱ����� ����!
	int score[2];
	double avg;
	char grade;
}S;
int main() {

	// 1. �л��߰�
	// 2. �л��� ������ ���
	// 3. �л��� ���� ����-> ����,�̸�
	// 4. �л�����
	// 5. 1���� �л� �̸��� ���
	// 6. ��ü �л��� ���� ���
	// 7. ����

	//printf("������ ����Ͻðڽ��ϱ�?  "); <<�����޸�
	S book[SU];
	int index = 0;
	int num = 1001;

	int act;
	while (1) {
		printf("=====�л��� ���α׷�=====\n");
		printf("1.�л��߰�\n");
		printf("2.�л��������\n");
		printf("3.�л���������\n");
		printf("4.�л�����\n");
		printf("5.1�� Ȯ��\n");
		printf("6.�л��� ���\n");
		printf("7.����\n");
		printf(" : ");
		scanf("%d", &act);
		if (act == 1) {
			if (index >= SU) {
				printf("�л��ΰ� ����á���ϴ�!\n\n");
				continue;
			}

			printf("�л��̸��Է�: ");
			scanf("%s", book[index].name);
			book[index].num = num++;
			for (int i = 0; i < 2; i++) {
				printf("����%d�����Է�: ", i + 1);
				scanf("%d", &book[index].score[i]);
			}
			int sum = 0;
			for (int i = 0; i < 2; i++) {
				sum += book[index].score[i];
			}
			book[index].avg = sum / 2.0; // *1.0
										 /*
										 book[index].avg = 0.0;
										 for (int i = 0; i < 2; i++) {
										 book[index].avg += book[index].score[i];
										 }
										 book[index].avg /= 2.0;
										 */
			if (book[index].avg >= 50.0) {
				book[index].grade = 'A';
			}
			else if (book[index].avg >= 10.0) {
				book[index].grade = 'B';
			}
			else {
				book[index].grade = 'C';
			}
			printf("%s �Է¿Ϸ�!\n\n", book[index++].name);
		}
		else if (act == 2) {
			int n;
			while (1) {
				printf("������ ������� �л��� ��ȣ�Է�: ");
				scanf("%d", &n);
				if (n <= 1000 || n >= 2000) {
					printf("�ùٸ� ������ �ƴմϴ�!\n");
					//continue;
				}
				else {
					break;
				}
			}
			for (int i = 0; i < index; i++) {
				// ���¹�ȣ�� �Է�������,
				// �ش��л��� ���������ʽ��ϴ�! << ������ּ���!~~
				if (n == book[i].num) {
					printf(" %d�� %s %c %.2lf��\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
					break;
				}
			}
			printf("\n");
		}
		else if (act == 3) {
			printf("� ������ �����Ͻðڽ��ϱ�?\n1.�̸� 2.����  ");
			int nn;
			scanf("%d", &nn);
			int n;
			while (1) {
				printf("������ �����ϰ���� �л��� ��ȣ�Է�: ");
				scanf("%d", &n);
				if (n <= 1000 || n >= 2000) {
					printf("�ùٸ� ������ �ƴմϴ�!\n");
					//continue;
				}
				else {
					break;
				}
			}
			for (int i = 0; i < index; i++) {
				// ���¹�ȣ�� �Է�������,
				// �ش��л��� ���������ʽ��ϴ�! << ������ּ���!~~
				if (n == book[i].num) {
					printf(" %d�� %s %c %.2lf��\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
					if (nn == 1) {
						// �̸�����
						printf("�̸�����: ");
						scanf("%s", book[i].name);
					}
					else {
						// ��������
						printf("��������x2: ");
						scanf("%d%d", &book[i].score[0], &book[i].score[1]);
					}
					break;
				}
			}
			printf("\n");
		}
		else if (act == 4) {
			if (index == 0) {
				printf("���� �Ұ���!\n\n");
				continue;
			}
			printf("%s �л�����������!\n\n", book[--index].name); // �����ǥ�� Ȯ���ϱ�!!!�ڡ١ڡ�
		}
		else if (act == 5) {
			if (index == 0) {
				printf("�л��ο� �л��� ���������ʽ��ϴ�!\n\n");
				continue;
			}
			double max = book[0].avg;
			int maxIndex = 0;
			for (int i = 1; i < index; i++) {
				if (max < book[i].avg) {
					max = book[i].avg;
					maxIndex = i;
				}
			}
			printf("1���� %s�Դϴ�!\n\n", book[maxIndex].name);
		}
		else if (act == 6) {
			printf("===�л���===\n");
			for (int i = 0; i < index; i++) {
				printf(" %d.%-5s %c %5.2lf��\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
			}
			printf("\n");
		}
		else if (act == 7) {
			printf("\n���α׷� ����\n\n");
			break;
		}
		else {
			printf("��ȿ�������� ��ȣ�Դϴ�!\n");
			printf("�ٽ��Է��ϼ���!\n\n");
		}
	}

	return 0;
}