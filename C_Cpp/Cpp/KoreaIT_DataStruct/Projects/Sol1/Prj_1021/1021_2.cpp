#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#define StuNum 5 //��ȣ���(����� ���ǻ��)�� �� ����� ��! ����, ��Ÿ ���ɼ� �ּ�ȭ����.

#define MYSELF
//#define TEACHER
#ifdef TEACHER
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
			if (index > ? ? ? ? ? ? ) {
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
			// 2���׼ǰ� �����ϰ� �������ּ���!
			// ������ �����ϰ���� �л��� ��ȣ�Է�:
			// 1. �̸� / 2. ����
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

#endif


#ifdef MYSELF

typedef struct point {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;

void main() {
	//1. �л� �߰�
	//2. �л��� ���� ���
	//3. �л��� ���� ���� -> ����, �̸�
	//4. �л� ����
	//5. 1���� �л� �̸��� ���
	//6. ��ü �л��� ���� ���
	//7. ����

	printf("===========�л��� ���α׷�===========\n\n");

	int n;
	printf("�л��ο� ������ �Է��ϰڽ��ϱ�?");
	scanf("%d", &n);
	S* book = (S*)malloc(n * sizeof(S));
	//S book[StuNum]; //��ó���� Ȱ���Ͽ� ���� ���̱�
	int index = 0; //stack!
	int num = 1001; //�ο��� �л���ȣ�� �ʱⰪ

	while (1)
	{
		int input;
		printf("1. �л� �߰�\n"); //������� ������ ����ֱ��. (push)
		printf("2. �л��� ���� ���\n");
		printf("3. �л��� ���� ����\n");
		printf("4. �л� ����\n"); //�ϴ�, �����ʰ� ���� ������ ���� �����ϱ��. (pop)
		printf("5. 1�� Ȯ��\n");
		printf("6. ��ü �л��� ���\n");
		printf("7. ��ü �л��� ���\n");

		scanf(" %d", &input);


		if (input == 1) {
			printf("�л� �̸��� �Է��ϼ���.\n");
			scanf("%s", book[index].name);
			book[index].num = num++;
			printf("�߰���� ������ �Է��ϼ���.\n");
			scanf(" %d", &book[index].score[0]);
			printf("�⸻��� ������ �Է��ϼ���.\n");
			scanf(" %d", &book[index].score[1]);
			book[index].avg = (book[index].score[0] + book[index].score[1]) / 2.0;
			
			//���� �Ǵ�
			if (book[index].avg >= 50.0) {
				book[index].grade = 'A';
			}
			else if (book[index].avg >= 30.0) {
				book[index].grade = 'B';
			}
			else {
				book[index].grade = 'C';
			}
			printf("%s �Է� �Ϸ�!\n", book[index].name);
			index++; //�ſ� �߿��� �κ�
		}

		else if (input == 2) {
			//���߿� �˻� �˰����� ���� �� �ڵ巯���� �ϰ�
			//������ �����ϰ� ����

			int n;
			while (1) { //�ùٸ� ������ �������� �Է����� �𸣴� �ݺ��� ����
				printf("������ ������� �л��� ��ȣ �Է�: \n");
				scanf("%d", &n);
				if (n <= 1000 || n >= 2000) {
					printf("�ùٸ� ������ �ƴմϴ�!\n");
				}
				else {
					break;
				}
				for (int i = 0; i < index; i++) {
					//���� ��ȣ�� �Է����� ��
					//�ش� �л��� �������� �ʽ��ϴ�! << ���� ����ϱ�. (����)
					if (n == book[i].num) {
						printf("%d�� %-5s %c %5.2lf��\n", book[i].num, book[i].name, book[i].grade, book[i].avg);
						break;
					}
				}
				for (int i = 0; i <= index; i++) {

				}
			}
		}
		else if (input == 3) { //���� ����
			//����
			//2���� �����ϰ� ����
			//������ �����ϰ���� �л��� ��ȣ �Է�:
			//1. �̸� / 2. ���� (�����ؼ� �����ϱ�)
		}
		else if (input == 4) { //�л� ����
			//�� ���� �����ϰ�, ���� �����Ǿ����� �˷��ֱ�
			//index �ϳ� ���̱�
			//index ���� �� �ؼ� �� �����.
			//if (index == *0*�� or 1 or -1) { //����!
			//	printf("���� �Ұ���!\n");
			//	continue; //���������� ���� �����ϴ�
			//}
			printf("%s �л����� ������\n", book[index-1].name); //index-1�� �ƴϸ� ������ �����Ⱚ�� �о����ٰ�?
			//�����ǥ �׸���!!!!
		}
		//TEACHER
		else if (input == 5) {
			//�л��� 0���� ��
			if (index == 0) {
				printf("�л��ο� �л��� �������� �ʽ��ϴ�!\n\n");
				continue;
			}

			double max;
			int maxIndex = 0;
			for (int i = 1; i < index; i++) {
				if (max < book[i].avg) {
					max = book[i].avg;
					maxIndex = 1;
				}
			}
			printf("1���� %s�Դϴ�!\n", book[maxIndex].name);
		}
		else if (input == 6) {
			//...
		}
		else if (input == 7) break;
		else {
			printf("��ȿ���� ���� �����Դϴ�.\n"); //��ȿ�� �˻�
			continue;
		}
	}
	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */