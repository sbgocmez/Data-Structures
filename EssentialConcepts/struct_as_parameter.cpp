#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct rectangle
{
    int length;
    int width;
} Rectangle;

// call by value
int area(Rectangle r)
{
    return r.length * r.width;
}

int area2(Rectangle *r)
{
    return r->length * r->width;
}

int change_area(Rectangle r)
{
    r.width = 9;
    return r.length * r.width;
}

int change_area_real(Rectangle *r)
{
    r->width = 9;
    return r->length * r->width;
}

Rectangle *create()
{
    Rectangle *r;
    r = new Rectangle;
    //r=(Rectangle*)malloc(sizeof(Rectangle));
    r->width = 7;
    r->length = 4;
}

int main()
{
    Rectangle myRect;
    myRect.length = 5;
    myRect.width = 10;

    Rectangle *rectHeap;
    rectHeap = create();

    cout << "Original heap rectangle area: " << area2(rectHeap) << endl;

    cout << "Original rectangle area: " << area(myRect) << endl;

    cout << "In function, Changed rectangle area but passed by value: " << change_area(myRect) << endl;

    cout << "Current rectangle area: " << myRect.width * myRect.length << endl;

    cout << "In function, Changed rectangle area but passed by address: " << change_area_real(&myRect) << endl;

    cout << "Current rectangle area: " << myRect.width * myRect.length << endl;

    return 0;
}