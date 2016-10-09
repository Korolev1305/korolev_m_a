#ifndef HG_RATIONAL_H_20160926
#define HG_RATIONAL_H_20160926

class Rational {
public:
    Rational();

    explicit Rational(const int32_t val);

    Rational(const int32_t num, const int32_t denum);

    double toDouble() const;

    Rational operator+ (const Rational& a);
    Rational operator- (const Rational& a);
    Rational operator*(const Rational& a);
    Rational operator/(const Rational& a);

	Rational& operator= (const Rational& a);
	Rational& operator+=(const Rational& a);
	Rational& operator-=(const Rational& a);
	Rational operator/=(const Rational& a);
	Rational operator*=(const Rational& a);

	bool operator==(const Rational& a) const;
	bool operator!=(const Rational& a) const;

	bool operator>(const Rational& a);
	bool operator<(const Rational& a);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
private:
	int32_t num_{ 0 }; // числитель
	int32_t denum_{ 1 }; // знаменатель
    Rational normalize(const Rational a);
		
};
std::ostream& operator<<(std::ostream& ostrm, const Rational& a);
std::istream& operator >> (std::istream& istrm, Rational& a);

#endif 
