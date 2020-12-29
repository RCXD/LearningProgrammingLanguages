package day07;

import java.util.Scanner;

public class MethodTest {
	public static void main(String[] args) {
		MethodTest m = new MethodTest();
//		Scanner sc = new Scanner(System.in);
//			int num1=sc.nextInt();
//			int num2=sc.nextInt();
		int data = 10;
		m.init(data);
		System.out.println(data);
			
	}
	//두 정수의 합 구하는 메소드
	void init(int[] data) { //main에서도 쓰고, 메소드에서도 쓰려면 static으로 변수를 선언해줘야 함.
		int result= num1+num2;
		data[0]+=10;
	}
}
