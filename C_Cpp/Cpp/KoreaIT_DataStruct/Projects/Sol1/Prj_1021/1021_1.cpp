#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER



//������ ���̱�!
/*
typedef struct �ڷ����� {
}�ٲ� �̸�;
*/
typedef struct stu {
    char name[10];
    int num; //��ȣ�� �� �ʿ��ϴ�. ���������� ���� ���� �ְ�.
    //��, ���� �������� �Ǵ��ϴ� ���̴�.
    //���α׷��� Tip.
    int score[2];
    double avg;
    char grade;
}S;

void show(int i) {
    printf("%d", i);
}

void show(S s) {
    printf("%d", s.num);
} //�ڵ尡 �ſ� ª������ �������� ��������!!
//C�� ����ü ���� ������ �ʳ�?
//Ŭ������ ũ�� ���� ������..?

void main() {

    int i = 10;
    show(i);
    S s[10]; //�迭�� ���� �� �ִ�. �ڷ����̴ϱ�.

    //���� �޸� �Ҵ�:
    int n;
    scanf("%d", &n);
    S s[n]; //�ڷ����� �� �� �ִ°͵��� ��κ� �� �� �ִٰ�
    //�����ϸ� �ȴٰ� �Ѵ�.

    //����ü�� �ϳ��� �ڷ��� ����!
    //1. �Լ��� ���� ���� ����
    //2. �迭 -> ����ü �迭�� ����
    //3. �迭�����͸� �� �� �ִ�.
    //4. ���� �迭�� ���� �� �ִ�.
    //struct stu s1;
    
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