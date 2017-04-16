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
		newNode->next = top;
		top = newNode;
	}

	ElemType pop() override
	{
		ElemType elem;
		if (empty())
		{
			cout << "栈为空！" << endl;
			return ElemType();
		}
		elem = top->data;
		top = top->next;
		return elem;
	}

	// 这里的locate是错误的仅仅是给后面遍历用
	// 因为单链表的头结点才是top而不是尾节点，所以刚好相反
	ElemType& locate(int index) const override
	{
		// index检查，非空检查等略过
		int count = 0;
		Node <ElemType> *p = top;
		while (p->next && count < index)
		{
			p = p->next;
			++count;
		}
		return p->data;
	}
private:
	// 注意因为为了方便pop操作，把top设置为单链表的头结点！
	Node<ElemType> *top;
};
#endif