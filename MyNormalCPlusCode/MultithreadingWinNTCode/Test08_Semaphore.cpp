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
	hSemaphore=CreateSemaphore(NULL, 3, 3, "ͣ��λ");
	if (GetLastError() == ERROR_ALREADY_EXISTS)//�����ظ�������ʵ�ֽ��̻���
	{
		std::cout <<  "�����ظ�����"  << std::endl;
		getchar();
		CloseHandle(hSemaphore);
		return false;
	}
	HANDLE hArray[5]{INVALID_HANDLE_VALUE};
	for (int i = 0; i < 5; ++i)
	{
		Car *pCar = new Car;
		strcpy_s(pCar->name,"����");
		pCar->name[4]=(char)('A' + i)  ;
		pCar->name[5] = ('\0');
		pCar->time = 3 + i * 2000;
		std::cout << pCar->name<<"�����߳�" << i << std::endl;
		hArray[i] = (HANDLE)_beginthread(ThreadFun8_1, 0,pCar);
	//	Sleep(pCar->time);
	}
	
	
	WaitForMultipleObjects(2, hArray, true, INFINITE);

	getchar();
	return 0;
}
void ThreadFun8_1(void* Param)
{
	//���ͣ��λ��Դʣ�ࣨ���ź�״̬�����ͷ��С�
	WaitForSingleObject(hSemaphore, INFINITE);
	Car*pCar = (Car*)Param;
	std::cout << pCar->name << "����ͣ����ͣ��" <<pCar->time <<std::endl;
	Sleep(pCar->time);
	std::cout << pCar->name << "�뿪ͣ����"  << std::endl;
	//�ͷ�һ��ͣ��λ
	ReleaseSemaphore(hSemaphore, 1, NULL);
}

void ThreadFun8_2(void* Param)
{

	


}