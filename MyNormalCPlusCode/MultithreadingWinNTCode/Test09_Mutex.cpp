#include <iostream>
#include <windows.h>
#include <process.h>
//�ٽ����ṹ��s
//CRITICAL_SECTION Section;
void SellThread9_1(void* Param);
void SellThread9_2(void* Param);
static int ticket{ 100 };
HANDLE hMutex{INVALID_HANDLE_VALUE};

int main9()
{
	//��ʼ���ٽ�����Դ
	//InitializeCriticalSection(&Section);
	//����ΪMutex
	
	hMutex = CreateMutex(NULL,false,"������");
	if (GetLastError()==ERROR_ALREADY_EXISTS)
	{
		std::cout << "�����ظ���";
		getchar();
		return 0;
	}
	std::cout << "��Ʊ��ʼ" << std::endl;
	uintptr_t t1 = _beginthread(SellThread9_1, 0, NULL);
	uintptr_t t2 = _beginthread(SellThread9_2, 0, NULL);
	HANDLE hArray[]{ (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "��Ʊ����" << std::endl;
	//ɾ���ٽ�����Դ
	//DeleteCriticalSection(&Section);
	getchar();
	return 0;
}


void SellThread9_1(void* Param)
{
	//���������û���߳�ӵ�У�Ϊ���ź�״̬���������ִ��
	
	while (ticket > 0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		//�����ٽ���
		//EnterCriticalSection(&Section);
		//���Խ����ٽ�����������������
		//if (TryEnterCriticalSection(&Section))
	//	{
		if (ticket > 0)
		{



			Sleep(10);
			std::cout << "����1����" << ticket-- << std::endl;
			//�뿪�ٽ���
			//LeaveCriticalSection(&Section);

		}
		//}
		ReleaseMutex(hMutex);
	}


}
void SellThread9_2(void* Param)
{
	//���������û���߳�ӵ�У�Ϊ���ź�״̬���������ִ��
	
	while (ticket > 0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		//�����ٽ���
		//EnterCriticalSection(&Section);
		//���Խ����ٽ�����������������
		//if (TryEnterCriticalSection(&Section))
	//	{
			if (ticket > 0)
			{



				Sleep(10);
				std::cout << "����2����" << ticket-- << std::endl;
				//�뿪�ٽ���
				//LeaveCriticalSection(&Section);
				
			}
		//}
			ReleaseMutex(hMutex);
	}


}