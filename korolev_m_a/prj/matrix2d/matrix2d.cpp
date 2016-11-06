#include "matrix2d.h"
#include <iostream>

Matrix::Matrix() = default;

Matrix::~Matrix() {
    delete[] matrix; 
    matrix = nullptr;
}

Matrix::Matrix(const ptrdiff_t size_lines, const ptrdiff_t size_columns)
    :size_lines{ size_lines }
    , size_columns{ size_columns }
{
    if ((size_lines < 0) || (size_columns < 0)) {
        throw std::invalid_argument("Negative size");
    }
    matrix = new int[size_lines*size_columns];
}

Matrix::Matrix(const Matrix& obj)
{
    *this = obj;
}

Matrix& Matrix::operator=(const Matrix& obj) {
    if (this != &obj) {
        delete[] matrix;
        size_lines = obj.size_lines;
        size_columns = obj.size_columns;
        matrix = new int[size_lines*size_columns];
        for (int i = 0; i < size_lines*size_columns; i++) {
            this->operator[](i) = obj[i];
        }
    }
    return *this;
}

const ptrdiff_t Matrix::init_lines() 
{
    return size_lines;
}

const ptrdiff_t Matrix::init_columns() {
    return size_columns;
}

int &Matrix::operator[](const ptrdiff_t idx) {
    if (idx >= size_lines*size_columns) {
        throw std::out_of_range("Out of range in matrix");
    }
    return *(matrix + idx);
}

const int &Matrix::operator[](const ptrdiff_t idx) const {
    if (idx >= size_lines*size_columns) {
        throw std::out_of_range("Out of range in matrix");
    }
    return *(matrix + idx);
}

ptrdiff_t& Matrix::at(const ptrdiff_t i, const ptrdiff_t j) {
    if (i < 0 || j < 0) {
        throw std::invalid_argument("Invalid index\n");
    }
    return matrix[i * size_columns + j];
}

const ptrdiff_t& Matrix::at(const ptrdiff_t i, const ptrdiff_t j) const {
    if (i < 0 || j < 0) {
        throw std::invalid_argument("Invalid index\n");
    }
    return matrix[i * size_columns + j];
}

std::ostream& Matrix::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < size_lines; ++i) {
        for (int j = 0;j < size_columns; ++j) {
            ostrm <<(*this).at(i,j)<< " ";
        }
        ostrm << "\n";
    }
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, Matrix& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}