#include<iostream>
#include"pra108.h"
using namespace std;

void showitem(Item &item)
{
	cout << item << "  ";
}

void increment(Item& item) {
    item += 1;
}

int main() {
    List mylist;
    mylist.add(1);
    mylist.add(2);
    mylist.add(3);
    mylist.add(4);

    cout << "Original items: \t";
    mylist.visit(showitem);
    cout << endl;

    mylist.visit(increment);

    cout << "Incremented items: \t";
    mylist.visit(showitem);
    cout << endl;

    return 0;
}
