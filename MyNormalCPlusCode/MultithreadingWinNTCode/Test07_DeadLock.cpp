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
	std::cout << "�߳�1������1������Ϣ��3��" << std::endl;
	Sleep(3000);
	std::cout << "�߳�1�������2����" << std::endl;
	EnterCriticalSection(&cs2);
	std::cout << "�߳�1������2����" << std::endl;
	LeaveCriticalSection(&cs2);
	std::cout << "�߳�1�뿪��2����" << std::endl;
	LeaveCriticalSection(&cs1);
	std::cout << "�߳�1�뿪��1����" << std::endl;

}

void ThreadFun7_2(void* Param)
{

	EnterCriticalSection(&cs2);
	std::cout << "�߳�2������2����" << std::endl;
	Sleep(3000);
	std::cout << "�߳�2�������1����" << std::endl;
	EnterCriticalSection(&cs1);
	std::cout << "�߳�2������1����" << std::endl;
	LeaveCriticalSection(&cs1);
	std::cout << "�߳�2�뿪��1����" << std::endl;
	LeaveCriticalSection(&cs2);
	std::cout << "�߳�2�뿪��2����" << std::endl;


}