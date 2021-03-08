#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    //on stack
    int array[5] = {7, 4, 5, 2, 3};
    int *p;
    p = array; // p = &array[0]

    for (int i = 0; i < 5; i++)
        cout << p[i] << "  ";

    cout << endl
         << "*     *     *" << endl;
    for (int i = 0; i < 5; i++)
        cout << *(p + i) << "  ";

    cout << endl
         << "*     *     *" << endl;
    for (int i = 0; i < 5; i++)
        cout << *(array + i) << "  ";

    //dynamic allocation on heap
    int *a;                             // a is at stack
    a = (int *)malloc(sizeof(int) * 5); // these 5 locations are at heap same as a=new int[5]
    a[0] = 2;
    a[1] = 4;
    a[2] = 6;
    a[3] = 8;
    a[4] = 10;

    cout << endl
         << "*     *     *" << endl;
    cout << endl
         << "*     *     *" << endl;
    for (int i = 0; i < 5; i++)
        cout << a[i] << "  ";
    cout << endl
         << "*     *     *" << endl;
    for (int i = 0; i < 5; i++)
        cout << *(a + i) << "  ";

    free(p); // delete[]p;

    //interesting
    int *p1;
    double *p2;
    char *p3;
    float *p4;
    struct Rectangle *p5;
    cout << endl
         << "*     *     *" << endl;
    cout << endl
         << "*     *     *" << endl;
    cout << "Sizes of pointers" << endl;
    cout << "For int: " << sizeof(p1) << endl;
    cout << "For double: " << sizeof(p2) << endl;
    cout << "For char: " << sizeof(p3) << endl;
    cout << "For float: " << sizeof(p4) << endl;
    cout << "For struct Rectangle: " << sizeof(p5) << endl;

    return 0;
}