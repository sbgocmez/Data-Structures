#include <stdio.h>
#include <iostream>

using namespace std;

struct Person
{
    int age;
    char gender;
};

void initialize(struct Person *p, int age, char gender)
{
    p->age = age;
    p->gender = gender;
}

void printing(struct Person p)
{
    cout << "Your age is: " << p.age << " and your gender is: " << p.gender << endl;
}

int main()
{
    struct Person me = {20, 'F'};
    struct Person user;

    int a;
    char g;
    cout << "Your age and gender (M/F) please: " << endl;
    cin >> a >> g;
    printing(me);
    initialize(&user, a, g);
    printing(user);
    return 0;
}