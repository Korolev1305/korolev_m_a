#include <cstdint>
#include <iostream>
#include <sstream>
#include "rational.h"
using namespace std;

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << num_ << "/" << denum_ << "\n";
	return ostrm;
}
Rational& Rational:: operator+=(const Rational& a) {
	num_ = num_*a.denum_ + a.num_ * denum_;
	denum_ = denum_ * a.denum_;
	Rational z = normalize(Rational(num_, denum_));
	return z;
}
Rational& Rational:: operator-=(const Rational& a) {
	num_ = num_*a.denum_ - a.num_ * denum_;
	denum_ = denum_ * a.denum_;
	return normalize(Rational(num_, denum_));;
}
Rational Rational:: operator/=(const Rational& a) {
	num_ = num_*a.denum_;
	denum_ = denum_*a.num_;
	Rational z = normalize(Rational(num_, denum_));
	return z;
}
Rational Rational:: operator*=(const Rational& a) {
	num_ = num_*a.num_;
	denum_ = denum_ * a.denum_;
	Rational z = normalize(Rational(num_, denum_));
	return z;
}
bool Rational:: operator==(const Rational& a) const { return (num_ == a.num_) && (denum_ == a.denum_); }
bool Rational:: operator!=(const Rational& a) const { return !operator==(a); }
bool Rational:: operator>(const Rational& a) { return (num_*a.denum_ - a.num_*denum_ >0); }
bool Rational:: operator<(const Rational& a) { return (num_*a.denum_ - a.num_*denum_ < 0); }
Rational Rational:: operator+ (const Rational& a) { return normalize(Rational(num_*a.denum_ + a.num_ * denum_, denum_ * a.denum_)); }
Rational& Rational:: operator= (const Rational& a) { return Rational(num_ = a.num_, denum_ = a.denum_); }
Rational Rational:: operator/(const Rational& a) { return normalize(Rational(num_*a.denum_, denum_*a.num_)); }
Rational Rational:: operator*(const Rational& a) { return normalize(Rational(num_*a.num_, denum_*a.denum_)); }
Rational Rational:: operator- (const Rational& a)
{
	return normalize(Rational(num_*a.denum_ - a.num_ * denum_, denum_ * a.denum_));
	Rational z(num_*a.denum_ - a.num_ * denum_, denum_ * a.denum_);
	return normalize(z);
};
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& a) { return a.writeTo(ostrm); }
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.readFrom(istrm); }


