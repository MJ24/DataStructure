// ջ��ʵ���� --> ������ʵ�ֵ�ջ

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
			cout << "ջΪ�գ�" << endl;
			return ElemType();
		}
		elem = top->next->data;
		top->next = top->next->next;
		return elem;
	}

	void print() const override
	{
		if (empty())
			cout << "ջΪ�գ�" << endl;
		else
		{
			cout << "��ջ����ջ�ף�";
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
	// ע����ΪΪ�˷���pop��������top����Ϊ�������ͷ��㣡
	// ����top���Ϊ����ڵ㣬top->nextΪջ��Ԫ��
	Node<ElemType> *top;
};
#endif