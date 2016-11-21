#include <iostream>
#include "matrix2d.h"

using namespace std;

int main() {
    const int lines(5);
    const int columns(5);
    Matrix matrix(lines, columns);
    for (int i(0); i < lines; i += 1) {
        for (int j(0); j < columns; j += 1) {
            matrix.at(i, j) = i * j;
        }
        cout << endl;
    }
    cout << "Write a matrix 5x5" << endl;
    cout << matrix;
    cout << endl;


    Matrix matrix2(lines, columns);
    cout << "copy matrix in matrix2" << endl;

    matrix2 = matrix;
    cout << matrix2;
    
    cout << "copy matrix2 in matrix 3" << endl;
    Matrix matrix3(matrix2);
    cout << matrix3;
    cout << "Try to use wrong size\n";
    try {
        Matrix matrix3(5, -4);
    } catch (invalid_argument) {
        cout << "Exception cathed.\n";
    }

    cout << "Try to use wrong index\n";
    try {
        matrix.at(-1, 4);
    } catch (invalid_argument) {
        cout << "Exception catched.\n";
    }

    cout << "Try to use wrong index\n";
    try {
        matrix.at(1000, 4);
    } catch (invalid_argument) {
        cout << "Exception catched.\n";
    }
    return 0;
    
}