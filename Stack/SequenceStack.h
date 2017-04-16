// 栈的实现类 --> 泛型数组实现的栈

#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H
#include "StackBase.h"

template <typename ElemType>
class SequenceStack :public StackBase < ElemType >
{
public:
	SequenceStack(int mSize = 20)
	{
		maxSize = mSize;
		data = new ElemType[maxSize];
		top = -1;
	}

	int size() const override { return top + 1; }

	bool empty() const override { return top == -1; }

	void push(const ElemType &elem) override
	{
		if (top == maxSize - 1)
		{
			cout << "栈已满！" << endl;
			return;
		}
		data[++top] = elem;
	}

	ElemType pop() override
	{
		ElemType elem;
		if (empty())
		{
			cout << "栈为空！" << endl;
			return ElemType();
		}
		elem = data[top--];
		return elem;
	}

	ElemType& locate(int index) const override
	{
		// index检查，非空检查等略过
		return data[index];
	}
private:
	ElemType *data;
	int maxSize;
	int top;
};
#endif