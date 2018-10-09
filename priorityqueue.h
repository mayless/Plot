#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000000

typedef struct PQUEUE priority_q;
typedef struct NODE node;
struct NODE
{
    long long int element;
    long long int priority;
    node* next;
};
struct PQUEUE
{
    node* head;
};

priority_q* create_p_q();

void enqueuepq(priority_q* priority_queue,long long int element,long long int pr);

long long int searchpq(priority_q* priority_queue,long long int element);

node* dequeue(priority_q* priority_queue);

long long int maximum(priority_q* priority_queue);

long long int get_comppq();

#endif