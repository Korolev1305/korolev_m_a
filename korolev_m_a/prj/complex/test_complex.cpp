#include <iostream>
#include <sstream>
#include "complex.h"

using namespace std;

bool testParse(const std::string& str)
{
    std::istringstream istrm(str);
    Complex ñ;
    istrm >> ñ;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << ñ << endl;
    }
    else {
        cout << "Read error : " << str << " -> " << ñ << endl;
    }
    return istrm.good();
}

void runArufmeticsTests(Complex a, Complex b)
{
    cout << "Arifmetics tests: " << endl;
    Complex ñ{ a }, k{ b };

    cout << "Ñ = " << ñ << "; Ñ += {8, 2}; Ñ = ";
    ñ += Complex{ 8, 2 };
    cout << ñ << endl;

    cout << k << " + " << ñ << " = " << (k + ñ) << endl;
    cout << k << " - " << ñ << " = " << (k - ñ) << endl;
    cout << k << " * " << ñ << " = " << (k * ñ) << endl;
    cout << k << " equal to " << ñ << " = " << (k == ñ) << endl;
    cout << k << " not equal to " << ñ << " = " << (k != ñ) << endl;

    cout << k << " + " << 3 << " = " << (k + 3) << endl;
    cout << k << " - " << 5 << " = " << (k - 5) << endl;
    cout << k << " * " << 2 << " = " << (k * 2) << endl << endl;
}

void runParseTest()
{
    cout << endl << "Parse tests: " << endl;

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
}

int main()
{
    runArufmeticsTests({ 1,1 }, { 8, 2 });

    cout << endl;

    runParseTest();

    return 0;
}