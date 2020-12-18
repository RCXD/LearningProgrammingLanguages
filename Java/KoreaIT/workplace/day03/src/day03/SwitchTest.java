package day03;

import java.util.Scanner;

public class SwitchTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("다음 중 프로그래밍 언어가 아닌 것은?");
		System.out.println("1. C언어\n2. Java\n3. 망둥어\n4. 파이썬");
		int choice=sc.nextInt();
		switch(choice) {
		case 1: case 2: case 4: //OR연산일 때 이렇게 응용... C에서도 될듯?
			System.out.println("정답임다.");
			break;
		case 3:
			System.out.println("오답임다.");
		default:
			System.out.println("잘못입력했음.");
			break; //단축키(Ctrl+Alt+위/아래)가 이거 만들때 상당히 유용한듯.
		}
	}
}
