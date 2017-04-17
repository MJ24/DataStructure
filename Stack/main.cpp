#include <iostream>
#include "StackBase.h"
#include "SequenceStack.h"
#include "LinkStack.h"
using namespace std;

void testIntStack(StackBase<int> &isb)
{
	isb.pop();
	cout << isb.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		isb.push(i);
	}
	isb.print();
	cout << isb.size() << endl;
	cout << isb.pop() << endl;
	cout << isb.pop() << endl;
	isb.print();
	cout << isb.size() << endl;
}

int main()
{
	SequenceStack<int> iss;
	StackBase<int> &isb = iss;
	cout << "********  By SequenceStack:  ********\n";
	testIntStack(isb);

	LinkStack<int> ils;
	StackBase<int> &isb2 = ils;
	cout << "\n********  By LinkStack:  ********\n";
	testIntStack(isb2);
	system("pause");
	return 0;
}