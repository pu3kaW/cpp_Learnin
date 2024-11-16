#include<iostream>
#include<cctype>
#include<cstring>
#include"string2.h"

using namespace std;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}

String::String(const String& st)
{
	len = st.length();
	str = new char[len + 1];
	strcpy(str, st.str);
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete[]str;
}

String String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

String String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return (st2 < st1);
}

bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

//string2.hÐÂÔö
String operator+(const String& st1, const String& st2)
{
	int newlen = st1.len + st2.len;
	char* temp = new char[newlen + 1];
	strcpy(temp, st1.str);
	strcat(temp, st2.str);
	String st3(temp);
	delete[] temp;
	return st3;
}

String String::Stringlow() const
{
	String temp(*this);
	for (int i = 0;i < len;i++)
	{
		if (isupper(str[i]))
			temp[i] = tolower(str[i]);
	}
	return temp;
}

String String::Stringup() const
{
	String temp(*this);
	for (int i = 0;i < len;i++)
	{
		if (islower(str[i]))
			temp[i] = toupper(str[i]);
	}
	return temp;
}

int String::has(const char s) const
{
	int num = 0;
	for (int i = 0;i < len;i++)
	{
		if (str[i] == s)
			num++;
	}
	return num;
}