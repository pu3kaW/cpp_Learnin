#include"pra105.h"

Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const customer& a)
{
	if (top < MAX)
	{
		cms[top++] = a;
		return true;
	}
	else
		return false;
}

bool Stack::pop(customer& b)
{
	if (top > 0)
	{
		b = cms[--top];
		return true;
	}
	else
		return false;
}