#include <iostream>
#include <windows.h>
#include <process.h>

void SellThread10_1(void* Param);
void SellThread10_2(void* Param);
static int ticket{ 100 };
HANDLE hEvent{ INVALID_HANDLE_VALUE };

int main()
{
	//��ʼ���ٽ�����Դ
	//InitializeCriticalSection(&Section);
	//����ΪEvent

	hEvent = CreateEvent(NULL, false, true,"�ֶ��¼�");
	//hEvent = CreateEvent(NULL, false, false,"�ֶ��¼�");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		std::cout << "�����ظ���";
		getchar();
		return 0;
	}
	std::cout << "��Ʊ��ʼ" << std::endl;
	uintptr_t t1 = _beginthread(SellThread10_1, 0, NULL);
	uintptr_t t2 = _beginthread(SellThread10_2, 0, NULL);
	HANDLE hArray[]{ (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "��Ʊ����" << std::endl;
	//ɾ���ٽ�����Դ
	//DeleteCriticalSection(&Section);
	CloseHandle(hEvent);
	getchar();
	return 0;
}


void SellThread10_1(void* Param)
{
	//���������û���߳�ӵ�У�Ϊ���ź�״̬���������ִ��

	while (ticket > 0)
	{
		//���øú������¼��źŶ������̱�Ϊ���ź�
		WaitForSingleObject(hEvent, INFINITE);
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
		SetEvent(hEvent);
	}


}
void SellThread10_2(void* Param)
{
	//���������û���߳�ӵ�У�Ϊ���ź�״̬���������ִ��

	while (ticket > 0)
	{
		//���øú������¼��źŶ������̱�Ϊ���ź�
		WaitForSingleObject(hEvent, INFINITE);
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
			//hEvent = CreateEvent(NULL, false, false,"�ֶ��¼�");
		}
		//}
		SetEvent(hEvent);
	}


}