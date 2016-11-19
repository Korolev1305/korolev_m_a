#include <iostream>
#include "matrix2d.h"

using namespace std;

int main() {
    const int lines{ 25 };
    const int columns{ 25 };
    Matrix matrix(lines, columns);
    cout << "Write a matrix 25x25" << endl;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix.at(i, j) = i * j;
            cout << matrix.at(i, j) << " ";
        }
        cout << endl;
    }

    cout << endl;


    Matrix matrix2(lines, columns);
    cout << "copy matrix in matrix2" << endl;
    matrix2 = matrix;

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix2.at(i, j) << " ";
        }
        cout << endl;
    }

    cout << "Try to use wrong size\n";
    try {
        Matrix matrix3(5, -4);
    }
    catch (invalid_argument) {
        cout << "Exception cathed.\n";
    }

    cout << "Try to use wrong index\n";
    try {
        matrix.at(-1, 4);
    }
    catch (invalid_argument) {
        cout << "Exception catched.\n";
    }

    cout << "Try to use wrong index\n";
    try {
        matrix.at(1000, 4);
    }
    catch (invalid_argument) {
        cout << "Exception catched.\n";
    }
        
    return 0;
    
}