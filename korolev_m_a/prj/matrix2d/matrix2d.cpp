#include "matrix2d.h"
#include <iostream>


Matrix::~Matrix()
{
    delete[] matrix; 
    matrix = nullptr;
}

Matrix::Matrix(const ptrdiff_t size_lines, const ptrdiff_t size_columns)
    : size_lines_{ size_lines }
    , size_columns_{ size_columns }
{
    if ((size_lines < 0) || (size_columns < 0)) {
        throw std::invalid_argument("Negative size");
    }
    matrix = new int[size_lines * size_columns];
}

Matrix::Matrix(const Matrix& obj)
{
    *this = obj;
}

Matrix& Matrix::operator=(const Matrix& obj) {
    if (this != &obj) {
        int* newData(new int[obj.size_columns_ * obj.size_lines_]);
        for (int i = 0; i < obj.size_lines_ * obj.size_columns_; i++) {
            newData[i] = obj.matrix[i];
        }
        delete[] matrix;
        size_lines_ = obj.size_lines_;
        size_columns_ = obj.size_columns_;
        matrix = newData;
    }
    return *this;
}


ptrdiff_t& Matrix::at(const ptrdiff_t i, const ptrdiff_t j) {
    if (i < 0 || j < 0) {
        throw std::invalid_argument("Invalid index\n");
    }
    return matrix[i * size_columns_ + j];
}

const ptrdiff_t& Matrix::at(const ptrdiff_t i, const ptrdiff_t j) const {
    if (i < 0 || j < 0) {
        throw std::invalid_argument("Invalid index\n");
    }
    return matrix[i * size_columns_ + j];
}

std::ostream& Matrix::writeTo(std::ostream& ostrm) const {
    for (int i = 0; i < size_lines_; ++i) {
        for (int j = 0; j < size_columns_; ++j) {
            ostrm << at(i, j) << " ";
        }
        ostrm << "\n";
    }
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, Matrix& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}