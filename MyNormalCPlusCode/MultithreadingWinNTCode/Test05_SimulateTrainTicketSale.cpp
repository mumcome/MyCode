#include <iostream>
#include <windows.h>
#include <process.h>

void SellThread1(void* Param);
void SellThread2(void* Param);
int ticket{ 100 };


int main5()
{
	std::cout << "售票开始" << std::endl;
	uintptr_t t1=_beginthread(SellThread1,0,NULL);
	uintptr_t t2=_beginthread(SellThread2, 0, NULL);
	HANDLE hArray[]{(HANDLE)t1,(HANDLE)t2};
	WaitForMultipleObjects(2, hArray, true, INFINITE);
	std::cout << "售票结束" << std::endl;
	//删除临界区资源
	getchar();
	return 0;
}
void SellThread2(void* Param)
{
	
	
	while (ticket >0)
	{
		
		
				Sleep(10);
		std::cout <<"窗口2卖出"<< ticket-- << std::endl;
	}


}

void SellThread1(void* Param)
{

	while (ticket > 0)
	{
	
			Sleep(12);
			std::cout << "窗口1卖出" << ticket-- << std::endl;
			//离开临界区
	
	}

}