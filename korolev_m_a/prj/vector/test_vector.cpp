#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    Vector vector(7);
    for (int i = 0;i < 7;i++) {
        vector[i] = i;
    }
    cout << "������� ����� ������ ������� 7"<< endl;
    cout << vector << endl;
    cout << "����������� ������� ������� � �����" << endl;
    Vector newVector;
    newVector = vector;
    cout << newVector << endl;
}