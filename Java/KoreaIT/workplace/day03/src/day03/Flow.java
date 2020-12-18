package day03;

import java.util.Scanner;

public class Flow {
	public static void main(String[] args) {
		int num = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("10보다 큰 수를 입력하세요: "); //프로그래밍할때 마인드셋: 입력하라한걸 절대 입력하지 않는 사용자가 있다고 생각.
		num=sc.nextInt();
		System.out.println(num>10?"잘했어요":"제발 10보다 큰수를 입력"); //if문의 하위호환인거같은다
	}
}
