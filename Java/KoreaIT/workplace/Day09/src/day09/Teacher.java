package day09;

//���� ���� �ڵ� �����ٶ�! 9����, 10���� ����
public class Teacher {
	static Student[] arStudent = new Student[1000];
	static int arCnt = 0;
	void addStudent(Student student) {
		if(arCnt=1000) {
			System.out.println("�л��� ���� á���ϴ�.");
			return;//���α׷� ����
		}
		arStudent[arCnt]=student;
		arCnt++;
	}
	void deleteStudent(String studname) {
		for (int i=0; i<arCnt; i++) {
			if(arStudent[i].name.equals(studname)) {
				for (int j=i; j<arCnt;i++) { //�� ������� ���� ����...?
					arStudent[j]=arStudent[j+1]; //1000�ϰ�� ������ ����ٳ�?
				}
				break;
			}
		}
	}
	
	void showAll() {
		//�̸� / ���� / �������
		if(arCnt>=1) {
			for(int i=0;i<arCnt;i++) {
				double avg = (arStudent[i].kor+arStudent[i].eng+arStudent[i].mat+arStudent[i].his+arStudent[i].com)/5.0;
				System.out.printf("%s / %d / %.2f\n", arStudent[i].name, arStudent[i].age, avg);
			}
		}else {
			System.out.println("��ϵ� �л��� �����ϴ�.");
		}
		System.out.println("=========================");
	}
	void updateStudent(String studname, int subChoice, int newData) { //�ҷ������ʿ��� �Ű������� �Է��ϰ� �ڵ������ϴ� ��� �˾ƾ���~!
		for (int i = 0; i < arCnt; i++) {
			if(arStudent[i].name.equals(studname)) {
				switch(subChoice) {
				case 1:
					arStudent[i].kor=newData;
					break;
				case 2:
					arStudent[i].mat=newData;
					break;
				case 3:
					arStudent[i].eng=newData;
					break;
				case 4:
					arStudent[i].his=newData;
					break;
				case 5:
					arStudent[i].com=newData;
					break;
				}
			}
		}
	}
}
