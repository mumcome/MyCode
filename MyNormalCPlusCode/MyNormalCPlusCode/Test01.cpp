#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFun(
	LPVOID lpThreadParameter
	);
int main()
{
	DWORD threadID= 0;
	HANDLE Threadhandle= CreateThread(NULL,//���ΪNULLΪĬ�ϰ�ȫ��
		0,//�߳�ջ�Ĵ�С
		ThreadFun,//�̴߳�����
		"hello",//���̺߳����������
	0,//��������������
	& threadID);
	if (Threadhandle==NULL)
	{
		std::cout<<"�̴߳���ʧ��" << GetLastError();
	}
	return 0;
}