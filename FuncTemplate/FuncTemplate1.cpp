#include <iostream>
using namespace std;

template <typename T>
T TestFunc(T a)
{
    cout << "매개변수 a: " << a << endl;
    return a;
}
int main()
{
    cout << "int\t" << TestFunc(3) << endl;
    cout << "double\t" << TestFunc(3.3) << endl;
    cout << "char\t" << TestFunc('A') << endl;
    cout << "char*\t" << TestFunc("TestString") << endl;

    return 0;
}

