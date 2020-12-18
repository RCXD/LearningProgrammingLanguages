package day04;

import java.util.Scanner;
//Chanllenge: 증감식은 ++, --만, 초기값은 0으로 고정하고 도전하기

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
		//한번만 쓸 때는 이렇게
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
		
		int x = (int)('F'-'A')+1; //버그 조심. 개수: 간격+1
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
		
		//이진법 변환하기 ... String 뒤집기까지 활용.
		//알고리즘이 이게 효율적인건진 잘 모르겠다만.
		String result = "";
		int data = 20;
		for (int i = data; i > 0; i/=2) {
			result += i%2;
		} //new StringBuffer("문자열").reverse(): 문자열 뒤집기
		System.out.println(new StringBuffer(result).reverse());
		
	}
}
