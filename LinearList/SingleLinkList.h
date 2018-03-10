// ���Ա��ʵ���� --> ������

#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H
#include "LinearListBase.h"

//ע������һ��Ҫ��һ��SingleLinkList�������������
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
			cout << "����Ϊ�գ�" << endl;
			return result;
		}
		if (index < 0)
		{
			cout << "����λ�ô���" << endl;
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
			cout << "����λ�ô���" << endl;
		return result;
	}

	int find(const ElemType &elem) const override
	{
		if (empty())
			cout << "����Ϊ�գ�" << endl;
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
				cout << "����Ϊ�գ�ֻ�����ڵ�0�����룡" << endl;
		}
		else if (index < 0)
			cout << "����Ԫ��λ�ô���" << endl;
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
				cout << "����Ԫ��λ�ô���" << endl;
		}
	}

	void erase(int index) override
	{
		if (empty())
			cout << "����Ϊ�գ�" << endl;
		else if (index < 0)
			cout << "ɾ��Ԫ��λ�ô���" << endl;
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
			// ��i-1�͵�i��Ԫ�ض�����
			if (p && p->next)
				p->next = p->next->next;
			else
				cout << "ɾ��Ԫ��λ�ô���" << endl;
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