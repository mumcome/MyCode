#include <iostream>
#include <windows.h>
#include <process.h>
//�ٽ����ṹ��s
CRITICAL_SECTION Section;
void SellThread3(void* Param);
void SellThread4(void* Param);
static int ticket{ 100 };


int main6()
{
	//��ʼ���ٽ�����Դ
	InitializeCriticalSection(&Section);
	std::cout << "��Ʊ��ʼ" << std::endl;
	uintptr_t t1 = _beginthread(SellThread3, 0, NULL);
	uintptr_t t2 = _beginthread(SellThread4, 0, NULL);
	HANDLE hArray[]{ (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "��Ʊ����" << std::endl;
	//ɾ���ٽ�����Դ
	DeleteCriticalSection(&Section);
	getchar();
	return 0;
}
void SellThread4(void* Param)
{


	while (ticket > 0)
	{
		//�����ٽ���
		//EnterCriticalSection(&Section);
		//���Խ����ٽ�����������������
		if (TryEnterCriticalSection(&Section))
		{
			if (ticket > 0)
			{



				Sleep(10);
				std::cout << "����2����" << ticket-- << std::endl;
				//�뿪�ٽ���
				LeaveCriticalSection(&Section);

			}
		}

	}


}

void SellThread3(void* Param)
{

	while (ticket > 0)
	{
		//�����ٽ���
	//	EnterCriticalSection(&Section);
		//���Խ����ٽ�����������������
		if (TryEnterCriticalSection(&Section))
		{
			if (ticket > 0)
			{



				Sleep(10);
				std::cout << "����1����" << ticket-- << std::endl;
				//�뿪�ٽ���
				LeaveCriticalSection(&Section);

			}
		}

	}

}