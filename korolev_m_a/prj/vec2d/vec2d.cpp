#include "vec2d.h"
#include <iostream>
#include <math.h>
#include <sstream>
Vec2d& Vec2d::operator+=(const Vec2d& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	return *this;
}

Vec2d & Vec2d::operator==(const Vec2d & rhs)
{
	return (x_ == rhs.x_ && y_ == rhs.y_);
}

bool Vec2d::operator!=(const Vec2d & rhs)
{
	return (x_ != rhs.x_ && y_ != rhs.y_);
}

Vec2d& Vec2d::operator-=(const Vec2d& rhs)
{
	x_ -= rhs.x_;
	y_ -= rhs.y_;
	return *this;
}

Vec2d& Vec2d::operator+(const Vec2d& rhs)
{
	return Vec2d(x_ + rhs.x_, y_ + rhs.y_);
}

Vec2d& Vec2d::operator-(const Vec2d& rhs)
{
	return Vec2d(x_ - rhs.x_, y_ - rhs.y_);
}

bool Vec2d::operator<(const Vec2d& rhs)
{
	return (abs() - rhs.abs()) > 0;
}

std::ostream& Vec2d::writeTo(std::ostream& ostrm)
{
	ostrm << "x: " << x_ << " ; y: " << y_;
	return ostrm;
}

double Vec2d::operator*(const Vec2d& rhs)
{
	return x_*rhs.x_ + y_*rhs.y_;
}

Vec2d & Vec2d::operator*(int k)
{
	return Vec2d(x_*k, y_*k);
}

double Vec2d::operator[](const int index) const
{
	if (!index)
	{
		return x_;
	}
	else if (index)return y_;
}

double Vec2d::abs() const
{
	return sqrt(x_*x_ + y_*y_);
}

Vec2d::Vec2d()
{
}

Vec2d::Vec2d(const double x, const double y)
{
	x_ = x;
	y_ = y;
}

Vec2d::~Vec2d() {}

std::istream& Vec2d::readFrom(std::istream& istrm) const
{
	char leftBrace(0);
	double x_(0.0);
	double x(0.0);
	double y(0.0);
	char comma(0);
	double y_(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> x >> comma >> y >> rightBrace;
	if (istrm.good()) {
		if ((Vec2d::leftBrace == leftBrace) && (Vec2d::separator == comma)
			&& (Vec2d::rightBrace == rightBrace)) {
			x_ = x;
			y_ = y;

		}
		else {
			istrm.setstate(std::ios_base::failbit);

		}

	}
	return istrm;
}


