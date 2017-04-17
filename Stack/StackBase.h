// 抽象基类 --> 栈

#ifndef STACKBASE_H
#define STACKBASE_H

template <typename ElemType>
class StackBase
{
public:
	// 返回栈的大小
	virtual int size() const = 0;

	// 返回栈是否为空
	virtual bool empty() const = 0;

	// 入栈
	virtual void push(const ElemType &) = 0;

	// 出栈
	virtual ElemType pop() = 0;

	// 非必要接口，加之便于遍历输出
	virtual void print() const = 0;
};
#endif