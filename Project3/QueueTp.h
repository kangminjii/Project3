#pragma once
#include "worker0.h"

template <class Type>
class Queue
{
private:
	enum { SIZE = 10 };
	int queuesize;
	Type* items;
	int num;
	int front;
	int rear;
public:
	explicit Queue(int qs = SIZE);
	Queue(const Queue& qu);
	~Queue() { delete[] items; }
	bool isempty() { return num == 0; }
	bool isfull() { return num == queuesize; }
	bool enque(const Type& item);
	bool deque(Type& item);
	Queue& operator=(const Queue& qu);
};

template <class Type>
Queue<Type>::Queue(int qs) : queuesize(qs), num(0), front(0), rear(0)
{
	items = new Type[queuesize];
}

template <class Type>
Queue<Type>::Queue(const Queue& qu)
{
	queuesize = qu.queuesize;
	num = qu.num;
	front = qu.front;
	rear = qu.rear;
	items = new Type[queuesize];
	for (int i = 0; i < num; i++)
		items[i] = qu.items[i];
}

template <class Type>
bool Queue<Type>::enque(const Type& item)
{
	if (num < queuesize)
	{
		items[num++] = item;
		rear++;
		if (rear == queuesize)	rear = 0;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Queue<Type>::deque(Type& item)
{
	if (num > 0)
	{
		item = items[--num];
		front++;
		if (front == queuesize)	front = 0;
		return true;
	}
	else
		return false;
}

template <class Type>
Queue<Type>& Queue<Type>::operator=(const Queue<Type>& qu)
{
	if (this == &qu)
		return *this;
	delete[] items;
	queuesize = qu.queuesize;
	num = qu.num;
	items = new Type[queuesize];
	for (int i = 0; i < num; i++)
		items[i] = qu.items[i];

	return *this;
}