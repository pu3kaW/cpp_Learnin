#include<iostream>
#include <limits>
#include"complex0.h"

Complex::Complex()
{
	real = imaginary = 0;
}

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}

Complex Complex::operator+(const Complex& c) const
{
	return Complex(real + c.real, imaginary + c.imaginary);
}

Complex Complex::operator-(const Complex& c) const
{
    return Complex(real - c.real, imaginary - c.imaginary);
}

Complex Complex::operator*(const Complex& c) const
{
    return Complex((real * c.real) - (imaginary * c.imaginary), real * c.imaginary) + (c.real * imaginary);
}

Complex Complex::operator~() const
{
	return Complex(real,-imaginary);
}

Complex operator*(double x, const Complex& c)
{
    return (x * c.real, x * c.imaginary);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "(" << c.real << "," << c.imaginary << "i)\n";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
    std::cout << "Enter the real: ";
    if (!(is >> c.real)) {
        is.clear(); 
        std::string input;
        is >> input;
        if (input == "q") {
            is.setstate(std::ios::failbit); 
        }
        return is; 
    }

    std::cout << "Enter the imaginary: ";
    if (!(is >> c.imaginary)) {
        is.clear();
        std::string input;
        is >> input;
        if (input == "q") {
            is.setstate(std::ios::failbit); 
        }
        return is;
    }

    return is; 
}

