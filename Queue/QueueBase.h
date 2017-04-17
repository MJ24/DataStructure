// ������� --> ջ

#ifndef QUEUEBASE_H
#define QUEUEBASE_H

template <typename ElemType>
class QueueBase
{
public:
	// ���ض����Ƿ�Ϊ��
	virtual bool empty() const = 0;

	// ���ض��д�С
	virtual int size() const = 0;

	// �ڶ�β���Ԫ��
	virtual void pushBack(const ElemType &) = 0;

	// ����Ԫ�س���
	virtual ElemType popFront() = 0;

	// �Ǳ�Ҫ�ӿڣ���֮���ڱ������
	virtual void print() const = 0;
};
#endif