#include<windows.h>
#include<iostream>
DWORD WINAPI ThreadFun1(
	LPVOID lpThreadParameter
	);
//DWORD WINAPI SuspendThread(HANDLE hHandle);
//DWORD WINAPI GetCurrentThreadid();//返回当前线程ID
//DWORD CloseHandle(HANDLE hObject);
//VOID WINAPI Sleep(DWORD dwMilliseconds);
//DWORD WINAPI ResumeThread(	_In_ HANDLE hThread);
//DWORD WINAPI WaitForSingleObject(	_In_ HANDLE hHandle,	_In_ DWORD dwMilliseconds);
int main1()
{
	DWORD threadID= 0;
	HANDLE Threadhandle= CreateThread(NULL,//如果为NULL为默认安全性
		0,//线程栈的大小
		ThreadFun1,//线程处理函数
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
	std::cout << "子线程id" << threadID << std::endl;
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
		std::cout << "线程处理函数" << str << std::endl;
		std::cout << "子线程id" << GetCurrentThreadId() << std::endl;
Sleep(1000);
	}
	
	return 0;
}