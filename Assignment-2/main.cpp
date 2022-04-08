#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

using namespace std;

/*  @Author
    Student Name: Sakine Büşra Göçmez
    Student ID: 150190064
    Date: 12.6.2020
*/

void circuit::create()
{
    head = NULL;
}

void list::list_create()
{
    head = NULL;
}
// print our perfectly ordered list.
void list::print_list()
{
    element *n;
    n = head;

    while (n)
    {
        cout << n->value << ":" << n->quantity << endl;
        n = n->next;
    }
}
/* is_in function checks whether the given value is already exists in the output list. If yes, it increases
    the quantity of that groupname by the given quantity and returns true. If not already in, it returns false.
*/
bool list::is_in_list(float v, int q)
{
    element *node;
    node = head;

    bool already_in = false;
    while (node)
    {
        if (v == node->value)
        {
            node->quantity += q;
            already_in = true;
            break;
        }
        node = node->next;
    }
    return already_in;
}
// this function is very similar with add_resistor function.
void list::add_list(float val, int quantity)
{
    // check whether the value is already in the output list.
    if (is_in_list(val, quantity))
    {
        return;
    }

    element *toadd = new element;
    toadd->value = val;
    toadd->quantity = quantity;
    toadd->next = NULL;

    element *traverse, *previous;
    traverse = head;

    if (traverse == NULL)
    {
        head = toadd;
        return;
    }
    int i = 0;
    // this is for order
    while (traverse && traverse->value < toadd->value)
    {
        previous = traverse;
        traverse = traverse->next;
        i++;
    }
    // add to head
    if (i == 0)
    {
        toadd->next = head;
        head = toadd;
    }
    // add between
    else if (traverse)
    {
        toadd->next = traverse;
        previous->next = toadd;
    }
    // add to end
    else
    {
        previous->next = toadd;
    }
}

void circuit::sort_and_print_by_value()
{
    resistor *node;
    node = head;

    list l;
    l.list_create();

    // we add circuits' resistors to ouput list
    while (node)
    {
        l.add_list(node->value, node->quantity);
        node = node->next;
    }
    l.print_list();
}

void circuit::circuit_info()
{
    resistor *node;
    node = head;

    float total_r = 0;
    // total_resistance is found.
    while (node)
    {
        node->equivalent = node->value / node->quantity;
        total_r += node->equivalent;
        node = node->next;
    }
    sort_and_print_by_value(); // sort by value and print operations done here.
    cout << "Total resistance=" << total_r << " ohm" << endl;
}
/* already_in function checks whether the given groupname is already exists in the circuit. If yes, it increases
    the quantity of that groupname by one and returns true. If not already in, it returns false.
*/
bool circuit::already_in(char group)
{
    resistor *node;
    node = head;

    bool already_in = false;
    while (node)
    {
        if (group == node->group)
        {
            node->quantity++;
            already_in = true;
            break;
        }
        node = node->next;
    }
    return already_in;
}

void circuit::add_resistor(char resistor_group, float resistor_value)
{
    if (already_in(resistor_group)) // if to be added group name is already in the circuit : pass. (check the already_in fnct)
    {
        return;
    }

    resistor *toadd = new resistor;
    toadd->group = resistor_group;
    toadd->value = resistor_value;
    toadd->next = NULL;

    resistor *traverse, *previous;
    traverse = head;
    // if circuit is empty : add theadd to the beginning and return
    if (traverse == NULL)
    {
        head = toadd;
        return;
    }
    int i = 0;
    // go until the proper groupname moment.
    while (traverse && strcmp(&traverse->group, &toadd->group) < 0)
    {
        previous = traverse;
        traverse = traverse->next;
        i++;
    }
    // this means that the toadd.groupname should be at the beginning, never go into the loop. (i == 0). add it.
    if (i == 0)
    {
        toadd->next = head;
        head = toadd;
    }
    // we are in the middle (traverse is not NULL). add it
    else if (traverse)
    {
        toadd->next = traverse;
        previous->next = toadd;
    }
    // we are at the end. add it
    else
    {
        previous->next = toadd;
        toadd->next = NULL;
    }
}
// deleted_group_name is the group which is gonna be deleted
void circuit::delete_resistor(char deleted_group_name)
{
    resistor *node, *previous;
    node = head;
    previous = node;

    while (node)
    {
        // we find the groupname, it is not at the beginning and not at the end.
        if (node->group == deleted_group_name && node != head && node->next != NULL)
        {
            // groupname'before is no more links it. it links the should_be_deleted_groupname.next.
            previous->next = node->next;
            return;
        }
        // we find groupname and it is at the beginning
        else if (node->group == deleted_group_name && node == head)
        {
            head = node->next;
            return;
        }
        // we find the groupname and it is in the end
        else if (node->group == deleted_group_name && node->next == NULL)
        {
            previous->next = NULL;
            return;
        }
        previous = node;
        node = node->next;
    }
}

void circuit::remove_resistor(char groupname)
{
    resistor *node;
    node = head;

    while (node)
    { // if groupname exists and quantity is 1, it should be deleted : 1 - 1 = 0
        if (node->group == groupname && node->quantity == 1)
        {
            delete_resistor(groupname);
            return;
        } // if groupname exists and quantity is bigger than 1, it should be decreased by 1.
        else if (node->group == groupname && node->quantity > 1)
        {
            node->quantity--;
            return;
        }
        node = node->next;
    } // if not exists, print NO_RESISTOR. Note that we RETURNed in the conditional statements of while. They wont come here.
    cout << "NO_RESISTOR" << endl;
}

void circuit::clear()
{
    resistor *p;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

int main(int argc, char *argv[])
{
    resistor r;
    circuit crc;
    crc.create();

    FILE *file = fopen(argv[1], "r");
    if (file)
    {
        while (!feof(file))
        {
            fscanf(file, "%c %f\n", &r.group, &r.value);
            // if 0 : pass to circuit info to get resistor info and print output screen
            if (r.value == 0)
            {
                crc.circuit_info();
            }
            else if (r.value > 0) // if > 0 : add resistor to circuit
            {
                crc.add_resistor(r.group, r.value);
            }
            else // if < 0 : pass to remove function
            {
                crc.remove_resistor(r.group);
            }
        }
    }
    else
    {
        cout << "File cannot be opened!" << endl;
    }
    crc.clear();
    return 0;
}