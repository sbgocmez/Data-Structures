#include "data_structs.h"

/*  @Author
    Student Name: Sakine Büşra Göçmez
    Student ID: 150190064
    Date: 1.8.2020
*/

// Stack functions
void Stack::init()
{
    head = NULL;
}

void Stack::close()
{
    Subtask *iter;
    while (head != NULL)
    {
        iter = head;
        head = head->next;
        delete iter;
    }
}

bool Stack::isEmpty()
{
    return (head == NULL) ? true : false;
}

// we have isEmpty() but i want to be more general.
void Stack::push(Subtask *in)
{
    Subtask *toadd = new Subtask;
    toadd->name = in->name;
    toadd->duration = in->duration;
    toadd->next = NULL;

    // bossa
    /*if (isEmpty())
        head = toadd;
    else
    {*/
        toadd->next = head;
        head = toadd;
    //}
}

Subtask *Stack::pop()
{
    // bossa NULL döncek
    /*if (isEmpty())
        return head;*/
    Subtask *iter = new Subtask;
    Subtask *temp;
    temp = head;

    iter->name = head->name;
    iter->duration = head->duration;
    iter->next = NULL;
    head = head->next;

    delete temp;
    return iter;
}

// Queue functions
void Queue::init()
{
    head = NULL;
    tail = NULL;
}

void Queue::close()
{
    Process *p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

bool Queue::isEmpty()
{
    return (head == NULL) ? true : false;
}

void Queue::queue(Process *in)
{
    Process *newprocess = new Process;
    newprocess = in;
    newprocess->next = NULL;

    if (isEmpty())
    {
        tail = newprocess;
        head = tail;
    }
    else
    {
        tail->next = newprocess;
        tail = newprocess;
    }
}


Process* Queue::dequeue()
{
    Process *first = new Process;
    first->task_stack.init();
    first->priority = head->priority;
    first->name = head->name;
    first->task_stack = head->task_stack;
    first->task_count = head->task_count;
    Process *temp = head;
    head = head->next;
    delete temp;
    return first;
}

Process *Queue::front()
{
    return head;
}

int Queue::processlerin_beklenen_bitme_sureleri_toplami()
{
    int return_val = 0;
    Process *iter = head;
    while (iter)
    {
        return_val += iter->beklenen_bitme_sureleri_toplami();
        iter = iter->next;
    }
    return return_val;
}

// MultiQueue functions
void MultiQueue::init()
{
    queues[0].init();
    queues[1].init();
    queues[2].init();
}

void MultiQueue::close()
{
    queues[0].close();
    queues[1].close();
    queues[2].close();
}

void MultiQueue::queue(Process *in)
{
    int index = in->priority - 1;
    queues[index].queue(in);
}

Process *MultiQueue::front(int priority)
{
    int index = priority - 1;
    return queues[index].front();
}

Process* MultiQueue::dequeue(int priority)
{
    queues[priority].dequeue();
    int pr = priority - 1;
    Process* a = queues[pr].dequeue();
    return a;
}

bool MultiQueue::isEmpty()
{
    return (queues[0].isEmpty() && queues[1].isEmpty() && queues[2].isEmpty());
}

// Process function
int Process::beklenen_bitme_sureleri_toplami()
{
    int return_val = arrival_time;
    Subtask *iter = task_stack.head;
    while (iter != NULL)
    {
        return_val += iter->duration;
        iter = iter->next;
    }
    return return_val;
}
