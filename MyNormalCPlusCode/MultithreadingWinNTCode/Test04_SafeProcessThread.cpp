#include<iostream>
#include<process.h>
#include <windows.h>
//uintptr_t __cdecl _beginthread(	_In_  _beginthread_proc_type _StartAddress,	_In_   unsigned  _StackSize,_In_opt_ void* _ArgList);
//_endthread()
void  ThreadFun4(
	void* lpThreadParameter
);

int main4()
{
	std::cout << "主线程开始" << std::endl;
//	DWORD threadID = 0;
	HANDLE hThread= (HANDLE)_beginthread(ThreadFun4, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
	std::cout << "主线程结束" << std::endl;
	getchar();
	return 0;
	}
	
void  ThreadFun4(void* lpThreadParameter)
{
	std::cout << "子线程开始"  << std::endl;
	for (int i=0;i<=6;++i)
	{
		std::cout << i << std::endl;
		Sleep(1000);
		if (i==3)
		{
			_endthread();
		}
	}
	std::cout << "子线程结束" << std::endl;
//	return 0;
}