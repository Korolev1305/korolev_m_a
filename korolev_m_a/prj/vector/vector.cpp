#include "vector.h"

Vector::Vector() = default; 


Vector::~Vector() {
    delete[] vec; vec = nullptr;
}

Vector::Vector(const ptrdiff_t capacity)
    : length{ capacity }
{
    if (capacity < 0)
    {
        throw std::invalid_argument("Negative size");
    }
    vec = new int[capacity];
    size = 0;
    length = capacity;
}

Vector::Vector(const Vector &obj)
{
    *this = obj;
}

Vector& Vector::operator=(const Vector& obj) {
    if (this != &obj) {
        delete[] vec;
        size = obj.size;
        length = obj.length;
        vec = new int[length];
        for (int i = 0; i < size; i++) {
            this->operator[](i) = obj[i];
        }
    }
    return *this;
}
int &Vector::operator[](const ptrdiff_t idx) {
    if (idx > size && idx > length) {
        throw std::out_of_range("Out of range in vector");
    }
    return *(vec + idx);
}

const int &Vector::operator[](const ptrdiff_t idx) const {
    if (idx > size && idx > length) {
        throw std::out_of_range("Out of range in vector");
    }
    return *(vec + idx);
}

ptrdiff_t Vector::init_size() const {
    return size;
}

ptrdiff_t Vector::init_length() const {
    return length;
}

void Vector::resize(const ptrdiff_t new_size) {
    if(length <= new_size) {
        int* new_vec = new int[new_size];
        for (int i(0); i < length; ++i) {
            new_vec[i] = vec[i];
        }
        delete[] vec;
        vec = new_vec;
        size = new_size;
        length = new_size;
    }
else {
    int* new_vec = new int[size];
    for (int i(0); i < size; ++i) {
        new_vec[i] = vec[i];
    }
    delete[] vec;
    vec = new_vec;
    size = new_size;
}
}

void Vector::add(ptrdiff_t value) {
    if (size < length) {
        this->operator[](size) = value;
        size++;
    }
    
}

std::ostream &operator<<(std::ostream &ostrm, Vector& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}

std::ostream& Vector::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < size; ++i) {
        ostrm << (*this)[i] << " " ;
    }
    return ostrm;
}