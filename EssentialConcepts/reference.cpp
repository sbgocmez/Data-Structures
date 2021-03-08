#include <iostream>
#include <stdio.h>

using namespace std;

// reference doesnt consume any memory
int main()
{
    int a = 10;
    int &r = a;
    //int &r; error.

    cout << a << endl
         << r << endl;

    return 0;
}