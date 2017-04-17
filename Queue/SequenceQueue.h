// ���е�ʵ���� --> ѭ������ʵ�ֵĶ���

#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H
#include "QueueBase.h"

template <typename ElemType>
class SequenceQueue :public QueueBase < ElemType >
{
public:
	SequenceQueue(int mSize = 20)
	{
		maxSize = mSize;
		data = new ElemType[maxSize];
		front = -1;
		rear = -1;
	}

	bool empty() const override { return front == rear; }

	int size() const override { return (rear - front + maxSize) % maxSize; }

	void pushBack(const ElemType &elem) override
	{
		if (isFull())
			cout << "����������" << endl;
		else
		{
			rear = (rear + 1) % maxSize;
			data[rear] = elem;
		}
	}

	ElemType popFront() override
	{
		if (empty())
		{
			cout << "����Ϊ�գ�" << endl;
			return ElemType();
		}
		else
		{
			front = (front + 1) % maxSize;
			return data[front];
		}
	}

	void print() const override
	{
		if (empty())
			cout << "����Ϊ�գ�" << endl;
		else
		{
			if (front < rear)
			{
				for (int i = front + 1; i < rear; i++)
					cout << data[i] << ",";
				cout << data[rear] << endl;
			}
			else
			{
				for (int i = front + 1; i <= maxSize; i++)
					cout << data[i] << ",";
				for (int i = 0; i < rear; i++)
					cout << data[i] << ",";
				cout << data[rear] << endl;
			}
		}
	}
private:
	ElemType* data;
	int maxSize;
	// frontΪ����Ԫ�ص�ǰһ��
	int front;
	int rear;

	bool isFull() { return (rear + 1) % maxSize == front; }
};
#endif