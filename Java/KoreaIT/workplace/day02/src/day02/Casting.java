package day02;

public class Casting {
	public static void main(String[] args) {
//		System.out.println(10/3);
//		System.out.println((10+0.0)/3); //자동으로 float형으로 변환된다. 묵시적으로 실행됨
		System.out.println(10*1.0/3); //연산순서 때문에 이것도 가능. 그래서 결국 double형으로 바뀌는 것임
		System.out.println('A'+5); //이건 원래 C언어에선 안되는거같았는데... 아마?
			//ASCII 코드표 참조. 'A'+5 == 'F'
			//자동 형변환이라 하기 조금 애매해보이지만, 아무튼.
		System.out.println((int)10.24784); //소수점 소거
		System.out.println((int)'a'); //ASCII로 변환
		
		//형변환 연산자의 우선순위는 산술 연산자의 우선순위보다 높다.
		System.out.println((int)(8.43+2.59)); //괄호를 안쓰면 8+2.59 > 10.59가 나옴.
	}
}
