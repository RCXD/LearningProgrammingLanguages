package day05;

public class ArrTest {
	public static void main(String[] args) {
		//�迭�� �ʿ��� ����. �����̸��� ��Ģ���� �ǹ̰� ����. 
		//��Ģ���� �ֵ� ���� for���� �̿��� ���� ������ �ʱ�ȭ�� �ȵ�.
		int[] arData = {10, 20, 30, 40, 50}; //C�� ���� �ٸ���.
		System.out.println(arData[0]);
		for (int i = 0; i < arData.length; i++) { //�迭�� for���� �� �������� �˾ƾ� ��.
			System.out.println(arData[i]);
		} //length ����� ������. ���̸� ���� ���� �ʿ� ����.
		
		int[] arData2=new int[5]; //0���� �ʱ�ȭ�Ǵµ�.
		for (int j = 0; j < arData2.length; j++) {
			System.out.println(arData2[j]); 
		}
		//null: �ּ��� �ʱⰪ
		int[] arData3=null;
//		arData3=new int[10];
		arData3=arData;
		arData3[0]=10;
	}
}
