package day02;

import java.util.Scanner;

public class InputTest {
	public static void main(String[] args) {
		//Sc까지 쓰고 Ctrl+Space, Enter누르면 import까지 자동으로 완성됨!
		Scanner sc = new Scanner(System.in);
		//또는, Ctrl+Shift+O 누르면 추가되지 않은 패키지 불러옴
		//단, 원하는게 불러와질 수도 없는게 단점. 자동완성추가를 권장!
		
//		sc.next(); //콘솔창이 입력하고 엔터 누를때까지 기다림. 빨간불이 활성화됨(정지기능 활성화)
			//프로그램이 실행중, 즉 대기중이라는 얘기.
		System.out.print("이름: ");
		String name=sc.next(); //문자열 값으로 취급. 반환값이 문자열!
		System.out.println(name+"님 안녕하세요");
		System.out.print("정수 입력: ");
//		String data = sc.next();
		int data=sc.nextInt();
		System.out.println("결과: "+((data+5)); //string->int 강제 casting 안됨.

		//Java Tip: 이름을 보고 메소드를 활용
		//이게 네이밍규칙이 빡센 이유라고 함.
	}
}
