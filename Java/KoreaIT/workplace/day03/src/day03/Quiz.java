package day03;

import java.util.Scanner;

public class Quiz {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("다음 중 프로그래밍 언어가 아닌 것은?");
		System.out.println("1. C언어\n2. Java\n3. 망둥어\n4. 파이썬");
		int choice=sc.nextInt();
		if(choice==1||choice==2||choice==4) {
			System.out.println("정답임다.");
		} else {
			System.out.println("오답임다.");
		}
	}
}
