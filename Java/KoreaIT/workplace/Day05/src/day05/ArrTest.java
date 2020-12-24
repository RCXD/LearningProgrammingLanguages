package day05;

public class ArrTest {
	public static void main(String[] args) {
		//배열이 필요한 이유. 변수이름의 규칙성은 의미가 없다. 
		//규칙성이 있든 없든 for문을 이용한 여러 변수의 초기화가 안됨.
		int[] arData = {10, 20, 30, 40, 50}; //C와 많이 다르네.
		System.out.println(arData[0]);
		for (int i = 0; i < arData.length; i++) { //배열과 for문을 잘 조합할줄 알아야 함.
			System.out.println(arData[i]);
		} //length 멤버를 지원함. 길이를 굳이 따질 필요 없다.
		
		int[] arData2=new int[5]; //0으로 초기화되는듯.
		for (int j = 0; j < arData2.length; j++) {
			System.out.println(arData2[j]); 
		}
		//null: 주소의 초기값
		int[] arData3=null;
//		arData3=new int[10];
		arData3=arData;
		arData3[0]=10;
	}
}
