#include <iostream>
#include <stdio.h>

using namespace std;

// actually we dont need typedef in C++
typedef struct rectangele
{
    int length;
    int width;
} Rect;

int main()
{
    Rect myRect = {13, 5};
    cout << myRect.length << " " << myRect.width << endl;

    Rect *heapRect;
    //malloc function returns a pointer to the allocated memory
    heapRect = (Rect *)malloc(sizeof(Rect));
    heapRect->length = 7;
    cout << heapRect->length << endl;
    (*heapRect).width = 4; // (*p). = p->
    cout << heapRect->width << endl;

    return 0;
}