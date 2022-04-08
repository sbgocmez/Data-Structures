#pragma once
#include <iostream>
#include <string>

using namespace std;
/*  @Author
    Student Name: Sakine Büşra Göçmez
    Student ID: 150190064
    Date: 1.8.2020
*/
struct specialCondition
{
    bool is_active;
    int num_of_two;
};

struct Subtask
{
    string name;
    int duration;
    Subtask *next;
};

struct Stack
{
    Subtask *head;
    void init();
    void close();
    void push(Subtask *in);
    Subtask *pop();
    bool isEmpty();
};

struct Process
{
    string name;
    int arrival_time;
    int task_count;
    int priority;
    Stack task_stack;
    Process *next;
    // i added;
    int beklenen_bitme_sureleri_toplami();
    int clock = 0;
};

struct Queue
{
    Process *head;
    Process *tail;
    void init();
    void close();
    void queue(Process *in);
    Process* dequeue();
    bool isEmpty();
    Process *front();
    // i added
    int siradaki_elemanin_gelisi = -1;
    int processlerin_beklenen_bitme_sureleri_toplami();
};
struct MultiQueue
{
    Queue queues[3];
    void init();
    void close();
    void queue(Process *in);
    Process* dequeue(int priority);
    bool isEmpty();
    Process *front(int priority);
};
