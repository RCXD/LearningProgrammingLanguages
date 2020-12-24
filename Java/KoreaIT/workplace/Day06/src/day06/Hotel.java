package day06;

import java.util.Scanner;

public class Hotel {
	public static void main(String[] args) {
		//101호~103호
		//201호~203호
		//301호~303호
		
		//입력 예
		//101호 월세:
		//102호 월세:
		//...
		//303호 월세
		
		//1층 총 월세:
		//1층 평균 월세:
		//2층..
		//...
		//3층 평균 월세:
		//총 월세의 합:
		//전체 월세 평균:
		
		//Strategy: 2차원 배열
		int FLOORS = 3;
		int DOORS = 3;
		int[][] rooms = new int[FLOORS][DOORS];
		int[][] rent = new int[FLOORS][DOORS];
		Scanner sc = new Scanner(System.in);
		int[] sums = new int[FLOORS];
		float[] avgs = new float[FLOORS];
		String unit = " 만원";
		
		for (int j = 0; j < rooms.length; j++) {
			for (int i = 0; i < rooms[0].length; i++) {
				System.out.println((j+1)+"0"+(i+1)+"호 월세: ");
				rent[j][i]=sc.nextInt();
				sums[j] += rent[j][i];
			}
			avgs[j] = sums[j]*1.0F/DOORS;
		}
		System.out.println();
		
		int SUM = 0;
		float AVG = 0.0F;
		for (int i = 0; i < sums.length; i++) {
			System.out.println((i+1)+"층 총 월세: "+sums[i]+unit);
			SUM += sums[i];
			System.out.println((i+1)+"층 평균 월세: "+avgs[i]+unit);
		}
		AVG = SUM*1.0F/(FLOORS*DOORS);
		
		System.out.println("총 월세의 합: "+SUM+unit);
		System.out.println("전체 월세의 평균: "+AVG+unit);
	}
}
