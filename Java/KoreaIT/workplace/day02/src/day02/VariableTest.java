package day02;

public class VariableTest {
	public static void main(String[] args) {
		int data = 100;
		//�ݺ����� �����͸� brutal force�� �ݺ��ϴ°� �������� ������ ������
		//�ݺ����� �̿��ϸ� �������� ��������.
//		float f = 10.2778; //�Ǽ����� �̷��� ������ �� ����. ����.
		//10.2778 > �̰Ŵ� double�� �ǹ�
		float f = 10.2778f;
//		float f = 10.2778F; //�̰͵� ��������.
		double d = -12.147;
		char c = 'a';
//		char s = "Hello";
		String s = "Hello"; //�⺻����
		
		System.out.printf("%d\n", data);
		System.out.printf("f ������ ����ִ� ��: %f\n", f);
		System.out.printf("d : %f\nc : %c\n", d, c);
		
	}
}
