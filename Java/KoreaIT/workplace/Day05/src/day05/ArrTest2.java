package day05;

public class ArrTest2 {
	public static void main(String[] args) {
		//��: ���� �迭�� ����
		//��: ���� �迭�� ĭ��
		int[][] arData = {{1,2,3}, {4,5,6}};
		for (int i = 0; i < arData.length; i++) {
			for (int j = 0; j < arData[0].length; j++) {
				System.out.println(arData[i][j]);
			}
		}
		for (int i = 0; i < 6; i++) {
			System.out.println(arData[i/3][i%3]); //�Ǳ�� �Ѵ�
		}
	}
}
