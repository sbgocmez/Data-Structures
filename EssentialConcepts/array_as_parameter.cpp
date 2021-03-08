#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// array can only be pass by value
void change(int B[])
{
    //error:'sizeof' on array function parameter 'B' will return size of 'int*'
    // cout << "Size of A: " << sizeof(B) << endl;
    /*for (int x : A) // error!
        x += 4;*/
    B[2] = 8;
}

void function(int *B)
{
    *(B) = 4;
    *(B + 3) = 16;
    B[3] = 17;
}

int *create(int size)
{
    int *p;
    p = new int[size];

    for (int i = 0; i < size; i++)
        p[i] = i * 3;

    return p;
}

int main()
{
    int A[] = {3, 4, 7, 9};
    int *O;

    cout << "Before: " << endl;
    cout << "Size of A: " << sizeof(A) << endl;
    for (int x : A)
        cout << x << " ";

    change(A);
    cout << "After: " << endl;
    for (int x : A)
        cout << x << " ";

    function(A);
    cout << "After: " << endl;
    for (int x : A)
        cout << x << " ";

    O = create(6);
    cout << "After: " << endl;
    for (int x = 0; x < 6; x++)
        cout << *(O + x) << " ";

    O = create(6);
    cout << "After: " << endl;
    for (int x = 0; x < 6; x++)
        cout << O[x] << " ";
    return 0;
}