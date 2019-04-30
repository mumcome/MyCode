#include <iostream>
#include <windows.h>
#include <process.h>
#include <string.h>
void ThreadFun8_1(void* Param);
void ThreadFun8_2(void* Param);

//HANDLE WINAPI CreateSemaphoreA(_In_opt_ LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, _In_ LONG lInitialCount, _In_ LONG lMaximumCount, _In_opt_ LPCSTR lpName)
//WINBASEAPI BOOL WINAPI ReleaseSemaphore(_In_ HANDLE hSemaphore, _In_ LONG lReleaseCount, _Out_opt_ LPLONG lpPreviousCount)
HANDLE hSemaphore = INVALID_HANDLE_VALUE;
class Car
{
public:
	char name[20];
	int time;
protected:
private:
};
int main8()
{
	hSemaphore=CreateSemaphore(NULL, 3, 3, "停车位");
	if (GetLastError() == ERROR_ALREADY_EXISTS)//程序重复启动，实现进程互斥
	{
		std::cout <<  "程序重复启动"  << std::endl;
		getchar();
		CloseHandle(hSemaphore);
		return false;
	}
	HANDLE hArray[5]{INVALID_HANDLE_VALUE};
	for (int i = 0; i < 5; ++i)
	{
		Car *pCar = new Car;
		strcpy_s(pCar->name,"车辆");
		pCar->name[4]=(char)('A' + i)  ;
		pCar->name[5] = ('\0');
		pCar->time = 3 + i * 2000;
		std::cout << pCar->name<<"创建线程" << i << std::endl;
		hArray[i] = (HANDLE)_beginthread(ThreadFun8_1, 0,pCar);
	//	Sleep(pCar->time);
	}
	
	
	WaitForMultipleObjects(2, hArray, true, INFINITE);

	getchar();
	return 0;
}
void ThreadFun8_1(void* Param)
{
	//如果停车位资源剩余（有信号状态），就放行。
	WaitForSingleObject(hSemaphore, INFINITE);
	Car*pCar = (Car*)Param;
	std::cout << pCar->name << "进入停车场停车" <<pCar->time <<std::endl;
	Sleep(pCar->time);
	std::cout << pCar->name << "离开停车场"  << std::endl;
	//释放一个停车位
	ReleaseSemaphore(hSemaphore, 1, NULL);
}

void ThreadFun8_2(void* Param)
{

	


}