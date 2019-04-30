#include <iostream>
#include <windows.h>
#include <process.h>

void SellThread10_1(void* Param);
void SellThread10_2(void* Param);
static int ticket{ 100 };
HANDLE hEvent{ INVALID_HANDLE_VALUE };

int main()
{
	//初始化临界区资源
	//InitializeCriticalSection(&Section);
	//更换为Event

	hEvent = CreateEvent(NULL, false, true,"手动事件");
	//hEvent = CreateEvent(NULL, false, false,"手动事件");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		std::cout << "程序重复打开";
		getchar();
		return 0;
	}
	std::cout << "售票开始" << std::endl;
	uintptr_t t1 = _beginthread(SellThread10_1, 0, NULL);
	uintptr_t t2 = _beginthread(SellThread10_2, 0, NULL);
	HANDLE hArray[]{ (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "售票结束" << std::endl;
	//删除临界区资源
	//DeleteCriticalSection(&Section);
	CloseHandle(hEvent);
	getchar();
	return 0;
}


void SellThread10_1(void* Param)
{
	//如果互斥体没有线程拥有（为有信号状态），则继续执行

	while (ticket > 0)
	{
		//调用该函数，事件信号对象立刻变为无信号
		WaitForSingleObject(hEvent, INFINITE);
		//进入临界区
		//EnterCriticalSection(&Section);
		//尝试进入临界区，不会阻塞进程
		//if (TryEnterCriticalSection(&Section))
	//	{
		if (ticket > 0)
		{



			Sleep(10);
			std::cout << "窗口1卖出" << ticket-- << std::endl;
			//离开临界区
			//LeaveCriticalSection(&Section);

		}
		//}
		SetEvent(hEvent);
	}


}
void SellThread10_2(void* Param)
{
	//如果互斥体没有线程拥有（为有信号状态），则继续执行

	while (ticket > 0)
	{
		//调用该函数，事件信号对象立刻变为无信号
		WaitForSingleObject(hEvent, INFINITE);
		//进入临界区
		//EnterCriticalSection(&Section);
		//尝试进入临界区，不会阻塞进程
		//if (TryEnterCriticalSection(&Section))
	//	{
		if (ticket > 0)
		{



			Sleep(10);
			std::cout << "窗口2卖出" << ticket-- << std::endl;
			//离开临界区
			//LeaveCriticalSection(&Section);
			//hEvent = CreateEvent(NULL, false, false,"手动事件");
		}
		//}
		SetEvent(hEvent);
	}


}