package day09;

//강의 보고 코드 수정바람! 9일차, 10일차 강의
public class Teacher {
	static Student[] arStudent = new Student[1000];
	static int arCnt = 0;
	void addStudent(Student student) {
		if(arCnt=1000) {
			System.out.println("학생이 가득 찼습니다.");
			return;//프로그램 종료
		}
		arStudent[arCnt]=student;
		arCnt++;
	}
	void deleteStudent(String studname) {
		for (int i=0; i<arCnt; i++) {
			if(arStudent[i].name.equals(studname)) {
				for (int j=i; j<arCnt;i++) { //맨 끝방까지 가서 삭제...?
					arStudent[j]=arStudent[j+1]; //1000일경우 문제가 생긴다나?
				}
				break;
			}
		}
	}
	
	void showAll() {
		//이름 / 나이 / 평균점수
		if(arCnt>=1) {
			for(int i=0;i<arCnt;i++) {
				double avg = (arStudent[i].kor+arStudent[i].eng+arStudent[i].mat+arStudent[i].his+arStudent[i].com)/5.0;
				System.out.printf("%s / %d / %.2f\n", arStudent[i].name, arStudent[i].age, avg);
			}
		}else {
			System.out.println("등록된 학생이 없습니다.");
		}
		System.out.println("=========================");
	}
	void updateStudent(String studname, int subChoice, int newData) { //불러오는쪽에서 매개변수를 입력하고 자동수정하는 방법 알아야함~!
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
