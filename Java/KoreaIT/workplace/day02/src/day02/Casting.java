package day02;

public class Casting {
	public static void main(String[] args) {
//		System.out.println(10/3);
//		System.out.println((10+0.0)/3); //�ڵ����� float������ ��ȯ�ȴ�. ���������� �����
		System.out.println(10*1.0/3); //������� ������ �̰͵� ����. �׷��� �ᱹ double������ �ٲ�� ����
		System.out.println('A'+5); //�̰� ���� C���� �ȵǴ°Ű��Ҵµ�... �Ƹ�?
			//ASCII �ڵ�ǥ ����. 'A'+5 == 'F'
			//�ڵ� ����ȯ�̶� �ϱ� ���� �ָ��غ�������, �ƹ�ư.
		System.out.println((int)10.24784); //�Ҽ��� �Ұ�
		System.out.println((int)'a'); //ASCII�� ��ȯ
		
		//����ȯ �������� �켱������ ��� �������� �켱�������� ����.
		System.out.println((int)(8.43+2.59)); //��ȣ�� �Ⱦ��� 8+2.59 > 10.59�� ����.
	}
}
