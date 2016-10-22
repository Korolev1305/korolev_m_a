#include "vector.h"

Vector::Vector() {
    vec = new int[0];
    size = 0;
}

Vector::~Vector() {
    delete[] vec; vec = nullptr;
}

Vector::Vector(const ptrdiff_t size)
    : size{ size }
{
    if (size < 0)
    {
        throw std::invalid_argument("Negative size");
    }
    vec = new int[size];
}

Vector::Vector(const Vector &obj)
    : size(obj.size)
    , vec(new int[size])
{
    std::copy(obj.vec, obj.vec + obj.size, vec);
}

Vector& Vector::operator=(const Vector& obj) {
    if (this != &obj) {
        if (size < obj.size) {
            int* newData(new int[obj.size]);
            delete[] vec;
            vec = newData;
        }
        std::copy(obj.vec, obj.vec + obj.size, vec);
        size = obj.size;
    }
    return *this;
}
int &Vector::operator[](const ptrdiff_t idx) {
    if (idx >= size) {
        throw std::out_of_range("Out of range in vector");
    }
    return *(vec + idx);
}

const int &Vector::operator[](const ptrdiff_t idx) const {
    if (idx >= size) {
        throw std::out_of_range("Out of range in vector");
    }
    return *(vec + idx);
}

ptrdiff_t Vector::init_size() const {
    return size;
}

std::ostream &operator<<(std::ostream &ostrm, Vector& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}

std::ostream& Vector::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < size; ++i) {
        ostrm << '{' << (*this)[i] << '}' ;
    }
    return ostrm;
}