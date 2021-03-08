#include <iostream>
#include <stdio.h>

using namespace std;

/*class Arithmetic
{
private:
    int a;
    int b;

public:
    Arithmetic(int a, int b);
    int add();
    int sub();
};

Arithmetic::Arithmetic(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Arithmetic::add()
{
    return a + b;
}

int Arithmetic::sub()
{
    return a - b;
}
*/

// template type

template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

int main()
{
    Arithmetic<int> ar(5, 6);
    cout << ar.add() << endl;

    Arithmetic<float> ar2(2.86, 3.4);
    cout << ar2.add() << endl;
    return 0;
}