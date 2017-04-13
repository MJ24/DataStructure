// 抽象基类-->线性表

#ifndef LINEARLISTBASE_H
#define LINEARLISTBASE_H
// 模板类的这个防止重复声明很重要

template <typename ElemType>
class LinearListBase
{
public:
	// 获取线性表大小
	virtual int size() const = 0;
	// 返回线性表是否为空
	virtual bool empty() const = 0;
	// 清空线性表
	virtual void clear() = 0;
	// 查找下标为i的元素返回其值
	virtual ElemType locate(int index) const = 0;
	// 查找值为x的元素返回其下标
	virtual int find(const ElemType &x) const = 0;
	// 在下标为i的元素之前插入元素x
	virtual void insert(int i, const ElemType &x) = 0;
	// 删除下标为i的元素
	virtual void erase(int i) = 0;
	// 添加元素到末尾，非必要接口，加之便于构建对象
	virtual void append(const ElemType &elem) = 0;
};

#endif