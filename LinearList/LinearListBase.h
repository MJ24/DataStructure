// �������-->���Ա�

#ifndef LINEARLISTBASE_H
#define LINEARLISTBASE_H
// ģ����������ֹ�ظ���������Ҫ

template <typename ElemType>
class LinearListBase
{
public:
	// ��ȡ���Ա��С
	virtual int size() const = 0;
	// �������Ա��Ƿ�Ϊ��
	virtual bool empty() const = 0;
	// ������Ա�
	virtual void clear() = 0;
	// �����±�Ϊi��Ԫ�ط�����ֵ
	virtual ElemType locate(int index) const = 0;
	// ����ֵΪx��Ԫ�ط������±�
	virtual int find(const ElemType &x) const = 0;
	// ���±�Ϊi��Ԫ��֮ǰ����Ԫ��x
	virtual void insert(int i, const ElemType &x) = 0;
	// ɾ���±�Ϊi��Ԫ��
	virtual void erase(int i) = 0;
	// ���Ԫ�ص�ĩβ���Ǳ�Ҫ�ӿڣ���֮���ڹ�������
	virtual void append(const ElemType &elem) = 0;
};

#endif