package day03;

import java.util.Scanner;

public class Flow {
	public static void main(String[] args) {
		int num = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("10���� ū ���� �Է��ϼ���: "); //���α׷����Ҷ� ���ε��: �Է��϶��Ѱ� ���� �Է����� �ʴ� ����ڰ� �ִٰ� ����.
		num=sc.nextInt();
		System.out.println(num>10?"���߾��":"���� 10���� ū���� �Է�"); //if���� ����ȣȯ�ΰŰ�����
	}
}
