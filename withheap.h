#ifndef WITH_HEAP_H
#define WITH_HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000000

typedef struct HEAP heap;
struct HEAP 
{
    long long int size;
    long long int items[MAX_SIZE];
};

heap* create_h();

void enqueuehp(heap *heap, long long int element);

long long int dequeuehp(heap* heap);

void printf_heap(heap* heap);

long long int get_parent_i(heap* heap,long long int i);

long long int get_left_i(heap* heap,long long int i);

long long int get_right_i(heap* heap,long long int i);

void max_hfy(heap* heap,long long int i);

long long int element_of(heap* heap,long long int i);

void heapsort(heap* heap);

long long int get_comphp();

#endif