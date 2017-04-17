// 抽象基类 --> 栈

#ifndef QUEUEBASE_H
#define QUEUEBASE_H

template <typename ElemType>
class QueueBase
{
public:
	// 返回队列是否为空
	virtual bool empty() const = 0;

	// 返回队列大小
	virtual int size() const = 0;

	// 在队尾添加元素
	virtual void pushBack(const ElemType &) = 0;

	// 队首元素出队
	virtual ElemType popFront() = 0;

	// 非必要接口，加之便于遍历输出
	virtual void print() const = 0;
};
#endif