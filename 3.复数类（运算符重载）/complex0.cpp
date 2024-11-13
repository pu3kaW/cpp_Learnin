#include<iostream>
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
	Complex result;
	result.real = real + c.real;
	result.imaginary = imaginary + c.imaginary;
	return result;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex result;
	result.real = real - c.real;
	result.imaginary = imaginary - c.imaginary;
	return result;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex result;
	result.real = (real * c.real) - (imaginary * c.imaginary);
	result.imaginary = (real * c.imaginary) + (c.real * imaginary);
	return result;
}

Complex Complex::operator~() const
{
	return Complex(real,-imaginary);
}

Complex operator*(double x, const Complex& c)
{
	Complex result;
	result.real = x * c.real;
	result.imaginary = x * c.imaginary;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "(" << c.real << "," << c.imaginary << "i)\n";
	return os;
}

#include <limits>

std::istream& operator>>(std::istream& is, Complex& c)
{
    std::cout << "Enter the real: ";
    if (!(is >> c.real)) {
        // ���������ʧ�ܣ�����Ƿ����û������˷������ַ�
        is.clear(); // �������״̬
        std::string input;
        is >> input;
        if (input == "q") {
            is.setstate(std::ios::failbit); // ������Ϊʧ��״̬�������˳�����
        }
        return is; // ����ʧ��״̬
    }

    std::cout << "Enter the imaginary: ";
    if (!(is >> c.imaginary)) {
        // ����鲿����Ĵ���
        is.clear();
        std::string input;
        is >> input;
        if (input == "q") {
            is.setstate(std::ios::failbit); // ������Ϊʧ��״̬
        }
        return is;
    }

    return is; // ���سɹ�״̬
}

