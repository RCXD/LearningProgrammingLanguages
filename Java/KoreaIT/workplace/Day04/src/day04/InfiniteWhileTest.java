package day04;

import java.util.Scanner;

public class InfiniteWhileTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice = 0;
		do {
			System.out.println("���� �� ���α׷��� �� �ƴ� ����?");
			System.out.println("1. C���\n2. Java\n3. ���վ�\n4. ���̽�\n5. ������");
			choice=sc.nextInt();
			if (choice==3) {
				System.out.println("�����Դϴ�.");
			} else if(choice==1 || choice==2 || choice==4) {
				System.out.println("�����Դϴ�.");
			} else if(choice==0) {
				System.out.println("�ȳ��� ������.");
			} else {
				System.out.println("�߸� �Է��Ͽ����ϴ�.");
			}		
		}while(choice!=0);
	}
}