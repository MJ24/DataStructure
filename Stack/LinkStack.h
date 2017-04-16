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
		newNode->next = top;
		top = newNode;
	}

	ElemType pop() override
	{
		ElemType elem;
		if (empty())
		{
			cout << "ջΪ�գ�" << endl;
			return ElemType();
		}
		elem = top->data;
		top = top->next;
		return elem;
	}

	// �����locate�Ǵ���Ľ����Ǹ����������
	// ��Ϊ�������ͷ������top������β�ڵ㣬���Ըպ��෴
	ElemType& locate(int index) const override
	{
		// index��飬�ǿռ����Թ�
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
	// ע����ΪΪ�˷���pop��������top����Ϊ�������ͷ��㣡
	Node<ElemType> *top;
};
#endif