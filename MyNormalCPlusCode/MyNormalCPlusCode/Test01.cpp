#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFun(
	LPVOID lpThreadParameter
	);
//DWORD WINAPI GetCurrentThreadid();//返回当前线程ID
int main()
{
	DWORD threadID= 0;
	HANDLE Threadhandle= CreateThread(NULL,//如果为NULL为默认安全性
		0,//线程栈的大小
		ThreadFun,//线程处理函数
		(void*)"hello",//向线程函数传入参数
	0,//创建后立即运行
	&threadID);
	if (Threadhandle==NULL)
	{
		std::cout<<"线程创建失败" << GetLastError()<<std::endl;
	}
	else
	{
		std::cout << "线程创建句柄" << Threadhandle << std::endl;
		std::cout << "线程创建ID" << threadID << std::endl;
	}
	std::cout << "主线程id" << GetCurrentThreadId() << std::endl;
	getchar();
	return 0;
}
DWORD WINAPI ThreadFun(	LPVOID lpThreadParameter) 
{
	char*str = (char*)lpThreadParameter;
	std::cout << "线程处理函数"<<str << std::endl;
	std::cout << "子线程id" << GetCurrentThreadId() << std::endl;
	return 0;
}