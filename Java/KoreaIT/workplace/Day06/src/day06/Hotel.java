package day06;

import java.util.Scanner;

public class Hotel {
	public static void main(String[] args) {
		//101ȣ~103ȣ
		//201ȣ~203ȣ
		//301ȣ~303ȣ
		
		//�Է� ��
		//101ȣ ����:
		//102ȣ ����:
		//...
		//303ȣ ����
		
		//1�� �� ����:
		//1�� ��� ����:
		//2��..
		//...
		//3�� ��� ����:
		//�� ������ ��:
		//��ü ���� ���:
		
		//Strategy: 2���� �迭
		int FLOORS = 3;
		int DOORS = 3;
		int[][] rooms = new int[FLOORS][DOORS];
		int[][] rent = new int[FLOORS][DOORS];
		Scanner sc = new Scanner(System.in);
		int[] sums = new int[FLOORS];
		float[] avgs = new float[FLOORS];
		String unit = " ����";
		
		for (int j = 0; j < rooms.length; j++) {
			for (int i = 0; i < rooms[0].length; i++) {
				System.out.println((j+1)+"0"+(i+1)+"ȣ ����: ");
				rent[j][i]=sc.nextInt();
				sums[j] += rent[j][i];
			}
			avgs[j] = sums[j]*1.0F/DOORS;
		}
		System.out.println();
		
		int SUM = 0;
		float AVG = 0.0F;
		for (int i = 0; i < sums.length; i++) {
			System.out.println((i+1)+"�� �� ����: "+sums[i]+unit);
			SUM += sums[i];
			System.out.println((i+1)+"�� ��� ����: "+avgs[i]+unit);
		}
		AVG = SUM*1.0F/(FLOORS*DOORS);
		
		System.out.println("�� ������ ��: "+SUM+unit);
		System.out.println("��ü ������ ���: "+AVG+unit);
	}
}
