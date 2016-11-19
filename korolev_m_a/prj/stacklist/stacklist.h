#ifndef HG_STACKLIST_H_20161114
#define HG_STACKLIST_H_20161114

class StackList
{

public:

    StackList() {}
    ~StackList();

    void push(const int v); 
    void pop(); 
    int top() const;
    bool isempty() const;
    void print();
    StackList(const StackList& obj); 
    StackList& operator=(const StackList& a); 

    void clear();
    void copy(const StackList& a);

    bool operator==(const StackList& a) const;
    bool operator!=(const StackList& a) const { return !operator==(a); }

private:
    struct node
    {
    public:
        int val{ 0 };
        node* next{ nullptr };

        node() {}
        node(int val_, node *node_)
            : val{ val_ }
            , next{ node_ }
        {}
    };

    node* head_{ nullptr };

};


#endif