package day03;

import java.util.Scanner;

public class NumTest {
	public static void main(String[] args) {
		//숫자 두개 입력받아서 비교 후
		Scanner sc = new Scanner(System.in);
		System.out.println("숫자 두개를 입력하세요");
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		System.out.println(num1==num2?"두 수가 같습니다":num1>num2 ? "num1이 큽니다": "num2이 큽니다");
		//java는 삼항연산자에 "값"만 쓸 수 있다. 변수(문자)를 쓸 수 없다. -> 제약 발생. C에서는 변수도 가능.
		
	}
}
