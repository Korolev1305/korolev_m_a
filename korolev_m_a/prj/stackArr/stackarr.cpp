#include "stackarr.h"
#include <iostream>

void StackArr::push(const int v)
{
    if (itop_ == size_ - 1)
    {
        int* pNewData{ new int[size_ * 2] };
        for (int i = 0; i < size_; i++)
            pNewData[i] = data_[i];
        delete[] data_;
        data_ = pNewData;
        size_ *= 2;
    }
    data_[++itop_] = v;
}

void StackArr::pop()
{
    if (!isempty())
    {
        itop_--;
    }
    else
    {
        throw std::logic_error("You try to pop the empty stack!");
    }
}

bool StackArr::isempty() const
{
    return (-1 == itop_);
}


int StackArr::top() const
{
    if (isempty())
    {
        throw std::logic_error("You try to get top element from the empty stack!");
    }
    return data_[itop_];
}

StackArr::~StackArr()
{
    delete[] data_;
}

StackArr & StackArr::operator=(const StackArr & a)
{

    if (a.size_ <= size_)
    {
        for (int i{ 0 }; i < a.size_; i++)
            data_[i] = a.data_[i];
        itop_ = a.itop_;
    }
    else
    {
        size_ = a.size_;
        itop_ = a.itop_;
        delete[] data_;
        data_ = new int[size_];
        for (int i{ 0 }; i < size_; i++)
            data_[i] = a.data_[i];
    }
    return *this;
}

StackArr::StackArr(const StackArr & a)
{
    if (a.size_ <= size_)
    {
        for (int i{ 0 }; i < a.size_; ++i)
            data_[i] = a.data_[i];
        itop_ = a.itop_;
    }
    else
    {
        size_ = a.size_;
        itop_ = a.itop_;
        delete[] data_;
        data_ = new int[size_];
        for (int i{ 0 }; i < size_; ++i)
            data_[i] = a.data_[i];
    }
}

std::ostream& StackArr::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < size_; ++i) {
        ostrm << data_[i] << " ";
        }
    ostrm << "\n";
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, StackArr& obj) {
    obj.writeTo(ostrm);
    return ostrm;