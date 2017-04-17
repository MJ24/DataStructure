// 栈的实现类 --> 单链表实现的栈

#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "StackBase.h"

template <typename ElemType> class LinkStack;
template <typename ElemType>
class Node
{
	friend class LinkStack < ElemType > ;
private:
	ElemType data;
	Node<ElemType>* next;
};

template <typename ElemType>
class LinkStack :public StackBase < ElemType >
{
public:
	LinkStack()
	{
		top = new Node < ElemType > ;
		top->next = nullptr;
	}

	int size() const override
	{
		int count = 0;
		Node <ElemType> *p = top;
		while (p->next)
		{
			p = p->next;
			++count;
		}
		return count;
	}

	bool empty() const override { return top->next == nullptr; }

	void push(const ElemType &elem) override
	{
		Node <ElemType> *newNode = new Node < ElemType > ;
		newNode->data = elem;
		newNode->next = top->next;
		top->next = newNode;
	}

	ElemType pop() override
	{
		ElemType elem;
		if (empty())
		{
			cout << "栈为空！" << endl;
			return ElemType();
		}
		elem = top->next->data;
		top->next = top->next->next;
		return elem;
	}

	void print() const override
	{
		if (empty())
			cout << "栈为空！" << endl;
		else
		{
			cout << "从栈顶到栈底：";
			Node <ElemType> *p = top->next;
			while (p->next)
			{
				cout << p->data << ",";
				p = p->next;
			}
			cout << p->data << endl;
		}
	}
private:
	// 注意因为为了方便pop操作，把top设置为单链表的头结点！
	// 另外top结点为虚拟节点，top->next为栈顶元素
	Node<ElemType> *top;
};
#endif