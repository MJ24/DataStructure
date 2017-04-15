// ���Ա��ʵ���� --> ��������ʵ�ֵ�˳���

#ifndef SEQUENCELISTBYARRAY_H
#define SEQUENCELISTBYARRAY_H

#include "LinearListBase.h"
using namespace std;

template <typename ElemType>
class SequenceListByArray : public LinearListBase<ElemType>
{
public:
	SequenceListByArray(int mSize = 20)
	{
		maxSize = mSize;
		data = new ElemType[maxSize];
		last = -1;
	}

	int size() const override { return last + 1; }

	bool empty() const override { return last == -1; }

	void clear() override { last = -1; }

	ElemType& locate(int index) const override
	{
		ElemType result;
		if (empty())
		{
			cout << "˳���Ϊ�գ�" << endl;
		}
		else if (index<0 || index>last)
		{
			// ���������һ�����ElemType��int֮���
			// ��returnһ��δ����ֵ��������û��ʲô���������
			cout << "����λ�ô���" << endl;
		}
		else
		{
			result = data[index];
		}
		return result;
	}

	int find(const ElemType &elem) const override
	{
		int index = -1;
		if (empty())
			cout << "˳���Ϊ�գ�" << endl;
		else
		{
			for (int i = 0; i < last; i++)
			{
				if (data[i] == elem)
					return i;
			}
		}
		return index;
	}

	void insert(int index, const ElemType &elem) override
	{
		if (isFull())
			cout << "˳���������" << endl;
		// index = last+1���ʾ����ĩβ
		else if (index<0 || index>last + 1)
			cout << "����Ԫ��λ�ô���" << endl;
		else
		{
			for (int i = last; i >= index; i--)
			{
				data[i + 1] = data[i];
			}
			data[index] = elem;
			++last;
		}
	}

	void erase(int index) override
	{
		if (empty())
			cout << "˳���Ϊ�գ�" << endl;
		else if (index<0 || index>last)
			cout << "ɾ��Ԫ��λ�ô���" << endl;
		// ע������ɾ���һ��Ԫ��ʱҪ�ر������ܰ�data[i + 1]��data[i]
		// ��Ϊdata[i + 1]��i=lastʱԽ����
		else if (index == last)
			--last;
		else
		{
			for (int i = index; i < last; i++)
			{
				data[i] = data[i + 1];
			}
			--last;
		}
	}

	void append(const ElemType &elem) override
	{
		if (isFull())
			cout << "˳���������" << endl;
		else
			//ע��Ҫ����last++�ٲ���Ԫ�أ���Ϊ����Ϊ��ʱlast=-1
			data[++last] = elem;
	}
private:
	ElemType* data;
	int last;
	int maxSize;
	bool isFull() const { return last == maxSize - 1; }
};

#endif
