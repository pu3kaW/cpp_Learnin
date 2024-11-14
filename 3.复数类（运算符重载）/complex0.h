#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include<iostream>

class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double r, double i);
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator~() const;

	friend Complex operator*(double x, const Complex& c);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif