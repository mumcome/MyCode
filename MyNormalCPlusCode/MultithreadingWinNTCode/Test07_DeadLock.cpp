#include <iostream>
#include <windows.h>
#include <process.h>

void ThreadFun7_1(void* Param);
void ThreadFun7_2(void* Param);
static int ticket{ 100 };
CRITICAL_SECTION cs1;
CRITICAL_SECTION cs2;
int main7()
{
	InitializeCriticalSection(&cs1);
	InitializeCriticalSection(&cs2);
	uintptr_t Thread7_1= _beginthread(ThreadFun7_1, 0, NULL);
	uintptr_t Thread7_2= _beginthread(ThreadFun7_2, 0, NULL);
	HANDLE hHandleArray[]{ (HANDLE)Thread7_1 ,(HANDLE)Thread7_2 };
	WaitForMultipleObjects(2, hHandleArray,true, INFINITE);

	getchar();
	return 0;
}
void ThreadFun7_1(void* Param)
{


	EnterCriticalSection(&cs1);
	std::cout << "线程1进入了1区域，休息了3秒" << std::endl;
	Sleep(3000);
	std::cout << "线程1想进入了2区域" << std::endl;
	EnterCriticalSection(&cs2);
	std::cout << "线程1进入了2区域" << std::endl;
	LeaveCriticalSection(&cs2);
	std::cout << "线程1离开了2区域" << std::endl;
	LeaveCriticalSection(&cs1);
	std::cout << "线程1离开了1区域" << std::endl;

}

void ThreadFun7_2(void* Param)
{

	EnterCriticalSection(&cs2);
	std::cout << "线程2进入了2区域" << std::endl;
	Sleep(3000);
	std::cout << "线程2想进入了1区域" << std::endl;
	EnterCriticalSection(&cs1);
	std::cout << "线程2进入了1区域" << std::endl;
	LeaveCriticalSection(&cs1);
	std::cout << "线程2离开了1区域" << std::endl;
	LeaveCriticalSection(&cs2);
	std::cout << "线程2离开了2区域" << std::endl;


}