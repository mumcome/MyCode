#include <windows.h>
#include<iostream>
DWORD WINAPI ThreadFun3(LPVOID lpThreadParament);
//VOID WINAPI ExitThread(	_In_ DWORD dwExitCode);
//WINBASEAPI BOOL WINAPI TerminateThread(	_In_ HANDLE hThread,	_In_ DWORD dwExitCode);
//TerminateThread();
//BOOL WINAPI GetExitCodeThread( 	_In_ HANDLE hThread,	_Out_ LPDWORD lpExitCode);
//WaitForMultipleObjects( _In_ DWORD nCount, _In_reads_(nCount) CONST HANDLE* lpHandles, _In_ BOOL bWaitAll, _In_ DWORD dwMilliseconds )
int main()
{
	std::cout << "主线程开始" << std::endl;
	DWORD CreatedMainThreadID = 0;
	DWORD ExitCode = 0;
	//std::cout << "主线程开始" << std::endl;
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun3, (void*)"Thread01", 0, &CreatedMainThreadID);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun3, (void*)"Thread02", 0, &CreatedMainThreadID);
	HANDLE hThread3 = CreateThread(NULL, 0, ThreadFun3, (void*)"Thread03", 0, &CreatedMainThreadID);
	HANDLE hHandleArray[]{ hThread1 ,hThread2,hThread3 };
	//无限等待所有进程结束
//	DWORD Ret = WaitForMultipleObjects(3, hHandleArray, true, INFINITE);
		//无限等待任意进程结束
	DWORD Ret = WaitForMultipleObjects(3, hHandleArray, false, INFINITE);
	std::cout << Ret << std::endl;

 	return 0;
	//STILL_ACTIVE
}
DWORD WINAPI ThreadFun3(LPVOID lpThreadParament)
{
	int n = 0;
	while (++n < 6)
	{
		
		if (strcmp("Thread01", (char *)lpThreadParament))
		{std::cout << n << (char *)lpThreadParament << std::endl;
			Sleep(1000);
		}
		else if (strcmp("Thread02", (char *)lpThreadParament))
		{
			std::cout << n << (char *)lpThreadParament << std::endl;
 			Sleep(6000);
		}
		else  if (strcmp("Thread03", (char *)lpThreadParament))
		{
			std::cout << n << (char *)lpThreadParament << std::endl;
		 	 Sleep(9000);
		}

		
		//  		if (n==3)
		//  		{
		//  			ExitThread(666);
		//  		}
	}
	return 0;
}