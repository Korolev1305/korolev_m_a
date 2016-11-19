#include "stacklist.h"
#include <iostream>
#include <stdexcept>


void StackList::push(const int v)
{
    head_ = new node{ v, head_ };
}

void StackList::pop()
{
    if (!isempty())
    {
        node* deleted{ head_ };
        head_ = head_->next;
        delete deleted;
    }
}

bool StackList::isempty() const
{
    return (nullptr == head_);
}

void StackList::print()
{
    if (!isempty())
    {
        std::cout << head_->val << " ";
        node* pread{ head_->next };
        while (pread != nullptr)
        {
            std::cout << pread->val << " ";
            pread = pread->next;
        }
        std::cout << std::endl;
    }
}

void StackList::copy(const StackList& obj)
{
    head_ = new node{ obj.head_->val, nullptr };
    node* pread{ obj.head_->next };
    node* pwrite{ head_ };
    while (pread != nullptr)
    {
        pwrite->next = new node{ pread->val, nullptr };
        pwrite = pwrite->next;
        pread = pread->next;
    }

}

int StackList::top() const
{
    if (isempty())
    {
        throw std::logic_error("stack is empty");
    }
    return head_->val;
}

void StackList::clear()
{
    while (!isempty())
        pop();
}

StackList::~StackList()
{
    clear();
}

StackList::StackList(const StackList& obj)
{
    if (!obj.isempty())
    {
        copy(obj);
    }
}

StackList& StackList::operator=(const StackList& a)
{
    if (this != &a)
    {
        if (!isempty())
        {
            while (!isempty())
                pop();
        }
        delete head_;
        head_ = nullptr;
        copy(a);
    }
    return *this;
}

bool StackList::operator==(const StackList& a) const
{
    if (this != &a)
    {
        bool res = true;
        if (head_->val != a.head_->val)
            return false;
        else
        {
            node* pcur{ head_->next };
            node* pobj{ a.head_->next };
            while (pobj != nullptr)
            {
                if ((pcur == nullptr) && (pcur->val != pobj->val))
                    return false;
                pcur = pcur->next;
                pobj = pobj->next;
            }
            return true;
        }

    }
    else
        return true;
}


