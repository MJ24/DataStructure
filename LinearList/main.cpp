#include <iostream>
#include "LinearListBase.h"
#include "SequenceListByArray.h"
using namespace std;

template <typename ElemType>
void printList(const LinearListBase<ElemType> &ll);
void testIntLl(LinearListBase<int> &intLl);

int main()
{
	SequenceListByArray<int> intSl;
	LinearListBase<int>& intLl = intSl;
	testIntLl(intSl);
	system("pause");
	return 0;
}

template <typename ElemType>
void printList(const LinearListBase<ElemType> &ll)
{
	for (int i = 0; i < ll.size() - 1; i++)
	{
		cout << ll.locate(i) << ",";
	}
	cout << ll.locate(ll.size() - 1) << endl;
}

void testIntLl(LinearListBase<int> &intLl)
{
	for (int i = 0; i < 10; i++)
	{
		intLl.append(i*i);
	}

	printList<int>(intLl);
	cout << "元素49的index是：" << intLl.find(49) << endl;
	cout << "元素50的index是：" << intLl.find(50) << endl;

	intLl.insert(10, 101);
	intLl.insert(7, 77);
	intLl.insert(-1, -33);
	intLl.insert(999, 999);
	cout << "当前表长：" << intLl.size() << endl;
	printList<int>(intLl);

	intLl.erase(7);
	intLl.erase(10);
	cout << "当前表长：" << intLl.size() << endl;
	printList<int>(intLl);
}