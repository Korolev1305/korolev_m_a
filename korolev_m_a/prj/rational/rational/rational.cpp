#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Rational {
	public:
	Rational() {}
	explicit Rational(const int32_t val) : num_(val) { }
	Rational(const int32_t num, const int32_t denum) : num_(num), denum_(denum) {}
	double toDouble() const;
	bool operator==(const Rational& a) const { return (num_ == a.num_) && (denum_ == a.denum_) ; }
	bool operator!=(const Rational& a) const { return !operator==(a); }
	Rational& operator= (const Rational& a) { return Rational(num_ = a.num_, denum_ = a.denum_); }
	Rational operator+ (const Rational& a) {return normalize(Rational(num_*a.denum_ + a.num_ * denum_, denum_ * a.denum_)); }
	Rational operator/(const Rational& a) {return normalize(Rational(num_*a.denum_,denum_*a.num_)) ; }
	Rational& operator+=(const Rational& a);
	Rational& operator-=(const Rational& a);
	Rational operator/=(const Rational& a);
	Rational operator*=(const Rational& a);
	bool operator>(const Rational& a) { return (num_*a.denum_ > a.num_*denum_); }
	bool operator<(const Rational& a) { return (num_*a.denum_ < a.num_*denum_); }
	Rational operator*(const Rational& a) { return normalize(Rational(num_*a.num_,denum_*a.denum_)); }
	
	Rational operator- (const Rational& a) { return normalize(Rational(num_*a.denum_ - a.num_ * denum_, denum_ * a.denum_));
		Rational z(num_*a.denum_ - a.num_ * denum_, denum_ * a.denum_);
		return normalize(z);
	};
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	private:
	int32_t num_{0}; // числитель
	int32_t denum_{1}; // знаменатель
	Rational normalize(const Rational a) {
		int32_t a1(a.num_);
		int32_t b1(a.denum_);
		while (a1 % b1 != 0) {
			if (abs(a1) < abs(b1)) swap(a1, b1);
			if (a1 % b1 != 0) a1 = a1 % b1;
		}
		a1 = a.num_ / b1;
		b1 = a.denum_ / b1;
		Rational z(a1, b1);
		return z;
	}
};
	std::ostream& Rational::writeTo(std::ostream& ostrm) const {
		ostrm << num_ << "/" << denum_ << "\n";
		return ostrm;	
}
	Rational& Rational:: operator+=(const Rational& a) { 
		num_ = num_*a.denum_ + a.num_ * denum_;
		denum_ = denum_ * a.denum_;
		return normalize(Rational(num_, denum_));
	}
	Rational& Rational:: operator-=(const Rational& a) {
		num_ = num_*a.denum_ - a.num_ * denum_;
		denum_ = denum_ * a.denum_;
		return normalize(Rational(num_, denum_));
	}
	Rational Rational:: operator/=(const Rational& a) {
		num_ = num_*a.denum_;
		denum_ = denum_*a.num_;
		return normalize(Rational(num_, denum_));
	}
	Rational Rational:: operator*=(const Rational& a) {
		num_ = num_*a.num_;
		denum_ = denum_ * a.denum_;
		return normalize(Rational(num_, denum_));
	}
	inline std::ostream& operator<<(std::ostream& ostrm, const Rational& a) { return a.writeTo(ostrm); }
	inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.readFrom(istrm); }
int main() {
	Rational a(3, 4);
	Rational b(6, 8);
	Rational c(5, 7);
	Rational d(2, 8);
	Rational e(10, 12);
	Rational f(4, 3);
	Rational g(8, 15);
	Rational h(6, 25);
	
	cout << "a =" << a << "b = " << b << "c =" << c << "d = " << d << "e = " << e << "f = " << f << "g = " << g << "h = " << h ;
	Rational(a1) = a + b;
	a += b;
	Rational(a2) = c * d;
	c *= d;
	Rational(a3) = e / f;
	e /= f;
	Rational(a4) = g - h;
	g -= h;
	cout <<"a+b = " << a1;
	cout << "a+=b " <<a;
	cout << "c*d = " <<a2;
	cout << "c*=d " <<c;
	cout << "e/f = " <<a3;
	cout << "e/=f " <<e;
	cout << "g-h = " << a4;
	cout << "g-=h " << g;
	system("pause");
};
	
