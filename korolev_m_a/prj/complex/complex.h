#ifndef HG_VEC2D_H_20160310
#define HG_VEC2D_H_20160310

struct Complex {
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	Complex& dual();
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/(const Complex& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static Complex& dual(const Complex& rhs);
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };

};

#endif
