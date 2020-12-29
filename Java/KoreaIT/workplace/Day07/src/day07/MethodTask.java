package day07;

import java.util.Scanner;

public class MethodTask {
	public static void main(String[] args) {
		//메소드 호출은 전부 main()에서 하고, 입력도 main()에서 받은 후
		//메소드로 넘겨주는 방식을 이용한다.
		MethodTask M = new MethodTask();
		
		//1~10까지 출력하는 메소드
		M.outNum(1, 10);
		//1~10까지 합 구하는 메소드
		System.out.println(M.sum(1, 10));
		//1~n까지 합 출력하는 메소드
		System.out.println("1~n까지 합하기 위한 n 입력:");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(M.sum(1, n));
		
		System.out.println("n~m까지 합하기 위한 두 수 입력:");
		n = sc.nextInt();
		int m = sc.nextInt();
		//n~m까지의 합 구해주는 메소드
		System.out.println(M.sum(n, m));
		//두 정수의 나눗셈 메소드
		System.out.println("n/m 연산을 위한 두 정수 입력: ");
		n = sc.nextInt();
		m = sc.nextInt();
		System.out.println(M.div(n, m));
		
		//소문자를 대문자로 바꿔주는 메소드
		System.out.println("대문자화할 문자열 입력:");
		String s = sc.next();
//		System.out.println(M.capit(s)); //String은 반환형으로 쓸수 없나? python은 되지않던가
//		M.outCapit(s.toCharArray());
		System.out.println(M.capit(s));
		//문자열 거꾸로 출력하는 메소드("ASDF" -> "FDSA") //스트링버퍼 안쓴다는게 무슨말이지?
		//리버스 스트링 메소드 안쓰고 하기
		System.out.println("뒤집을 문자열 입력: ");
		s = sc.next();
		System.out.println(M.inv(s));
		//정수를 한글로 바꿔주는 메소드(1024 -> "일공이사")
		System.out.println("한글로 바꿀 정수 입력: ");
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
//			char ch = s.charAt(i); //한글자는 문자 자료형에 넣을 수 있다.
//			if(ch>='a' && ch<='z') {
//				res += (char)(ch+d);
//			}
//			else 
//				res += ch;
//		} //이렇게 하면 잡다한 문자들도 잘 처리됨.
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
		String han = "공일이삼사오육칠팔구";
		String res="";
		do {
			res+=han.charAt(n%10);
			n /= 10;
		}while(n>0);
		MethodTask M = new MethodTask(); //이부분이 좀 별로인듯.
		return M.inv(res);
	}
	changeKR(int num){
		String result="";
		String hangle="공일이삼사오육칠팔구";
		String data=num+""; //1024
		//착안점!
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
