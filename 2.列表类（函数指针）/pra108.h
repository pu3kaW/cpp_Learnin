#ifndef PRA108_H_
#define PRA108_H_

const int MAX = 20;
typedef int Item;

class List
{
private:
	Item items[MAX];
	int num;

public:
	List();
	bool add(const Item& a);
	bool isempty() const;
	bool isfull() const;
	void visit(void (*pf)(Item&));
};

#endif
