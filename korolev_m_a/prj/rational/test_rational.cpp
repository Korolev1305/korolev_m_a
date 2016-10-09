#include <iostream>
#include <sstream>
#include "rational.h"

using namespace std;

int main() {
	Rational a(3, 4);
	Rational b(6, 8);
	Rational c(5, 7);
	Rational d(2, 8);
	Rational e(10, 12);
	Rational f(4, 3);
	Rational g(8, 15);
	Rational h(6, 25);
	bool flag;
	cout << "a =" << a << "b = " << b << "c =" << c << "d = " << d << "e = " << e << "f = " << f << "g = " << g << "h = " << h << endl;
	flag = a > b;
    cout << flag << endl;
	flag = a < b;
	cout << flag << endl;
	flag = a != b;
	cout << flag << endl;
	flag = a == a;
	cout << flag << endl;
	Rational(a1) = a + b;
	a += b;
	Rational(a2) = c * d;
	c *= d;
	Rational(a3) = e / f;
	e /= f;
	Rational(a4) = g - h;
	g -= h;
	cout << "a+b = " << a1 << endl;
	cout << "a+=b " << a << endl;
	cout << "c*d = " << a2 << endl;
	cout << "c*=d " << c << endl;
	cout << "e/f = " << a3 << endl;
	cout << "e/=f " << e << endl;
	cout << "g-h = " << a4 << endl;
	cout << "g-=h " << g << endl;
};