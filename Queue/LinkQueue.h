// 队列的实现类 --> 单链表实现的队列

#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "QueueBase.h"

template <typename ElemType> class LinkQueue;
template <typename ElemType>
class Node
{
	friend class LinkQueue < ElemType > ;
private:
	ElemType data;
	Node<ElemType>* next;
};

template <typename ElemType>
class LinkQueue :public QueueBase < ElemType >
{
public:
	LinkQueue() :front(nullptr), rear(nullptr) { }

	bool empty() const override { return front == nullptr && rear == nullptr; }

	int size() const override
	{
		if (empty())
			return 0;
		else
		{
			int count = 1;
			Node<ElemType> *p = front;
			while (p != rear)
			{
				++count;
				p = p->next;
			}
			return count;
		}
	}

	void pushBack(const ElemType &elem) override
	{
		Node<ElemType> *newNode = new Node < ElemType > ;
		newNode->data = elem;
		newNode->next = nullptr;
		if (empty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	ElemType popFront() override
	{
		if (empty())
		{
			cout << "队列为空！" << endl;
			return ElemType();
		}
		else
		{
			ElemType elem = front->data;
			front = front->next;
			return elem;
		}
	}

	void print() const override
	{
		if (empty())
			cout << "队列为空！" << endl;
		else
		{
			Node<ElemType> *p = front;
			while (p != rear)
			{
				cout << p->data << ",";
				p = p->next;
			}
			cout << rear->data << endl;
		}
	}
private:
	Node<ElemType> *front;
	Node<ElemType> *rear;
};
#endif