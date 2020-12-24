package codeUp01;

import java.util.Scanner;

//https://codeup.kr/problem.php?id=1096
//1096 : [기초-2차원배열] 바둑판에 흰 돌 놓기(설명)

//public class Main { //제출하려면 이거로 바꾸면 됨.
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
