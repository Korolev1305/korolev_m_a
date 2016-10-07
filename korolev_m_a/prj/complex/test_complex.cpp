#include "complex.h"
#include <iostream>

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;

	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;

	}
	return istrm.good();
}
int main()
{
	using namespace std;

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	Complex first(8, 1);
	Complex second(7, 3);
	cout << first << "-=" << second;
	first -= second;
	cout << "=" << first << endl;
	cout << first << "*=" << second << "=";
	first *= second;
	cout << first << endl;
	Complex dualFirst(Complex::dual(first));
	cout << "dual for first" << dualFirst << endl;
	Complex dualSecond = second.dual();
	cout << "dual for second" << dualSecond << endl;
	cout << first << "/=" << second << "=";
	first /= second;
	cout << first << endl;
	cout << first << "/" << second << "=";
	Complex newComp(first / second);
	cout << newComp << endl;
	cout << first << "==" << second << " result:" << (first == second);
	cout << first << "!=" << second << " result:" << (first != second);
	system("pause");
	return 0;
}


