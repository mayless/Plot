#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "priorityqueue.h"
#define MAX_SIZE 1000000

long long int compnumber = 0;

priority_q* create_p_q()
{
    priority_q* p_q = (priority_q*) malloc(sizeof(priority_q));
    node *new = (node*) malloc(sizeof(node));
    new->priority = 0;
    p_q->head = new;
    return p_q;
}

void enqueuepq(priority_q* priority_queue,long long int element,long long int pr)
{
    node *new = (node*) malloc(sizeof(node));
    new->element = element;
    new->priority = pr;
    if((priority_queue->head != NULL) && (pr > priority_queue->head->priority))
    {
        new->next = priority_queue->head;
        priority_queue->head = new;
        //printf("here\n");
    }
    else
    {
        node* now = priority_queue->head;
        while((now->next != NULL) && (now->next->priority > pr))
        {
            now = now->next;
        }
        new->next = now->next;
        now->next = new;
    }
}

long long int searchpq(priority_q* priority_queue,long long int element)
{
   if((priority_queue->head == NULL))
    {
        printf("Underflow\n");
        return 0;
    }
    else{
        while((priority_queue->head->next != NULL))
        {
            if((priority_queue->head->element) == element)
            {
                compnumber++;
                return 1;
            }
            else
            {
                compnumber++;
                priority_queue->head = priority_queue->head->next;
            }
        }
    }
}

node* dequeue(priority_q* priority_queue)
{
    if((priority_queue->head == NULL))
    {
        printf("Underflow\n");
        return NULL;
    }
    else{
        node* aux = priority_queue->head;
        priority_queue->head = priority_queue->head->next;
        aux->next = NULL;
        return aux;
    }
}

long long int maximum(priority_q* priority_queue)
{
    if(priority_queue->head == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else{
        return priority_queue->head->element;
    }
}

long long int get_comppq()
{
    return compnumber;
}