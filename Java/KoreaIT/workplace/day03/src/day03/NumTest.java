package day03;

import java.util.Scanner;

public class NumTest {
	public static void main(String[] args) {
		//���� �ΰ� �Է¹޾Ƽ� �� ��
		Scanner sc = new Scanner(System.in);
		System.out.println("���� �ΰ��� �Է��ϼ���");
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		System.out.println(num1==num2?"�� ���� �����ϴ�":num1>num2 ? "num1�� Ů�ϴ�": "num2�� Ů�ϴ�");
		//java�� ���׿����ڿ� "��"�� �� �� �ִ�. ����(����)�� �� �� ����. -> ���� �߻�. C������ ������ ����.
		
	}
}
