#ifndef HG_MATRIX_H_20161024
#define HG_MATRIX_H_20160924

#include <iostream>

class Matrix {
public:
    Matrix() = default;
    Matrix(const Matrix& obj);
    Matrix(const ptrdiff_t size_lines, const ptrdiff_t size_columns);
    ~Matrix();
    Matrix& operator=(const Matrix& obj);
    int& at(const ptrdiff_t size_lines, const ptrdiff_t size_columns);
    const int& Matrix::at(const ptrdiff_t size_lines, const ptrdiff_t size_columns) const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    int* matrix{ nullptr };
    ptrdiff_t size_lines_{ 0 };
    ptrdiff_t size_columns_{ 0 };
};

std::ostream& operator<<(std::ostream& ostrm, const Matrix& obj);

#endif 
