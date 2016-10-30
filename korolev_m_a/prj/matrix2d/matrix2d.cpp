#include "matrix2d.h"

Matrix::Matrix() {
    matrix = new int[0];
    size_lines = 0;
    size_columns = 0;
}

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
    :size_lines{ obj.size_lines }
    , size_columns{ obj.size_columns }
    , matrix{ new int[size_lines*size_columns] }
{
    std::copy(obj.matrix, obj.matrix + obj.size_columns*obj.size_lines, matrix);
}

Matrix& Matrix::operator=(const Matrix& obj) {

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

const int Matrix::at(const ptrdiff_t idx_lines, const ptrdiff_t idx_columns) {
    int element = matrix[idx_lines*size_columns + idx_columns];
    return element;
}

std::ostream& Matrix::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < size_lines; ++i) {
        for (int j = 0;j < size_columns; ++j) {
            ostrm << '{' << (*this).at(i,j) << '}';
        }
        ostrm << "\n";
    }
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, Matrix& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}