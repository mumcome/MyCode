#include <iostream>
#include <windows.h>
#include <process.h>
//临界区结构体s
CRITICAL_SECTION Section;
void SellThread3(void* Param);
void SellThread4(void* Param);
static int ticket{ 100 };


int main6()
{
	//初始化临界区资源
	InitializeCriticalSection(&Section);
	std::cout << "售票开始" << std::endl;
	uintptr_t t1 = _beginthread(SellThread3, 0, NULL);
	uintptr_t t2 = _beginthread(SellThread4, 0, NULL);
	HANDLE hArray[]{ (HANDLE)t1,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "售票结束" << std::endl;
	//删除临界区资源
	DeleteCriticalSection(&Section);
	getchar();
	return 0;
}
void SellThread4(void* Param)
{


	while (ticket > 0)
	{
		//进入临界区
		//EnterCriticalSection(&Section);
		//尝试进入临界区，不会阻塞进程
		if (TryEnterCriticalSection(&Section))
		{
			if (ticket > 0)
			{



				Sleep(10);
				std::cout << "窗口2卖出" << ticket-- << std::endl;
				//离开临界区
				LeaveCriticalSection(&Section);

			}
		}

	}


}

void SellThread3(void* Param)
{

	while (ticket > 0)
	{
		//进入临界区
	//	EnterCriticalSection(&Section);
		//尝试进入临界区，不会阻塞进程
		if (TryEnterCriticalSection(&Section))
		{
			if (ticket > 0)
			{



				Sleep(10);
				std::cout << "窗口1卖出" << ticket-- << std::endl;
				//离开临界区
				LeaveCriticalSection(&Section);

			}
		}

	}

}