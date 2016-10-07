#ifndef HG_RATIONAL_H_20160926
#define HG_RATIONAL_H_20160926
#include <iostream>
class Rational {
public:
    Rational() {}
    explicit Rational(const int32_t val) : num_(val) { }
    Rational(const int32_t num, const int32_t denum) : num_(num), denum_(denum) {}
    double toDouble() const;
    Rational operator/(const Rational& a);
    Rational operator+ (const Rational& a);
    Rational& operator= (const Rational& a);
    Rational& operator+=(const Rational& a);
    Rational& operator-=(const Rational& a);
    Rational operator/=(const Rational& a);
    Rational operator*=(const Rational& a);
    Rational operator- (const Rational& a);
    bool operator==(const Rational& a) const;
    bool operator!=(const Rational& a) const;
    bool operator>(const Rational& a);
    bool operator<(const Rational& a);
    Rational operator*(const Rational& a);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
private:
    int32_t num_{ 0 }; // числитель
    int32_t denum_{ 1 }; // знаменатель
    Rational normalize(const Rational a) {
        int32_t a1(a.num_);
        int32_t b1(a.denum_);
        while (a1 % b1 != 0) {
            if (abs(a1) < abs(b1)) std::swap(a1, b1);
            if (a1 % b1 != 0) a1 = a1 % b1;
        }
        a1 = a.num_ / b1;
        b1 = a.denum_ / b1;
        Rational z(a1, b1);
        return z;
    }
};
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& a);
inline std::istream& operator>>(std::istream& istrm, Rational& rhs);
#endif HG_RATIONAL_H_20160926
