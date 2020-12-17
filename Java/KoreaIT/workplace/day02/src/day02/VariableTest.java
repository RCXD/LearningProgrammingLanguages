package day02;

public class VariableTest {
	public static void main(String[] args) {
		int data = 100;
		//반복적인 데이터를 brutal force로 반복하는건 유동성이 현저히 떨어짐
		//반복문을 이용하면 유동성이 좋아진다.
//		float f = 10.2778; //실수형은 이렇게 정의할 수 없다. 에러.
		//10.2778 > 이거는 double을 의미
		float f = 10.2778f;
//		float f = 10.2778F; //이것도 문제없다.
		double d = -12.147;
		char c = 'a';
//		char s = "Hello";
		String s = "Hello"; //기본지원
		
		System.out.printf("%d\n", data);
		System.out.printf("f 변수에 들어있는 값: %f\n", f);
		System.out.printf("d : %f\nc : %c\n", d, c);
		
	}
}
