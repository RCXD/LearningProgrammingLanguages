package day05;

public class ArrTest2 {
	public static void main(String[] args) {
		//행: 작은 배열의 개수
		//열: 작은 배열의 칸수
		int[][] arData = {{1,2,3}, {4,5,6}};
		for (int i = 0; i < arData.length; i++) {
			for (int j = 0; j < arData[0].length; j++) {
				System.out.println(arData[i][j]);
			}
		}
		for (int i = 0; i < 6; i++) {
			System.out.println(arData[i/3][i%3]); //되기는 한다
		}
	}
}
