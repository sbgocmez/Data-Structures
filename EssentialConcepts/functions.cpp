#include <iostream>
#include <stdio.h>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

/*
Classical swap function
temp = x;
x = y;
y = temp;
*

void pass_by_value_swap(int x, int y)
{
    cout << " In the Funciton Pass by Value " << endl;
    cout << "x: " << x << "  y: " << y << endl;
    x += y;
    y = x - y;
    x -= y;
    cout << "x: " << x << "  y: " << y << endl;
    cout << " Out of the Funciton " << endl;
}

void pass_by_address_swap(int *x, int *y)
{
    cout << " In the Funciton Pass by Address " << endl;
    cout << "x: " << *x << "  y: " << *y << endl;
    *x += *y;
    *y = *x - *y;
    *x -= *y;
    cout << "x: " << *x << "  y: " << *y << endl;
    cout << " Out of the Funciton " << endl;
}

void pass_by_reference_swap(int &x, int &y)
{
    cout << " In the Funciton Pass by Reference " << endl;
    cout << "x: " << x << "  y: " << y << endl;
    x += y;
    y = x - y;
    x -= y;
    cout << "x: " << x << "  y: " << y << endl;
    cout << " Out of the Funciton " << endl;
}

int main()
{
    cout << add(8, 9) << endl;
    int x = 5, y = 6;
    cout << add(*(&x), *(&y)) << endl;
    int *p1 = &x;
    int *p2 = &y;

    int &r1 = x;
    int &r2 = y;

    cout << add(*p1, *p2) << endl;
    pass_by_value_swap(x, y);
    cout << " In main function, x: " << x << " y: " << y << endl;
    pass_by_address_swap(p1, p2);
    cout << " In main function, x: " << x << " y: " << y << endl;
    pass_by_reference_swap(r1, r2); // we can also write x,y
    cout << " In main function, x: " << x << " y: " << y << endl;
    return 0;
}