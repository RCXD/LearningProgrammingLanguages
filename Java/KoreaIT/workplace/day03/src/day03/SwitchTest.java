package day03;

import java.util.Scanner;

public class SwitchTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("���� �� ���α׷��� �� �ƴ� ����?");
		System.out.println("1. C���\n2. Java\n3. ���վ�\n4. ���̽�");
		int choice=sc.nextInt();
		switch(choice) {
		case 1: case 2: case 4: //OR������ �� �̷��� ����... C������ �ɵ�?
			System.out.println("�����Ӵ�.");
			break;
		case 3:
			System.out.println("�����Ӵ�.");
		default:
			System.out.println("�߸��Է�����.");
			break; //����Ű(Ctrl+Alt+��/�Ʒ�)�� �̰� ���鶧 ����� �����ѵ�.
		}
	}
}
