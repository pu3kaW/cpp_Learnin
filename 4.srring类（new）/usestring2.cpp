#include<iostream>
using namespace std;
#include"string2.h"

int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	cout << "The string\n" << s2.Stringup() << "\ncontains " << s2.Stringup().has('A')
		<< "'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"),String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		for (int i = 0;i < 3;i++)
		{
			if (ans.Stringlow() == rgb[i])
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";

	return 0;
}