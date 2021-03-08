#include <stdio.h>
#include <iostream>

using namespace std;

// all data public by default
struct Rectangle
{
    int width;
    int length;

    void initialize(int w, int l)
    {
        width = w;
        length = l;
    }
    int area()
    {
        return length * width;
    }
    int perimeter()
    {
        return 2 * (width + length);
    }
};

// all data private by default
class RectangleC
{
public:
    int width;
    int length;

    void initialize(int w, int l)
    {
        width = w;
        length = l;
    }
    int area()
    {
        return length * width;
    }
    int perimeter()
    {
        return 2 * (width + length);
    }
};

int main()
{
    struct Rectangle r = {5, 10};
    struct Rectangle user;

    RectangleC r2 = {6, 7};
    RectangleC user2;

    cout << "STRUCT" << endl;
    cout << "area: " << r.area() << endl;
    cout << "perimeter: " << r.perimeter() << endl;

    int w, l;
    cout << "Your turn, width and length: " << endl;
    cin >> w >> l;
    user.initialize(w, l);
    cout << "area: " << user.area() << endl;
    cout << "perimeter: " << user.perimeter() << endl;

    cout << "*********************************" << endl;

    cout << "CLASS" << endl;
    cout << "area: " << r2.area() << endl;
    cout << "perimeter: " << r2.perimeter() << endl;

    cout << "Your turn, width and length: " << endl;
    cin >> w >> l;
    user2.initialize(w, l);
    cout << "area: " << user2.area() << endl;
    cout << "perimeter: " << user2.perimeter() << endl;

    return 0;
}