package day02;

public class VariableTask {
	public static void main(String[] args) {
		//===ȸ������===
		//�̸�	: 000
		//Ű		: 182.24cm
		//������	: 75.26kg
		//����	: 'A'
		String name = "ȫ�浿";
		float height = 182.24f;
		float weight = 75.26f;
		char score = 'A';
		System.out.println("===ȸ������====");
//		System.out.printf("�̸�\t: %s\n", name);
//		System.out.printf("Ű\t: %.2fcm\n", height);
//		System.out.printf("������\t: %.2fkg\n", weight);
//		System.out.printf("����\t: '%c'\n", score);
		System.out.println("�̸�\t: "+name); //�����ϱ�
		System.out.println("Ű\t: "+height+"cm");
		System.out.println("������\t: "+weight+"kg");
		System.out.println("����\t: \'"+score+"\'");
		//�߿�! �� ����� ���� �־��� ����ŭ ������ �������ٰ� ��.
			
		//Tip: ���� ���� ���� ���Ű 3��!
		//Ctrl+Alt+��(��) : ��(�Ʒ�)�� ���� ����
		//Alt+��(��): ��(�Ʒ�)�� �� �� �̵�
		//Ctrl+Space
	}
}
