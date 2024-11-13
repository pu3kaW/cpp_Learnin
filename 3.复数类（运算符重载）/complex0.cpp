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
        // 如果输入流失败，检查是否是用户输入了非数字字符
        is.clear(); // 清除错误状态
        std::string input;
        is >> input;
        if (input == "q") {
            is.setstate(std::ios::failbit); // 设置流为失败状态，触发退出条件
        }
        return is; // 返回失败状态
    }

    std::cout << "Enter the imaginary: ";
    if (!(is >> c.imaginary)) {
        // 检查虚部输入的错误
        is.clear();
        std::string input;
        is >> input;
        if (input == "q") {
            is.setstate(std::ios::failbit); // 设置流为失败状态
        }
        return is;
    }

    return is; // 返回成功状态
}

