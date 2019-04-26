#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}
int main()
{
	int a{ 99 };
	int b{ 1000 };
	cout << "交换前a为" << a << "交换前b为" << b<<endl;
	swap(a, b);
	cout << "交换后a为" << a << "交换后b为" << b<<endl;
	system("pause");
	return 0;
}