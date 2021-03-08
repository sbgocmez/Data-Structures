#include <iostream>
#include <stdio.h>
#define N 5
using namespace std;

int main()
{
    // N should be constant integer or macro. N as an user input may seem like working but its garbage.
    double A[N] = {2.3, 3.5, 12.0, 34.33, 7.67};

    //print elements
    for (int i = 0; i < N; i++)
        cout << A[i] << endl;
    //C++ style fractions not included
    for (int x : A)
        cout << x << endl;

    return 0;
}