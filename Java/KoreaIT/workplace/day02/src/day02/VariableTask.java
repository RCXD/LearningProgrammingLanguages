package day02;

public class VariableTask {
	public static void main(String[] args) {
		//===회원정보===
		//이름	: 000
		//키		: 182.24cm
		//몸무게	: 75.26kg
		//점수	: 'A'
		String name = "홍길동";
		float height = 182.24f;
		float weight = 75.26f;
		char score = 'A';
		System.out.println("===회원정보====");
//		System.out.printf("이름\t: %s\n", name);
//		System.out.printf("키\t: %.2fcm\n", height);
//		System.out.printf("몸무게\t: %.2fkg\n", weight);
//		System.out.printf("점수\t: '%c'\n", score);
		System.out.println("이름\t: "+name); //연결하기
		System.out.println("키\t: "+height+"cm");
		System.out.println("몸무게\t: "+weight+"kg");
		System.out.println("점수\t: \'"+score+"\'");
		//중요! 위 방식을 쓰면 넣어준 값만큼 포맷이 정해진다고 함.
			
		//Tip: 가장 많이 쓰는 기능키 3개!
		//Ctrl+Alt+↑(↓) : 위(아래)로 한줄 복사
		//Alt+↑(↓): 위(아래)로 한 줄 이동
		//Ctrl+Space
	}
}
