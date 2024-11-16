#ifndef STRING2_H_
#define STRING2_H_

#include<iostream>
using namespace std;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String();
	String(const char* s);
	String(const String& st);
	~String();
	int length() const { return len; }

	String operator=(const String& st);
	String operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);

	static int HowMany();

	//string2.hÐÂÔö
	friend String operator+(const String& st1, const String& st2);
	String Stringlow() const;
	String Stringup() const;
	int has(const char s) const;
};

#endif
