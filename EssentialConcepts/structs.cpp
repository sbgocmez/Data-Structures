#include <iostream>
#include <stdio.h>

using namespace std;

//1. this is also variable decleration (global)
/*struct Rectangle
{
    int width;
    int length;
} r1, r2, r3;
*/

//2. also this (global).
/*struct Rectangle
{
    int width;
    int length;
};

struct Rectangle r1, r2, r3;
*/

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    struct Rectangle r1, r2, r3;
    r1 = {12, 3};
    r2 = {4, 5};
    r3 = {7, 8};

    cout << r1.length << " " << r1.width << endl;
    cout << r2.length << " " << r2.width << endl;
    cout << r3.length << " " << r3.width << endl;

    return 0;
}