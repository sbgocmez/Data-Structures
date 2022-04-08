#include <iostream>

using namespace std;

struct element
{
    int data;
    element *next;
};

struct Linkedlist
{
    element *head;
    void create();
    void add2beginning(int);
    void clear();
    void print();
};

void Linkedlist::create()
{
    head = NULL;
};

void Linkedlist::clear()
{
    element *p;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void Linkedlist::add2beginning(int k)
{
    element *toadd = new element;
    toadd->data = k;
    toadd->next = NULL;
    //bossa
    if (head == NULL)
    {
        head = toadd;
        return;
    }

    toadd->next = head;
    head = toadd;
}

void Linkedlist::print()
{
    element *node;
    node = head;

    cout << "print" << endl;
    while (node)
    {
        cout << "node" << endl;
        cout << node->data << endl;
        node = node->next;
    }
}

int main()
{
    Linkedlist l;
    l.create();
    for (int i = 0; i < 4; i++)
        l.add2beginning(i);
    l.clear();
    cout << "here" << endl;
    l.print();
}