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
	cout << "����ǰaΪ" << a << "����ǰbΪ" << b<<endl;
	swap(a, b);
	cout << "������aΪ" << a << "������bΪ" << b<<endl;
	system("pause");
	return 0;
}