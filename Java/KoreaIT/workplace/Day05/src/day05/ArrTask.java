package day05;

import java.util.Scanner;

public class ArrTask {
	public static void main(String[] args) {
		//for�� �̿��ؼ� 1~10���� �迭�� �ְ� ���
		int[] arData = new int[10];
		for (int i = 0; i < arData.length; i++) {
			arData[i] = i+1;
			System.out.print(arData[i]+" ");
		}System.out.println();
		
		//for�� �̿��ؼ� 10~1���� �迭�� �ְ� ���
		int[] arData2 = new int[10];
		for (int i = 0; i < arData2.length; i++) {
			arData2[i] = 10-i;
			System.out.print(arData2[i]+ " ");
		}System.out.println();
		
		Scanner sc = new Scanner(System.in);
		String[] subject = {"����", "����", "����", "����", "�ѱ���"};
		
		String[] name = new String[2];
		for (int j = 0; j < name.length; j++) {
			System.out.print((j+1)+"��° ����� �̸�: ");
			name[j] = sc.next();
			
			//����, ����, ����, ����, �ѱ��� ���� �Է¹ް� ������ ��� ���
			int[][] score = new int[name.length][subject.length];
			
			float avg = 0;
			int sum = 0;
			for (int i = 0; i < subject.length; i++) {
				System.out.print(subject[i]+" ����:");
				score[j][i] = sc.nextInt();
//				System.out.println();
				sum += score[j][i];
			}
			
			avg = sum/score.length*1.0F;
			System.out.println(name[j]+"���� ����: "+sum);
			System.out.println(name[j]+"���� ��� ����: "+avg);
			
		}System.out.println();
	} //������ �ѹ��� ��ġ��: Alt + Shift + R(Rename) : ������ ����ϴ� ������ ���Բ� ����
}
