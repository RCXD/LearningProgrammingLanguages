#include<iostream>
using namespace std;
int sum(int x, int y);
void display(int result);
int main()
{

	int num1, num2;
	cout << "Enter two number: ";
	cin >> num1 >> num2;
	int result = sum(num1, num2);
	display(result);

	return 0;
}