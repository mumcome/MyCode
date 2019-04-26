#include <windows.h>
#include<iostream>
DWORD WINAPI ThreadFun2(LPVOID lpThreadParament);
//VOID WINAPI ExitThread(	_In_ DWORD dwExitCode);
//WINBASEAPI BOOL WINAPI TerminateThread(	_In_ HANDLE hThread,	_In_ DWORD dwExitCode);
//TerminateThread();
//BOOL WINAPI GetExitCodeThread( 	_In_ HANDLE hThread,	_Out_ LPDWORD lpExitCode);
//WaitForMultipleObjects( _In_ DWORD nCount, _In_reads_(nCount) CONST HANDLE* lpHandles, _In_ BOOL bWaitAll, _In_ DWORD dwMilliseconds )
int main2()
{
	std::cout << "主线程开始" << std::endl;
	DWORD CreatedMainThreadID = 0;
	DWORD ExitCode = 0;
	HANDLE hThread = CreateThread(NULL, 0, ThreadFun2, (void*)"hello,test02",0, &CreatedMainThreadID);
	std::cout << "主线程结束" << std::endl;
	GetExitCodeThread(hThread, &ExitCode);
	std::cout << "前WaitForSingleObject" << ExitCode << std::endl;
	if (ExitCode==STILL_ACTIVE)
	{
		std::cout << STILL_ACTIVE << "子线程还在运行STILL_ACTIVE"  << std::endl;
	}
	DWORD Ret=WaitForSingleObject(hThread, 5000);
	if (Ret==WAIT_TIMEOUT)
	{
		std::cout << "等待子线程退出超时" << std::endl;
	}
	//getchar();
	DWORD A=TerminateThread(hThread,888);
	GetExitCodeThread(hThread, &ExitCode);
	if (ExitCode==666)
	{
		std::cout <<  "子线程被ExitThread(666)强制结束" << std::endl;
	}
	if (ExitCode == 888)
	{
		std::cout << "子线程被TerminateThread888强制结束" << std::endl;
	}
	std::cout <<"后WaitForSingleObject"<< ExitCode<<std::endl;
	return 0;
	//STILL_ACTIVE
}
DWORD WINAPI ThreadFun2(LPVOID lpThreadParament)
{
	int n = 0;
	while (++n<6)
	{
		std::cout <<n<< "子线程hello" << std::endl;
		Sleep(1000);
//  		if (n==3)
//  		{
//  			ExitThread(666);
//  		}
	}
	return 0;
}