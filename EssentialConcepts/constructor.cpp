#include <stdio.h>
#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    //Rectangle(int l, int w);
    Rectangle();
    void init(int a, int b);
    int area();
    int perimeter();
    int getLength()
    {
        return length;
    };
    void setLength(int l)
    {
        length = l;
    };
    ~Rectangle();
};

Rectangle::Rectangle()
{
    this->length = length;
    this->width = width;
}

void Rectangle::init(int a, int b)
{
    length = a;
    width = b;
}

/*Rectangle::Rectangle(int l, int w)
{
    length = l;
    width = w;
}*/
int Rectangle::area()
{
    return length * width;
}
int Rectangle::perimeter()
{
    return 2 * (length + width);
}
Rectangle::~Rectangle(){};

int main()
{
    Rectangle();
    Rectangle b;
    b.init(4, 5);

    cout << b.area() << endl;
    cout << b.getLength() << endl;
    cout << b.perimeter() << endl;
    // Rectangle(5, 8);
    // do what you want;
    return 0;
}