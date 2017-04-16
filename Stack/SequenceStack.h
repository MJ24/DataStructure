// ջ��ʵ���� --> ��������ʵ�ֵ�ջ

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
			cout << "ջ������" << endl;
			return;
		}
		data[++top] = elem;
	}

	ElemType pop() override
	{
		ElemType elem;
		if (empty())
		{
			cout << "ջΪ�գ�" << endl;
			return ElemType();
		}
		elem = data[top--];
		return elem;
	}

	ElemType& locate(int index) const override
	{
		// index��飬�ǿռ����Թ�
		return data[index];
	}
private:
	ElemType *data;
	int maxSize;
	int top;
};
#endif