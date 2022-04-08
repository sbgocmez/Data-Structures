#pragma once

/*  @Author
    Student Name: Sakine Büşra Göçmez
    Student ID: 150190064
    Date: 12.6.2020
*/

struct resistor
{
    char group;
    float value;
    int quantity = 1;
    float equivalent = 0;
    resistor *next;
};

struct circuit
{
    resistor *head;
    void create();
    void add_resistor(char, float);
    void remove_resistor(char);
    void delete_resistor(char);
    void circuit_info();
    void clear();
    // i added
    bool already_in(char);
    void sort_and_print_by_value();
};

// I added these structs for output list.
struct element
{
    float value;
    int quantity;
    element *next;
};

struct list
{
    element *head;
    void list_create();
    void add_list(float, int);
    bool is_in_list(float, int);
    void print_list();
    void list_clear();
};