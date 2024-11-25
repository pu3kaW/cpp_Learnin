#ifndef WINEC_H_
#define WINEC_H_

#include<iostream>
#include<string>
#include<valarray>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename T1, typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	Pair() {}
	Pair(T1 t1, T2 t2) :a(t1), b(t2){}
	T1& vintage() { return a; }
	T2& bottles() { return b; }
	T1 vintage() const { return a; }
	T2 bottles() const { return b; }

};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	string label;
	PairArray pair;
	int  years;
public:
	Wine() :label("none"), years(0), pair(ArrayInt(), ArrayInt()) {}
	Wine(const char* l, int y, const int yr[], const int bot[])
		:label(l), years(y), pair(ArrayInt(yr, y), ArrayInt(bot, y)) {}
	Wine(const char* l, int y)
		:label(l), years(y), pair(ArrayInt(y), ArrayInt(y)) {}

	void GetBottles()
	{
		for (int i = 0;i < years;i++)
		{
			cout << "Enter the vintage year:\n";
			cin >> pair.vintage()[i];
			cout << "Enter the bottles:\n";
			cin >> pair.bottles()[i];
		}
	}

	const string& Label()  const
	{
		return label;
	}

	int sum()
	{
		return pair.bottles().sum();
	}

	void Show() const
	{
		cout << "Wine: " << label << endl;
		cout << "\t" << "Year" << "\t" << "Bottles" << endl;
		for (int i = 0;i < years;i++)
			cout << "\t" << pair.vintage()[i] << "\t" << pair.bottles()[i] << endl;
	}
};

#endif