package codeUp01;

import java.util.Scanner;

//https://codeup.kr/problem.php?id=1096
//1096 : [����-2�����迭] �ٵ��ǿ� �� �� ����(����)

//public class Main { //�����Ϸ��� �̰ŷ� �ٲٸ� ��.
public class TwoDimArray01 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[][] floor = new int[19][19];
		int num = sc.nextInt();
		for (int i = 0; i < num; i++) {
			floor[sc.nextInt()-1][sc.nextInt()-1] = 1;			
		}
		
		for (int i = 0; i < floor.length; i++) {
			for (int j = 0; j < floor[0].length; j++) {
				System.out.print(floor[i][j]+" ");
			}System.out.println();
		}
	}
}
