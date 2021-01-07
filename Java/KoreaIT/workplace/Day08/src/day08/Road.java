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
		System.out.println("Car Ŭ���� ������ ȣ��!");
		this.brand = brand;
		this.color = color;
		this.price = price;
		this.pass = pass;
	}
//	Car(String brand, String color, int price, int pass){
//		System.out.println("Car Ŭ���� ������ ȣ��!");
//		this.brand=brand;
//		this.color=color;
//		this.price=price;
//	}
	void enginStart() {
		if(isStart) { //boolean Ÿ���� ���� ==�� �� �ʿ䰡 ����.
			System.out.println("�̹� �õ��� ���� �ֽ��ϴ�.");
		}else {
			if(checkPass());
			else return;
			System.out.println(brand+" �õ� �ѱ�");
			isStart = true;
		}
	}
	void enginStop() {
		if(isStart) {
			System.out.println(brand+" �õ� ����");
			isStart = false;
		}else {
			System.out.println("�̹� �õ��� ���� �ֽ��ϴ�.");
		}
	}
	boolean checkPass() {
		System.out.println("��й�ȣ�� �Է��ϼ���.: ");
		if(new Scanner(System.in).nextInt() == pass) {
			System.out.println("�ݰ����ϴ�.");
			return true;
		}else {
			System.out.println("��й�ȣ�� Ʋ�Ƚ��ϴ�.");
//			checkPass(); //���ȣ���ص� �ɵ�
			return false;
		}	
	}
}