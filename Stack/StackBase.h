// ������� --> ջ

#ifndef STACKBASE_H
#define STACKBASE_H

template <typename ElemType>
class StackBase
{
public:
	// ����ջ�Ĵ�С
	virtual int size() const = 0;

	// ����ջ�Ƿ�Ϊ��
	virtual bool empty() const = 0;

	// ��ջ
	virtual void push(const ElemType &) = 0;

	// ��ջ
	virtual ElemType pop() = 0;

	// �Ǳ�Ҫ�ӿڣ���֮���ڱ������
	virtual void print() const = 0;
};
#endif