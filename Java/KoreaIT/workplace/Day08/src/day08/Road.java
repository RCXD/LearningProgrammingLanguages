package day08;

import java.util.Scanner;

public class Road {
	public static void main(String[] args) {
		Car mycar = new Car("Ferrari", "Red", 60000, 4643);
		Car momcar = new Car("K7", "White", 40000, 3535);
	}
}

class Car{
	String brand;
	String color;
	int price;
	boolean isStart = false;
	int pass;
	
	
	
	public Car(String brand, String color, int price, int pass) {
		super();
		System.out.println("Car 클래스 생성자 호출!");
		this.brand = brand;
		this.color = color;
		this.price = price;
		this.pass = pass;
	}
//	Car(String brand, String color, int price, int pass){
//		System.out.println("Car 클래스 생성자 호출!");
//		this.brand=brand;
//		this.color=color;
//		this.price=price;
//	}
	void enginStart() {
		if(isStart) { //boolean 타입을 쓰면 ==을 쓸 필요가 없다.
			System.out.println("이미 시동이 켜져 있습니다.");
		}else {
			if(checkPass());
			else return;
			System.out.println(brand+" 시동 켜기");
			isStart = true;
		}
	}
	void enginStop() {
		if(isStart) {
			System.out.println(brand+" 시동 끄기");
			isStart = false;
		}else {
			System.out.println("이미 시동이 켜져 있습니다.");
		}
	}
	boolean checkPass() {
		System.out.println("비밀번호를 입력하세요.: ");
		if(new Scanner(System.in).nextInt() == pass) {
			System.out.println("반갑습니다.");
			return true;
		}else {
			System.out.println("비밀번호가 틀렸습니다.");
//			checkPass(); //재귀호출해도 될듯
			return false;
		}	
	}
}