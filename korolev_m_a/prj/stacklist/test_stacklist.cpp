#include "stacklist.h"
#include <iostream>

using namespace std;

int main()
{
    StackList a;
    cout << "Create stack and add numbers 20, 23, -9, 13" << endl;
    a.push(20);
    a.push(23);
    a.push(-9);
    a.push(13);
    cout << "Write a top number: 13" << endl;
    cout << a.top() << endl;
    a.pop();
    cout << "Remove top number, write a new top number: -9" << endl;
    cout << a.top() << endl;
    a.pop();
    cout << "Remove top number, write a new top number: 23" << endl;
    cout << a.top() << endl;
    cout << "Copy stack a in stack b" << endl;
    StackList b{ a };
    b.print();
    cout << endl;
    cout << "add -45 45 in stack a. Write all stacks:" << endl;
    a.push(-45);
    a.push(45);
    a.print();
    b.print();
    cout << "Create new stack, check empty" << endl;
    StackList c;
    try
    {
        cout << c.top() << endl;
    }
    catch (const logic_error& e)
    {
        cout << e.what() << endl;
    }
    c.push(95);
    cout << "add in stack c 95 and check" << endl;
    cout << c.top() << endl;
    cout << "Copy stack b in c and write them" << endl;
    c = b;
    b.print();
    c.print();
    cout << "add in stack c 12 and write b and c stacks" << endl;
    c.push(12);
    b.print();
    c.print();
    cout << "Stack b != c : " << (b != c) << endl;
    cout << "Stack b == c : " << (b == c) << endl;
    cout << "Stack b == b : " << (b == b) << endl;
    cout << "Stack c == c : " << (c == c) << endl;
    cout << "add in stack b 12 and write b and c stacks" << endl;
    b.push(12);
    b.print();
    c.print();
    cout << "Stack b != c : " << (b != c) << endl;
    cout << "Stack b == c : " << (b == c) << endl;
    b = b;
    b.print();
    c.print();
    cout << "Copy stack b in d and write d" << endl;
    StackList d(b);
    d.print();
    return 0;
}