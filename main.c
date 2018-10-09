#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "priorityqueue.h"
#include "withheap.h"
#define MAX_SIZE 1000000

int main()
{
    priority_q* p_q = create_p_q();
    heap* heap = create_h();
    long long int numberofcomparisons = 0,number = 0,numberof = 0,randomN[MAX_SIZE];
    printf("Enter the quantity of Data Numbers you want to insert:\n");
    scanf("%Ld",&numberofcomparisons);
    for(number = 0; number <= numberofcomparisons; number++)
    {
       enqueuepq(p_q,number,number);
    }
   	for(number = 0; number <= numberofcomparisons; number++)
    {
        enqueuehp(heap,number);
    }
    long long int heapcomp = 0, priorityqcomp = 0, ran = 0,i = 0;
    FILE* archive;
    archive = fopen("Graficos.txt", "w");
    printf("How many numbers do you want to compare?\n");
    scanf("%Ld",&numberof);
    srand(time(NULL));
    for (i= 0; i < numberof; i ++)
    {
        ran = rand()%numberof;
        randomN[i] = ran;
        if(searchpq(p_q,randomN[i])) priorityqcomp = get_comppq();
        if(earchpq(heap,randomN[i])) heapcomp = get_comphp();
        fprintf(archive, "%lld\n", randomN[i]);
        /*StepsTree[i] = Comparations;
        result2 = searchavl(avl, var);
        StepsAVL[i] = ComparationsAVL;
        fprintf(arch, "%lld\n", StepsTree[i]);
        fprintf(arch, "%lld\n", StepsAVL[i]);
        Comparations = ComparationsAVL = 0;*/
    }
    fclose(archive);
    printf("Comparisons: %Ld\n",priorityqcomp);
    return 0;
}