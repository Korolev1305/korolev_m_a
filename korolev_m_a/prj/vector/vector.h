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
    Vector& operator=(const Vector& obj);
    int& operator[](const ptrdiff_t idx);
    const int& operator[](const ptrdiff_t idx) const;
    std::ostream& writeTo(std::ostream& ostrm);
private:
    int* vec = nullptr;
    ptrdiff_t size{ 0 };
};

std::ostream& operator<<(std::ostream& ostrm, Vector& obj);

#endif 

