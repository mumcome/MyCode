#include <windows.h>
#include<iostream>
DWORD WINAPI ThreadFun2(LPVOID lpThreadParament);
//VOID WINAPI ExitThread(	_In_ DWORD dwExitCode);
//WINBASEAPI BOOL WINAPI TerminateThread(	_In_ HANDLE hThread,	_In_ DWORD dwExitCode);
//TerminateThread();
//BOOL WINAPI GetExitCodeThread( 	_In_ HANDLE hThread,	_Out_ LPDWORD lpExitCode);
int main()
{
	std::cout << "���߳̿�ʼ" << std::endl;
	DWORD CreatedMainThreadID = 0;
	DWORD ExitCode = 0;
	HANDLE hThread = CreateThread(NULL, 0, ThreadFun2, (void*)"hello,test02",0, &CreatedMainThreadID);
	std::cout << "���߳̽���" << std::endl;
	GetExitCodeThread(hThread, &ExitCode);
	std::cout << "ǰWaitForSingleObject" << ExitCode << std::endl;
	if (ExitCode==STILL_ACTIVE)
	{
		std::cout << "STILL_ACTIVE"  << std::endl;
	}
	WaitForSingleObject(hThread, INFINITE);
	//getchar();
	GetExitCodeThread(hThread, &ExitCode);
	std::cout <<"��WaitForSingleObject"<< ExitCode<<std::endl;
	return 0;
	//STILL_ACTIVE
}
DWORD WINAPI ThreadFun2(LPVOID lpThreadParament)
{
	int n = 0;
	while (++n<6)
	{
		std::cout <<n<< "���߳�hello" << std::endl;
		Sleep(1000);
 		if (n==3)
 		{
 			ExitThread(666);
 		}
	}
	return 0;
}