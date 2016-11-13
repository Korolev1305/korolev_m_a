#ifndef STACKARR_H_20161031
#define STACKARR_H_20151031

#include <iostream>

class StackArr
{
private:
    int size_{ 0 };
    int itop_{ -1 };
    int* data_{ nullptr }; 

public:
    StackArr();


    ~StackArr();

    void push(const int v);
    void pop();
    int top() const;
    bool isempty() const;

    StackArr(const StackArr& obj); 
    StackArr& operator=(const StackArr& a);
    std::ostream& writeTo(std::ostream& ostrm);
};
    std::ostream& operator<<(std::ostream& ostrm, StackArr& obj);
#endif
