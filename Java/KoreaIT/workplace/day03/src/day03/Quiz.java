package day03;

import java.util.Scanner;

public class Quiz {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("���� �� ���α׷��� �� �ƴ� ����?");
		System.out.println("1. C���\n2. Java\n3. ���վ�\n4. ���̽�");
		int choice=sc.nextInt();
		if(choice==1||choice==2||choice==4) {
			System.out.println("�����Ӵ�.");
		} else {
			System.out.println("�����Ӵ�.");
		}
	}
}
