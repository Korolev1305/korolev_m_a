#ifndef HG_STACKARR_H_20161117
#define HG_STACKARR_H_20161117

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

template<typename T>
class StackArrT
{
public:

    StackArrT() = default;
    StackArrT(const StackArrT& starr);
    ~StackArrT();

    StackArrT& operator=(const StackArrT& starr);

    void push(const T v);
    void pop();
    bool isEmpty() const;
    T top() const;

    std::ostream& print(std::ostream& ostrm) const;

private:

    ptrdiff_t size_{ 0 };
    ptrdiff_t iTop{ -1 }; //номер верхнего элемента
    T* data_{ nullptr };
};

template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const StackArrT<T>& v);

#endif
