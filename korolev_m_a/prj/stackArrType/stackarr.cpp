#include "stackarr.h"

using namespace std;

template<class C, typename T = C::value_type>
void testT(const C& v)
{
    if (v.size() < 4)
        throw logic_error("Not enough elements!");
    StackArrT<T> a;
    cout << "StackArrT<T> a; -> isEmpty() -> ";
    cout << boolalpha << a.isEmpty() << endl;
    cout << "a.top() -> ";
    try
    {
        a.top();
    }
    catch (logic_error& e)
    {
        cout << "exception caught (" << e.what() << ')' << endl;
    }
    a.push(v[0]);
    cout << "a.push(" << v[0] << ") -> a.top() -> " << a.top() << endl;
    cout << "a.isEmpty() -> " << boolalpha << a.isEmpty() << endl;
    a.push(v[1]);
    cout << "a.push(" << v[1] << ") -> top() -> " << a.top() << endl;
    StackArrT<T> b{ a };
    cout << "StackArrT<T> b{a}: a -> " << a << " b-> " << b << endl;
    a.push(v[2]);
    cout << "a.push(" << v[2] << ") -> top() -> " << a.top() << endl;
    a.push(v[3]);
    cout << "a.push(" << v[3] << ") -> top() -> " << a.top() << endl;
    b = a;
    cout << "b=a : a -> " << a << " b-> " << b << endl;;
    a.pop();
    cout << "a.pop() -> a-> " << a << endl;
    a = a;
    cout << "a=a : a -> " << a << endl;
}

int main()
{
    cout << "double" << endl;
    testT(array<double, 4>{{ -8.0, 54.1, 13.2, 6.3 }});
    cout << "int" << endl;
    testT(array<int, 4>{{ 1, -4, 3, -6 }});
    testT(array<string, 4>{{ "s531", "s54434", "s5435343", "s6" }});
    return 0;
}

