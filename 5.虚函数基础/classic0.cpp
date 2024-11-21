#include<iostream>
#include<cstring>
#include"classic0.h"
using namespace std;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[1];
	label = new char[1];
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const {
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	
	delete[] performers;
	delete[] label;

	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* m, const char* s1, const char* s2, int n, double x)
	:Cd(s1, s2, n, x)
{
	mvp = new char[strlen(m) + 1];
	strcpy(mvp, m);
}

Classic::Classic(const char* m, Cd& d)
	:Cd(d)
{
	mvp = new char[strlen(m) + 1];
	strcpy(mvp, m);
}

Classic::Classic()
{
	 mvp = new char[1];
	mvp[0] = '\0';
}

CLassic::~Classic()
{
	delete[] mvp;
}

void Classic::Report() const
{
	Cd::Report();
	cout << "The main string: " << mvp << endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;

	Cd::operator= (c);
	delete[] mvp;
	mvp = new char[strlen(c.mvp) + 1];
	strcpy(mvp, c.mvp);
	return *this;
}

