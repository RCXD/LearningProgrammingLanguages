// ����ü
// ���� �迭  /  �ڷ����� ������ְ� ����
// �迭: 1.���� ���õ� ������ 2.�ڷ����� ����
#include<stdio.h>
#include<string.h>
struct stu {
	char name[10]; // �ʵ�,�Ӽ�,���
	int age; // . ��� ���� ������
	double avg;
};
int main() {

	struct stu s1 = { "kim",20,11.1 };
	struct stu s2;
	strcpy(s2.name, "lee"); // s2.name = "lee";
	s2.age = 30;
	s2.avg = 22.2;
	printf("%s�� ���̴� %d,������ %.2lf��\n", s1.name, s1.age, s1.avg);
	printf("%s�� ���̴� %d,������ %.2lf��\n", s2.name, s2.age, s2.avg);

	return 0;
}