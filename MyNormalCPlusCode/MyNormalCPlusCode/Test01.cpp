#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFun(
	LPVOID lpThreadParameter
	);
//DWORD WINAPI GetCurrentThreadid();//���ص�ǰ�߳�ID
int main()
{
	DWORD threadID= 0;
	HANDLE Threadhandle= CreateThread(NULL,//���ΪNULLΪĬ�ϰ�ȫ��
		0,//�߳�ջ�Ĵ�С
		ThreadFun,//�̴߳�����
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
	getchar();
	return 0;
}
DWORD WINAPI ThreadFun(	LPVOID lpThreadParameter) 
{
	char*str = (char*)lpThreadParameter;
	std::cout << "�̴߳�����"<<str << std::endl;
	std::cout << "���߳�id" << GetCurrentThreadId() << std::endl;
	return 0;
}