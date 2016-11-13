#include "stackarr.h"
#include <iostream>

StackArr::StackArr() = default;

void StackArr::push(const int v)
{
    if (itop_ == size_ - 1)
    {
        int* pNewData{ new int[size_ + 10] };
        for (int i = 0; i < size_; ++i)
            pNewData[i] = data_[i];
        delete[] data_;
        data_ = pNewData;
        size_ += 10;
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

StackArr & StackArr::operator=(const StackArr & obj)
{
    if (this != &obj) {
        if (obj.size_ <= size_)
        {
            for (int i = 0; i < obj.size_; ++i)
                data_[i] = obj.data_[i];
            itop_ = obj.itop_;
        }
        else
        {
            int* newData(new int[obj.size_]);
            for (int i = 0; i < obj.size_; i++) {
                newData[i] = obj.data_[i];
            }
            delete[] data_;
            size_ = obj.size_;
            itop_ = obj.itop_;
            data_ = newData;
        }
    }
    return *this;
}

StackArr::StackArr(const StackArr & obj)
{
    if (obj.size_ <= size_)
    {
        for (int i=0; i < obj.size_; ++i)
            data_[i] = obj.data_[i];
        itop_ = obj.itop_;
    }
    else
    {
        size_ = obj.size_;
        itop_ = obj.itop_;
        delete[] data_;
        data_ = new int[size_];
        for (int i=0; i < size_; ++i)
            data_[i] = obj.data_[i];
    }
}

std::ostream& StackArr::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < itop_+1; ++i) {
        ostrm << data_[i] << " ";
        }
    ostrm << "\n";
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, StackArr& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}