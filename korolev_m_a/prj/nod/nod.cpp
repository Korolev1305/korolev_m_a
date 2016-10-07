#include <iostream>
using namespace std;
void gcd(int a, int b) {
    int a1(a);
    int b1(b);

    while (a1 % b1 != 0) {
        if (abs(a1) < abs(b1)) swap(a1, b1);
        if (a1 % b1 != 0) a1 = a1 % b1;
	}
    cout << "a = " << a << " b = " << b << "\n";
    cout << "gcd(a,b) =" << b1 << "\n";
    return;
}
int main() {
    gcd(3, -9);
    gcd(5, 15);
    gcd(-4, -40);
    gcd(41, 41);
}