package day03;

import java.util.Scanner;

public class InputTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		System.out.print("�̸� �Է�: ");
		System.out.print("name: ");
		String name = sc.next(); //���� ���� �� \n�� �Էµ�.
//		System.out.println(name+"�� �ȳ��ϼ���");
		System.out.println("hello, "+name);
		
		sc.nextLine(); //������ �ǹ̾��� �ԷµǾ� ������� ���͸� �������ش�.
//		System.out.print("�ּ�: "); //�Ұ����ִ� �ڵ尡 ������, ������ ���� �ٳ�(\n)�� �״�� �ް�, ����Ǿ������ ������ ����.
		System.out.print("Your address: ");
		String addr = sc.nextLine();
		System.out.println(addr);
		}
}

//Ŀ���� �ǵڷ� �Ȱ��°�... ��Ŭ������ �ѱ��Է� ���׶�� ��.
