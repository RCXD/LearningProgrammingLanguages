package day02;

import java.util.Scanner;

public class InputTest {
	public static void main(String[] args) {
		//Sc���� ���� Ctrl+Space, Enter������ import���� �ڵ����� �ϼ���!
		Scanner sc = new Scanner(System.in);
		//�Ǵ�, Ctrl+Shift+O ������ �߰����� ���� ��Ű�� �ҷ���
		//��, ���ϴ°� �ҷ����� ���� ���°� ����. �ڵ��ϼ��߰��� ����!
		
//		sc.next(); //�ܼ�â�� �Է��ϰ� ���� ���������� ��ٸ�. �������� Ȱ��ȭ��(������� Ȱ��ȭ)
			//���α׷��� ������, �� ������̶�� ���.
		System.out.print("�̸�: ");
		String name=sc.next(); //���ڿ� ������ ���. ��ȯ���� ���ڿ�!
		System.out.println(name+"�� �ȳ��ϼ���");
		System.out.print("���� �Է�: ");
//		String data = sc.next();
		int data=sc.nextInt();
		System.out.println("���: "+((data+5)); //string->int ���� casting �ȵ�.

		//Java Tip: �̸��� ���� �޼ҵ带 Ȱ��
		//�̰� ���ֱ̹�Ģ�� ���� ������� ��.
	}
}
