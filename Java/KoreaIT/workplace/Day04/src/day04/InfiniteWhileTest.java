package day04;

import java.util.Scanner;

public class InfiniteWhileTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice = 0;
		do {
			System.out.println("다음 중 프로그래밍 언어가 아닌 것은?");
			System.out.println("1. C언어\n2. Java\n3. 망둥어\n4. 파이썬\n5. 나가기");
			choice=sc.nextInt();
			if (choice==3) {
				System.out.println("정답입니다.");
			} else if(choice==1 || choice==2 || choice==4) {
				System.out.println("오답입니다.");
			} else if(choice==0) {
				System.out.println("안녕히 가세요.");
			} else {
				System.out.println("잘못 입력하였습니다.");
			}		
		}while(choice!=0);
	}
}