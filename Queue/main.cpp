#include <iostream>
#include "QueueBase.h"
#include "SequenceQueue.h"
#include "LinkQueue.h"
using namespace std;

void testIntQueue(QueueBase<int> &iqb)
{
	iqb.popFront();
	cout << iqb.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		iqb.pushBack(i);
	}
	iqb.print();
	cout << iqb.size() << endl;
	cout << iqb.popFront() << endl;
	cout << iqb.popFront() << endl;
	iqb.print();
	cout << iqb.size() << endl;
}

int main()
{
	SequenceQueue<int> isq;
	QueueBase<int> &iqb = isq;
	cout << "********  By SequenceQueue:  ********\n";
	testIntQueue(iqb);

	LinkQueue<int> ilq;
	QueueBase<int> &iqb2 = ilq;
	cout << "********  By LinkQueue:  ********\n";
	testIntQueue(iqb2);
	system("pause");
	return 0;
}