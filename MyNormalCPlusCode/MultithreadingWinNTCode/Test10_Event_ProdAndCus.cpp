#include <windows.h>
#include <queue>
#include <process.h>
using namespace std;
//��һ���ֿ�
queue <int> store;
int StoreSize = 3;
int ID = 1;//������ʼID
HANDLE hConsumer;
HANDLE hProdecer;
HANDLE hEvent1=INVALID_HANDLE_VALUE;//�л���ʱ֪ͨ������ȡ����
HANDLE hEvent2=INVALID_HANDLE_VALUE;//�ֿ�Ϊ��ʱ֪ͨ�����߿�ʼ���� 
int main()
{

	hProdecer=(HANDLE)_beginthread(ProducerThread,0,NULL);
	hConsumer = (HANDLE)_beginthread(ConsumerThread, 0, NULL);







	return 0;
}

void ConsumerThread(LPVOID param)
{
}
//������
void ProducerThread(LPVOID param)
{

}
