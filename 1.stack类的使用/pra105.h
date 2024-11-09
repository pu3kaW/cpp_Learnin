#ifndef PRA105_H_
#define PRA105_H_

typedef struct customer
{
	char fullname[35];
	double payment;
}customer;

class Stack
{
private:
	enum{MAX = 10};
	customer cms[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const customer& a);
	bool pop(customer& a);
};

#endif
