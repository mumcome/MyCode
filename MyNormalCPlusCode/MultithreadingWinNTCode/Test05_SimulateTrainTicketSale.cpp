#include <iostream>
#include <windows.h>
#include <process.h>

void SellThread1(void* Param);
void SellThread2(void* Param);
int ticket{ 100 };


int main5()
{
	std::cout << "��Ʊ��ʼ" << std::endl;
	uintptr_t t1=_beginthread(SellThread1,0,NULL);
	uintptr_t t2=_beginthread(SellThread2, 0, NULL);
	HANDLE hArray[]{(HANDLE)t1,(HANDLE)t2};
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "��Ʊ����" << std::endl;
	//ɾ���ٽ�����Դ
	getchar();
	return 0;
}
void SellThread2(void* Param)
{
	
	
	while (ticket >0)
	{
		
		
				Sleep(10);
		std::cout <<"����2����"<< ticket-- << std::endl;
	}


}

void SellThread1(void* Param)
{

	while (ticket > 0)
	{
	
			Sleep(12);
			std::cout << "����1����" << ticket-- << std::endl;
			//�뿪�ٽ���
	
	}

}