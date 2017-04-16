#include <iostream>
#include "StackBase.h"
#include "SequenceStack.h"
#include "LinkStack.h"
using namespace std;

template <typename ElemType>
void printStack(const StackBase<ElemType> &sb)
{
	for (int i = 0; i < sb.size() - 1; i++)
	{
		cout << sb.locate(i) << ",";
	}
	cout << sb.locate(sb.size() - 1) << endl;
}

void testIntStack(StackBase<int> &isb)
{
	isb.pop();
	cout << isb.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		isb.push(i);
	}
	printStack(isb);
	cout << isb.size() << endl;
	cout << isb.pop() << endl;
	cout << isb.pop() << endl;
	printStack(isb);
	cout << isb.size() << endl;
}

int main()
{
	SequenceStack<int> iss;
	StackBase<int> &isb = iss;
	testIntStack(isb);

	LinkStack<int> ils;
	StackBase<int> &isb2 = ils;
	testIntStack(isb2);
	system("pause");
	return 0;
}