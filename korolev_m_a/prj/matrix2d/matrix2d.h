#ifndef HG_MATRIX_H_20161024
#define HG_MATRIX_H_20160924

#include <iostream>
class Matrix {
public:
    Matrix();
    Matrix(const Matrix& obj);
    Matrix(const ptrdiff_t size_lines, const ptrdiff_t size_columns);
    ~Matrix();
    Matrix& operator=(const Matrix& obj);
    ptrdiff_t& at(const ptrdiff_t size_lines, const ptrdiff_t size_columns);
    const ptrdiff_t& Matrix::at(const ptrdiff_t size_lines, const ptrdiff_t size_columns) const;
    std::ostream& writeTo(std::ostream& ostrm);
private:
    int* matrix = nullptr;
    ptrdiff_t size_lines{ 0 };
    ptrdiff_t size_columns{ 0 };
};

std::ostream& operator<<(std::ostream& ostrm, Matrix& obj);

#endif 
