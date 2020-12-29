package day07;

import java.util.Scanner;

public class MethodTask {
	public static void main(String[] args) {
		//�޼ҵ� ȣ���� ���� main()���� �ϰ�, �Էµ� main()���� ���� ��
		//�޼ҵ�� �Ѱ��ִ� ����� �̿��Ѵ�.
		MethodTask M = new MethodTask();
		
		//1~10���� ����ϴ� �޼ҵ�
		M.outNum(1, 10);
		//1~10���� �� ���ϴ� �޼ҵ�
		System.out.println(M.sum(1, 10));
		//1~n���� �� ����ϴ� �޼ҵ�
		System.out.println("1~n���� ���ϱ� ���� n �Է�:");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(M.sum(1, n));
		
		System.out.println("n~m���� ���ϱ� ���� �� �� �Է�:");
		n = sc.nextInt();
		int m = sc.nextInt();
		//n~m������ �� �����ִ� �޼ҵ�
		System.out.println(M.sum(n, m));
		//�� ������ ������ �޼ҵ�
		System.out.println("n/m ������ ���� �� ���� �Է�: ");
		n = sc.nextInt();
		m = sc.nextInt();
		System.out.println(M.div(n, m));
		
		//�ҹ��ڸ� �빮�ڷ� �ٲ��ִ� �޼ҵ�
		System.out.println("�빮��ȭ�� ���ڿ� �Է�:");
		String s = sc.next();
//		System.out.println(M.capit(s)); //String�� ��ȯ������ ���� ����? python�� �����ʴ���
//		M.outCapit(s.toCharArray());
		System.out.println(M.capit(s));
		//���ڿ� �Ųٷ� ����ϴ� �޼ҵ�("ASDF" -> "FDSA") //��Ʈ������ �Ⱦ��ٴ°� ����������?
		//������ ��Ʈ�� �޼ҵ� �Ⱦ��� �ϱ�
		System.out.println("������ ���ڿ� �Է�: ");
		s = sc.next();
		System.out.println(M.inv(s));
		//������ �ѱ۷� �ٲ��ִ� �޼ҵ�(1024 -> "�ϰ��̻�")
		System.out.println("�ѱ۷� �ٲ� ���� �Է�: ");
		int input = sc.nextInt();
		System.out.println(M.hangle(input));
		
	}
	void outNum(int x, int y) {
		while(y>=x) {
			System.out.print(x++ +" ");			
		}System.out.println();
	}
	int sum(int x, int y) {
		int sum = x;
		while(y>x++) {
			sum+=x;
		}
		return sum;
	}
	double div(int x, int y) {
		return y*1.0/x;
	}
	String capit(String s) {
		return s.toUpperCase();
//		int d = 'A'-'a';
//		String res = "";
//		for (int i = 0; i < s.length(); i++) {
//			char ch = s.charAt(i); //�ѱ��ڴ� ���� �ڷ����� ���� �� �ִ�.
//			if(ch>='a' && ch<='z') {
//				res += (char)(ch+d);
//			}
//			else 
//				res += ch;
//		} //�̷��� �ϸ� ����� ���ڵ鵵 �� ó����.
//		return res;
	}
	String inv(String s) { 
		String res = "";
		for (int i = 0; i < s.length(); i++) {
			res += s.charAt(s.length()-1-i);
		}
		return res;
	}
	String hangle(int n) {
		String han = "�����̻�����ĥ�ȱ�";
		String res="";
		do {
			res+=han.charAt(n%10);
			n /= 10;
		}while(n>0);
		MethodTask M = new MethodTask(); //�̺κ��� �� �����ε�.
		return M.inv(res);
	}
	changeKR(int num){
		String result="";
		String hangle="�����̻�����ĥ�ȱ�";
		String data=num+""; //1024
		//������!
		//'0': 48		'1' : 49
		//0: '0'-48		1: '1'-48
		for (int i = 0; i < data.length(); i++) {
//			char ch = data.charAt(i); //'1', '0', '2', '4'
//			int idx = ch-48;
//			result+= hangle.charAt(idx);
			result+=hangle.charAt(data.charAt(i)-48);
		}
	}
}
