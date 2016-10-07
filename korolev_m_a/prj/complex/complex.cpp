#include <iostream>
#include <sstream>
#include "complex.h"

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	double newRe(re*rhs.re - im*rhs.im);
	double newIm(re*rhs.im + im*rhs.re);
	re = newRe;
	im = newIm;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	double newRe((re*rhs.re + im*rhs.im) / (rhs.im*rhs.im + rhs.re*rhs.re));
	double newIm((rhs.re*im - re*rhs.im) / (rhs.im*rhs.im + rhs.re*rhs.re));
	re = newRe;
	im = newIm;
	return *this;
}

Complex& Complex::operator/(const Complex& rhs)
{
	return (*this /= rhs);
}

Complex& Complex::dual()
{
	return Complex(re, -im);
}

Complex& Complex::dual(const Complex& rhs)
{
	return Complex(rhs.re, -rhs.im);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;

		}
		else {
			istrm.setstate(std::ios_base::failbit);

		}

	}
	return istrm;
}