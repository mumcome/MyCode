#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFun1(
	LPVOID lpThreadParameter
	);
//DWORD WINAPI SuspendThread(HANDLE hHandle);
//DWORD WINAPI GetCurrentThreadid();//���ص�ǰ�߳�ID
//DWORD CloseHandle(HANDLE hObject);
//VOID WINAPI Sleep(DWORD dwMilliseconds);
//DWORD WINAPI ResumeThread(	_In_ HANDLE hThread);
//DWORD WINAPI WaitForSingleObject(	_In_ HANDLE hHandle,	_In_ DWORD dwMilliseconds);
int main1()
{
	DWORD threadID= 0;
	HANDLE Threadhandle= CreateThread(NULL,//���ΪNULLΪĬ�ϰ�ȫ��
		0,//�߳�ջ�Ĵ�С
		ThreadFun1,//�̴߳�����
		(void*)"hello",//���̺߳����������
	0,//��������������
	&threadID);
	if (Threadhandle==NULL)
	{
		std::cout<<"�̴߳���ʧ��" << GetLastError()<<std::endl;
	}
	else
	{
		std::cout << "�̴߳������" << Threadhandle << std::endl;
		std::cout << "�̴߳���ID" << threadID << std::endl;
	}
	std::cout << "���߳�id" << GetCurrentThreadId() << std::endl;
	std::cout << "���߳�id" << threadID << std::endl;
	//bool a = CloseHandle(Threadhandle);
	//std::cout<<a;
	while (true)
	{
		getchar();
		SuspendThread(Threadhandle);
		getchar();
		ResumeThread(Threadhandle);
	}

	return 0;
}
DWORD WINAPI ThreadFun1(	LPVOID lpThreadParameter) 
{
	char*str = (char*)lpThreadParameter;
	while (true)
	{
		std::cout << "�̴߳�����" << str << std::endl;
		std::cout << "���߳�id" << GetCurrentThreadId() << std::endl;
Sleep(1000);
	}
	
	return 0;
}