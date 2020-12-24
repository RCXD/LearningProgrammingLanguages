package day06;

public class MethodTest {
	public static void main(String[] args) {
		//규칙성이 없으면, for문으로 여러 상황을 처리하기 어렵다.
		
		MethodTest m = new MethodTest();
		System.out.println(m.f(3)); //f가 정의된 클래스의 객체를 만들고, 객체의 메소드로 불러와야 사용 가능.
		
		System.out.println("구구단");
		m.print99(3); //함수명에 같다대면 리턴값을 바로 알 수 있다.
		System.out.println(m.plus(10, 5));
	}
	//f(x) = 2x+1
	//정의한 범위를 잘 확인해서 호출해야 한다.
	int f(int x) { //main과 f는 다른 구역에 정의되어 있다는점을 주의.
		return 2*x+1;
	}
	//구구단 출력 메소드
	void print99(int dan) {
		for (int i = 1; i < 10; i++) {
			System.out.println(dan+" X "+i+" = "+i*dan);
		}
	}
	//두 정수의 덧셈 메소드
	int plus(int num1, int num2) {
		int result = num1+num2;
		System.out.println("두 정수의 덧셈 메소드입니다."); //출력형태도 바꾸고싶을 때가 있다. 따라서 이럴 때에는 리턴을 주는게 좋다.
		return result;
	}
}
