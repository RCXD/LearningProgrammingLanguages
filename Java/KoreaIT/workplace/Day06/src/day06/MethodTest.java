package day06;

public class MethodTest {
	public static void main(String[] args) {
		//��Ģ���� ������, for������ ���� ��Ȳ�� ó���ϱ� ��ƴ�.
		
		MethodTest m = new MethodTest();
		System.out.println(m.f(3)); //f�� ���ǵ� Ŭ������ ��ü�� �����, ��ü�� �޼ҵ�� �ҷ��;� ��� ����.
		
		System.out.println("������");
		m.print99(3); //�Լ��� ���ٴ�� ���ϰ��� �ٷ� �� �� �ִ�.
		System.out.println(m.plus(10, 5));
	}
	//f(x) = 2x+1
	//������ ������ �� Ȯ���ؼ� ȣ���ؾ� �Ѵ�.
	int f(int x) { //main�� f�� �ٸ� ������ ���ǵǾ� �ִٴ����� ����.
		return 2*x+1;
	}
	//������ ��� �޼ҵ�
	void print99(int dan) {
		for (int i = 1; i < 10; i++) {
			System.out.println(dan+" X "+i+" = "+i*dan);
		}
	}
	//�� ������ ���� �޼ҵ�
	int plus(int num1, int num2) {
		int result = num1+num2;
		System.out.println("�� ������ ���� �޼ҵ��Դϴ�."); //������µ� �ٲٰ���� ���� �ִ�. ���� �̷� ������ ������ �ִ°� ����.
		return result;
	}
}
