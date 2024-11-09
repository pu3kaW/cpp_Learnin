#include<iostream>
#include<cctype>
#include"pra105.h"

using namespace std;

int main()
{
	Stack stack;
	customer cm;
	double total = 0.0;
	char choice;

	cout << "Enter the customer into the stack.\n"
		<< "(a to push, b to pop, c to report total payment, q to quit.)\n";

	while (cin >> choice && isalpha(choice) && tolower(choice) != 'q')
	{
		switch (tolower(choice))
		{
		case 'a':
		{
			cout << "Enter one customer into the stack.\n";
			cin.get();
			cin.get(cm.fullname, 35);
			cin >> cm.payment;
			if (stack.isfull())
				cout << "The stack is already full!\n";
			else
				stack.push(cm);
			break;
		}
		case 'b':
		{
			if (stack.isempty())
				cout << "There is nothing in the stack!\n";
			else
			{
				stack.pop(cm);
				total += cm.payment;
				cout << cm.fullname << " poped!\n";
			}
			break;
		}
		case 'c':
			cout << "The total payment : " << total << endl;
			break;
		}
		cout << "Enter the customer into the stack.\n"
			<< "(a to push, b to pop, c to report total payment, q to quit.)\n";
	}
	cout << "\nBye\n";

	return 0;
}