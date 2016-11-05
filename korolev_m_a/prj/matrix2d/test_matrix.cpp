#include <iostream>
#include "matrix2d.h"

using namespace std;

int main() {
    const int lines{ 25 };
    const int columns{ 25 };
    Matrix matrix{ lines, columns };
    cout << "Write a matrix 25x25" << endl;
    for (ptrdiff_t i = 0; i < lines; ++i) {
        for (ptrdiff_t j = 1; j < columns; ++j) {
            matrix.at(i, j) = i * j + j;
            cout << matrix.at(i, j) << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;


    Matrix matrix2{ lines, columns };
    cout << "copy matrix in matrix2" << endl;
    for (int i = 0; i < 100000; ++i) {
        matrix2 = matrix2;
        matrix2 = matrix;
    }

    for (ptrdiff_t i = 0; i < lines; ++i) {
        for (ptrdiff_t j = 1; j < columns; ++j) {
            cout << matrix2.at(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}