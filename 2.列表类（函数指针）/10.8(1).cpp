#include"pra108.h"
using namespace std;

List::List()
{
	num = 0;
}

bool List::add(const Item& a)
{
	if (isfull())
		return false;
	else
	{
		items[num++] = a;
		return true;
	}
}

bool List::isempty() const
{
	return num == 0;
}

bool List::isfull() const
{
	return num == MAX;
}

void List::visit(void (*pf)(Item&))
{
	for (int i = 0;i < num;i++)
		pf(items[i]);
}