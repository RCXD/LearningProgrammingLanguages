package day04;

import java.util.Scanner;

public class WhileTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice = 0;
		while(choice!=3) { //�����϶��� Ż���ϴ� ���α׷�. �ʱⰪ�� �� �����������. �ƹ����� ���� ������ �Ǽ��� �� �� ����
			System.out.println("���� �� ���α׷��� �� �ƴ� ����?");
			System.out.println("1. C���\n2. Java\n3. ���վ�\n4. ���̽�");
			choice=sc.nextInt();
			if (choice==3) {
				System.out.println("�����Դϴ�.");
			} else if(choice==1 || choice==2 || choice==4) {
				System.out.println("�����Դϴ�.");
			} else {
				System.out.println("�߸� �Է��Ͽ����ϴ�.");
			}
		}
	}
}