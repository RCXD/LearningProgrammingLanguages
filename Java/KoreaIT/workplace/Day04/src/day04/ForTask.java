package day04;

import java.util.Scanner;
//Chanllenge: �������� ++, --��, �ʱⰪ�� 0���� �����ϰ� �����ϱ�

public class ForTask {
	public static void main(String[] args) {
		for (int i = 0; i < 10; i++) {
			System.out.print((i+1)+" ");
		}
		System.out.println();
		for (int i = 0; i < 10; i++) {
			System.out.print((10-i)+" ");
		}
		System.out.println();
//		Scanner sc = new Scanner(System.in);
//		int n = sc.nextInt();
		//�ѹ��� �� ���� �̷���
		int n = new Scanner(System.in).nextInt();
		
		int sum = 0;
		for (int i = 0; i < n; i++) {
			System.out.print((i+1)+" ");
			sum += i+1;
		}
		System.out.println();
		System.out.println("sum = "+sum);
		
		for (int i = 0; i < 101; i++) {
			if(i%2==0) System.out.print(i+" ");	
		}
		System.out.println();
		
		int x = (int)('F'-'A')+1; //���� ����. ����: ����+1
		for (int i = 0; i<x; i++) {
			System.out.print((char)((int)'A'+i));
		}System.out.println();
		
		int M = (int)'A';
		int m = (int)'a';
		for (int i = 0; i<26; i++) {
			if(i%2==0) {
				System.out.print((char)(M+i));				
			} else {
				System.out.print((char)(m+i));
			}
		}
		System.out.println();
		
		//������ ��ȯ�ϱ� ... String ��������� Ȱ��.
		//�˰����� �̰� ȿ�����ΰ��� �� �𸣰ڴٸ�.
		String result = "";
		int data = 20;
		for (int i = data; i > 0; i/=2) {
			result += i%2;
		} //new StringBuffer("���ڿ�").reverse(): ���ڿ� ������
		System.out.println(new StringBuffer(result).reverse());
		
	}
}
