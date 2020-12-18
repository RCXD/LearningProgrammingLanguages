package day03;

import java.util.Scanner;

public class InputTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		System.out.print("이름 입력: ");
		System.out.print("name: ");
		String name = sc.next(); //엔터 누를 때 \n이 입력됨.
//		System.out.println(name+"님 안녕하세요");
		System.out.println("hello, "+name);
		
		sc.nextLine(); //위에서 의미없이 입력되어 대기중인 엔터를 제거해준다.
//		System.out.print("주소: "); //소거해주는 코드가 없으면, 위에서 누른 텐너(\n)을 그대로 받고, 종료되어버리는 오류가 생김.
		System.out.print("Your address: ");
		String addr = sc.nextLine();
		System.out.println(addr);
		}
}

//커서가 맨뒤로 안가는건... 이클립스의 한글입력 버그라고 함.
