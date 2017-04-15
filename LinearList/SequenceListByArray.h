// 线性表的实现类 --> 泛型数组实现的顺序表

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
			cout << "顺序表为空！" << endl;
		}
		else if (index<0 || index>last)
		{
			// 这里和上面一样如果ElemType是int之类的
			// 会return一个未定义值而报错，有没有什么解决方法？
			cout << "索引位置错误！" << endl;
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
			cout << "顺序表为空！" << endl;
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
			cout << "顺序表已满！" << endl;
		// index = last+1则表示插在末尾
		else if (index<0 || index>last + 1)
			cout << "插入元素位置错误！" << endl;
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
			cout << "顺序表为空！" << endl;
		else if (index<0 || index>last)
			cout << "删除元素位置错误！" << endl;
		// 注意这里删最后一个元素时要特别处理，不能把data[i + 1]给data[i]
		// 因为data[i + 1]当i=last时越界了
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
			cout << "顺序表已满！" << endl;
		else
			//注意要先让last++再插入元素，因为当表为空时last=-1
			data[++last] = elem;
	}
private:
	ElemType* data;
	int last;
	int maxSize;
	bool isFull() const { return last == maxSize - 1; }
};

#endif
