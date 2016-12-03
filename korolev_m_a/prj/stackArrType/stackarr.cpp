#include "stackarr.h"


template<typename T>
StackArrT<T>::StackArrT(const StackArrT<T>& starr)
        : size_{ starr.size_ }
        , iTop{ starr.iTop }
        , data_{ new T[size_] }
{
    std::uninitialized_copy(starr.data_, starr.data_ + starr.iTop + 1, data_);
}

template<typename T>
StackArrT<T>::~StackArrT()
{
    delete[] data_;
    data_ = nullptr;
}

template<typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& starr)
{
    if (this != &starr)
    {
        if (size_ < starr.size_)
        {
            T* pNewData{ new T[starr.size_] };
            delete[] data_;
            data_ = pNewData;
        }
        std::uninitialized_copy(starr.data_, starr.data_ + starr.iTop + 1, data_);
        size_ = starr.size_;
        iTop = starr.iTop;
    }
    return *this;
}

template<typename T>
void StackArrT<T>::push(const T v)
{
    if (iTop == size_ - 1)
    {
        T* pNewData{ new T[size_ * 2] };
        for (size_t i = 0; i < size_; i++)
        {
            pNewData[i] = data_[i];
        }
        delete[] data_;
        data_ = pNewData;
        size_ *= 2;
    }
    data_[++iTop] = v;
}

template<typename T>
void StackArrT<T>::pop()
{
    if (!isEmpty())
    {
        iTop -= 1;
    }
}

template<typename T>
bool StackArrT<T>::isEmpty() const
{
    return -1 == iTop;
}

template<typename T>
T StackArrT<T>::top() const
{
    if (isEmpty())
    {
        throw logic_error("nothing in stack");
    }
    return data_[iTop];
}

template<typename T>
std::ostream& StackArrT<T>::print(std::ostream& ostrm) const
{
    ostrm << ']';
    for (size_t i = 0; i <= iTop; i++)
    {
        ostrm << data_[i];
        if (i < iTop)
            ostrm << ',';
    }
    ostrm << ']';
    return ostrm;
}

template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const StackArrT<T>& v)
{
    return v.print(ostrm);
}

