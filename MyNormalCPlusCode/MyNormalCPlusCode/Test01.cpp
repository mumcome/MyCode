#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFun(
	LPVOID lpThreadParameter
	);
int main()
{
	DWORD threadID= 0;
	HANDLE Threadhandle= CreateThread(NULL,//如果为NULL为默认安全性
		0,//线程栈的大小
		ThreadFun,//线程处理函数
		"hello",//向线程函数传入参数
	0,//创建后立即运行
	& threadID);
	if (Threadhandle==NULL)
	{
		std::cout<<"线程创建失败" << GetLastError();
	}
	return 0;
}