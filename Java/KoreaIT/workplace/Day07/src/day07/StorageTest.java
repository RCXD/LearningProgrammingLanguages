package day07;

//int data3; //클래스 밖에는 선언할 수 없다.
public class StorageTest {
	int data2; //클래스 내부에 선언되면 전역변수 개념이라고 함.
	static int data3; //클래스 내에서 쓸 수 있는 정적변수.(위치가 전역변수 선언위치이므로 호출범위는 전역과 같은 상태)
	public static void main(String[] args) {
//		int data;
//		System.out.println(data); //초기화 안되어있으면 에러남.
		//지역변수 초기화는 직접 해줘야 한다.
//		System.out.println(data2); //main에서는 전역변수를 접근할 수 없다. (일반 메소드에서는 접근가능)
		//접근제어의 문제가 아니라, 메모리 문제라고 함. 이유는?
		//이유: static이 붙은것들은 가장 먼저 메모리에 올라간다. data2는 전역변수이므로 아직 올라가있지 않다. 
		//따라서 static 메인함수에서는 접근불가.
		//좀 웃기지만...
		System.out.println(data3);
	}
	void method() {
		int data = 0;
		System.out.println(data2); //전역변수를 이상없이 가져올 수 있다.
	}
}
