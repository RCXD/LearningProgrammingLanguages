package day05;

import java.util.Scanner;

public class ArrTask {
	public static void main(String[] args) {
		//for문 이용해서 1~10까지 배열에 넣고 출력
		int[] arData = new int[10];
		for (int i = 0; i < arData.length; i++) {
			arData[i] = i+1;
			System.out.print(arData[i]+" ");
		}System.out.println();
		
		//for문 이용해서 10~1까지 배열에 넣고 출력
		int[] arData2 = new int[10];
		for (int i = 0; i < arData2.length; i++) {
			arData2[i] = 10-i;
			System.out.print(arData2[i]+ " ");
		}System.out.println();
		
		Scanner sc = new Scanner(System.in);
		String[] subject = {"국어", "수학", "영어", "과학", "한국사"};
		
		String[] name = new String[2];
		for (int j = 0; j < name.length; j++) {
			System.out.print((j+1)+"번째 사용자 이름: ");
			name[j] = sc.next();
			
			//국어, 수학, 영어, 과학, 한국사 점수 입력받고 총점과 평균 출력
			int[][] score = new int[name.length][subject.length];
			
			float avg = 0;
			int sum = 0;
			for (int i = 0; i < subject.length; i++) {
				System.out.print(subject[i]+" 점수:");
				score[j][i] = sc.nextInt();
//				System.out.println();
				sum += score[j][i];
			}
			
			avg = sum/score.length*1.0F;
			System.out.println(name[j]+"님의 총점: "+sum);
			System.out.println(name[j]+"님의 평균 점수: "+avg);
			
		}System.out.println();
	} //변수명 한번에 고치기: Alt + Shift + R(Rename) : 변수명 사용하는 곳까지 다함께 변경
}
