#include <windows.h>
#include <queue>
#include <process.h>
using namespace std;
//有一个仓库
queue <int> store;
int StoreSize = 3;
int ID = 1;//货物起始ID
HANDLE hConsumer;
HANDLE hProdecer;
HANDLE hEvent1=INVALID_HANDLE_VALUE;//有货物时通知消费者取货物
HANDLE hEvent2=INVALID_HANDLE_VALUE;//仓库为空时通知消费者开始生产 
int main()
{

	hProdecer=(HANDLE)_beginthread(ProducerThread,0,NULL);
	hConsumer = (HANDLE)_beginthread(ConsumerThread, 0, NULL);







	return 0;
}

void ConsumerThread(LPVOID param)
{
}
//生产者
void ProducerThread(LPVOID param)
{

}
