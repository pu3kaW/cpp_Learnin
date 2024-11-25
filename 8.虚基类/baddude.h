#ifndef BADDUDE_H_
#define BADDUDE_H_

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Person
{
private:
    string fname;  
    string lname;  
public:
    Person(const char* fn = "none", const char* ln = "none")
        : fname(fn), lname(ln) {}

    virtual ~Person() {}

    virtual void Show() const
    {
        cout << lname << ", " << fname << endl;
    }
};

class Gunslinger : virtual public Person
{
private:
    double gun_time; 
    int notch;       
public:
    Gunslinger(const char* fn = "none", const char* ln = "none", double gt = 0.0, int n = 0)
        : Person(fn, ln), gun_time(gt), notch(n) {}

    double Draw() const { return gun_time; }

    void Show() const override
    {
        Person::Show();
        cout << "Gunslinger - Time: " << gun_time << endl;
        cout << "Notch: " << notch << endl;
    }
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer(const char* fn = "none", const char* ln = "none")
        : Person(fn, ln) {}

    int Draw() const
    {
        return (rand() % 52) + 1; 
    }

    void Show() const override
    {
        Person::Show();
        cout << "PokerPlayer - Card Draw: " << Draw() << endl;
    }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(const char* fn, const char* ln, double gt, int n)
        : Person(fn, ln), Gunslinger(fn, ln, gt, n), PokerPlayer(fn, ln) {}

    double Gdraw() const { return Gunslinger::Draw(); }

    int Cdraw() const { return PokerPlayer::Draw(); }

    void Show() const override
    {
        Person::Show();
        cout << "BadDude - Guntime: " << Gdraw() << endl;
        cout << "Card Draw: " << Cdraw() << endl;
    }
};

#endif 
