#include <iostream>
#include <sstream>
#include "rational.h"

Rational::Rational()
{
}

Rational::Rational(const int32_t val)
{
    num_ = val;
}

Rational::Rational(const int32_t num, const int32_t denum)
{
    if (!denum)
    {
        throw std::exception("denum = 0");

    }
    num_ = num;
    denum_ = denum;
}

double Rational::toDouble() const
{
    return num_ / denum_;
}

Rational Rational::normalize(const Rational a)
{
    int num(a.num_);
    int denum(a.denum_);
    while (num % denum != 0) {
        if (abs(num) < abs(denum)) std::swap(num, denum);
        if (num % denum != 0) num = num % denum;
    }
    num = a.num_ / denum;
    denum = a.denum_ / denum;
    Rational z(num, denum);
    return z;
}

Rational& Rational::operator+=(const Rational& a) {
	num_ = (num_*a.denum_) + (a.num_ * denum_);
	denum_ = denum_ * a.denum_;
	Rational z = normalize(Rational(num_, denum_));
	return z;
}

Rational& Rational::operator-=(const Rational& a) {
	num_ = num_*a.denum_ - a.num_ * denum_;
	denum_ = denum_ * a.denum_;
	return normalize(Rational(num_, denum_));;
}

Rational Rational::operator/=(const Rational& a) {
	num_ = num_*a.denum_;
	denum_ = denum_*a.num_;
	Rational z = normalize(Rational(num_, denum_));
	return z;
}

Rational Rational::operator*=(const Rational& a) {
	num_ = num_*a.num_;
	denum_ = denum_ * a.denum_;
	Rational z = normalize(Rational(num_, denum_));
	return z;
}

bool Rational::operator==(const Rational& a) const { return (num_ - a.num_ < 1E-6) && (denum_ - a.denum_ < 1E-6); }

bool Rational::operator!=(const Rational& a) const { return !operator==(a); }

bool Rational::operator>(const Rational& a) { return (num_*a.denum_ - a.num_*denum_ >0); }

bool Rational::operator<(const Rational& a) { return (num_*a.denum_ - a.num_*denum_ < 0); }

Rational Rational::operator+ (const Rational& a) { return normalize(Rational(num_*a.denum_ + a.num_ * denum_, denum_ * a.denum_)); }

Rational& Rational::operator= (const Rational& a) { return Rational(num_ = a.num_, denum_ = a.denum_); }

Rational Rational::operator/(const Rational& a) { return normalize(Rational(num_*a.denum_, denum_*a.num_)); }

Rational Rational::operator*(const Rational& a) { return normalize(Rational(num_*a.num_, denum_*a.denum_)); }

Rational Rational::operator- (const Rational& a)
{
	return normalize(Rational(num_*a.denum_ - a.num_ * denum_, denum_ * a.denum_));
	Rational z(num_*a.denum_ - a.num_ * denum_, denum_ * a.denum_);
	return normalize(z);
};

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << num_ << "/" << denum_ << "\n";
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
    return istrm;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& a) { return a.writeTo(ostrm); }
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.readFrom(istrm); }


