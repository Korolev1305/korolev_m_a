#ifndef HG_VECTOR_H_20161017
#define HG_VECTOR_H_20160917

#include <iostream>
class Vector {
public:
    Vector();
    Vector(const Vector& obj);
    Vector(const ptrdiff_t size);
    ~Vector();
    ptrdiff_t init_size() const;
    ptrdiff_t init_length() const;
    Vector& operator=(const Vector& obj);
    void add(ptrdiff_t value);
    int& operator[](const ptrdiff_t idx);
    const int& operator[](const ptrdiff_t idx) const;
    std::ostream& writeTo(std::ostream& ostrm);
    void resize(const ptrdiff_t length);
private:
    int* vec = nullptr;
    ptrdiff_t size{ 0 };
    ptrdiff_t length{ 0 };
};

std::ostream& operator<<(std::ostream& ostrm, Vector& obj);

#endif 

