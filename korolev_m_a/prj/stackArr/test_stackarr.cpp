#include "stackarr.h"

using namespace std;

int main()
{
    StackArr a;
    cout << "Create stack and add numbers 20, 23, -9, 13" << endl;
    a.push(20);
    a.push(23);
    a.push(-9);
    a.push(13);
    cout << "Write a top number:13" << endl;
    cout << a.top() << endl;
    a.pop();
    cout << "Remove top number, write a new top number: -9" << endl;
    cout << a.top() << endl;
    a.pop();
    cout << "Remove top number, write a new top number: 23" << endl;
    cout << a.top() << endl;
    cout << "Copy stack a in stack b" << endl;
    StackArr b;
    b = a;
    cout << b << endl;
    cout << endl;
    cout << "add -45 45 in stack a. Write all stacks:" << endl;
    a.push(-45);
    a.push(45);
    cout << a << endl;
    cout << b << endl;
    cout << "Create new stack, check empty" << endl;
    StackArr c;
    try
    {
        cout << c.top() << endl;
    }
    catch (const logic_error& e)
    {
        cout << e.what() << endl;
    }
    c.push(95);
    cout << "add in this stack 95 and check it" << endl;
    cout << c.top() << endl;
    cout << "Copy stack b in c and write them" << endl;
    c = b;
    cout << b << endl;
    cout << c << endl;;
    cout << "Copy stack b in b  and write" << endl;
    b = b;
    cout << b << endl;
    cout << "Copy stack b in d and write d" << endl;
    StackArr d(b);
    cout << d << endl;
    return 0;
}