package day07;

//int data3; //Ŭ���� �ۿ��� ������ �� ����.
public class StorageTest {
	int data2; //Ŭ���� ���ο� ����Ǹ� �������� �����̶�� ��.
	static int data3; //Ŭ���� ������ �� �� �ִ� ��������.(��ġ�� �������� ������ġ�̹Ƿ� ȣ������� ������ ���� ����)
	public static void main(String[] args) {
//		int data;
//		System.out.println(data); //�ʱ�ȭ �ȵǾ������� ������.
		//�������� �ʱ�ȭ�� ���� ����� �Ѵ�.
//		System.out.println(data2); //main������ ���������� ������ �� ����. (�Ϲ� �޼ҵ忡���� ���ٰ���)
		//���������� ������ �ƴ϶�, �޸� ������� ��. ������?
		//����: static�� �����͵��� ���� ���� �޸𸮿� �ö󰣴�. data2�� ���������̹Ƿ� ���� �ö����� �ʴ�. 
		//���� static �����Լ������� ���ٺҰ�.
		//�� ��������...
		System.out.println(data3);
	}
	void method() {
		int data = 0;
		System.out.println(data2); //���������� �̻���� ������ �� �ִ�.
	}
}
