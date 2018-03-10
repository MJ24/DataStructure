// 线性表的实现类 --> 单链表

#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H
#include "LinearListBase.h"

//注意这里一定要加一句SingleLinkList类的声明！！！
template <typename ElemType> class SingleLinkList;
template <typename ElemType>
class Node
{
	friend class SingleLinkList<ElemType>;
private:
	ElemType data;
	Node<ElemType>* next;
};

template <typename ElemType>
class SingleLinkList :public LinearListBase<ElemType>
{
public:
	SingleLinkList() :head(nullptr) {}
	~SingleLinkList()
	{
		Node<ElemType>* next = head;
		while (head)
		{
			next = head->next;
			delete head;
			head = next;
		}
	}

	int size() const override
	{
		int size = 0;
		Node<ElemType>* p = head;
		while (p)
		{
			++size;
			p = p->next;
		}
		return size;
	}

	bool empty() const override { return head == nullptr; }

	void clear() override { head = nullptr; }

	ElemType& locate(int index) const override
	{
		ElemType result;
		if (empty())
		{
			cout << "链表为空！" << endl;
			return result;
		}
		if (index < 0)
		{
			cout << "索引位置错误！" << endl;
			return result;
		}
		Node<ElemType> *p = head;
		int count = 0;
		while (count < index && p)
		{
			p = p->next;
			++count;
		}
		if (p)
			result = p->data;
		else
			cout << "索引位置错误！" << endl;
		return result;
	}

	int find(const ElemType &elem) const override
	{
		if (empty())
			cout << "链表为空！" << endl;
		else
		{
			Node<ElemType> *p = head;
			int index = 0;
			while (p && p->data != elem)
			{
				p = p->next;
				++index;
			}
			if (p)
				return index;
		}
		return -1;
	}

	void insert(int index, const ElemType &elem) override
	{
		Node<ElemType> *newNode = new Node<ElemType>;
		newNode->data = elem;
		newNode->next = nullptr;
		if (empty())
		{
			if (index == 0)
				head = newNode;
			else
				cout << "链表为空！只允许在第0个插入！" << endl;
		}
		else if (index < 0)
			cout << "插入元素位置错误！" << endl;
		else if (index == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			Node<ElemType> *p = head;
			int count = 0;
			while (p && count < index - 1)
			{
				p = p->next;
				++count;
			}
			if (count == index - 1)
			{
				newNode->next = p->next;
				p->next = newNode;
			}
			else
				cout << "插入元素位置错误！" << endl;
		}
	}

	void erase(int index) override
	{
		if (empty())
			cout << "链表为空！" << endl;
		else if (index < 0)
			cout << "删除元素位置错误！" << endl;
		else if (index == 0)
			head = head->next;
		else
		{
			Node<ElemType> *p = head;
			int count = 0;
			while (p && count < index - 1)
			{
				p = p->next;
				++count;
			}
			// 第i-1和第i个元素都存在
			if (p && p->next)
				p->next = p->next->next;
			else
				cout << "删除元素位置错误！" << endl;
		}
	}

	void append(const ElemType &elem) override
	{
		Node<ElemType> *newNode = new Node<ElemType>;
		newNode->data = elem;
		newNode->next = nullptr;
		if (empty())
			head = newNode;
		else
		{
			Node<ElemType> *p = head;
			while (p->next)
				p = p->next;
			p->next = newNode;
		}
	}
private:
	Node<ElemType>* head;
};
#endif