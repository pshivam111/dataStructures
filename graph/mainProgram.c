#include<stdio.h>
#include"stack.h"
#include<queue.h>
#include<stdlib.h>
#include"node.h"
#include"graphFunctions.h"

void inspect(Gnode *a)
{
    Nnode *mover;

    if (a!=NULL)
    {
        printf(" %c ",a->data);
        mover=a->Nlist; 
        while(mover!=NULL)
        {   
            push(mover->Gadd);
            mover=mover->next;
        }
    }    
}
void deapthFirstSearchPrint( Gnode *a)
{
    printf("\n Deapth FIrst Search : ");
    Gnode *tra;
    push(a);
    while(!Empty())
    {
        tra=pop();
        inspect(tra);
    }
}
int main()
{
    edge g1[8]={{'A','D'},{'A','C'},{'B','C'},{'B','E'},{'B','D'},{'D','B'},{'E','C'},{'C','A'}};

    addEdge(g1[0]);
    addEdge(g1[1]);
    addEdge(g1[2]);
    addEdge(g1[3]);
    addEdge(g1[4]);
    addEdge(g1[5]);
    addEdge(g1[6]);
    addEdge(g1[7]);

    printGraph(start);
    
    // deapthFirstSearchPrint(start);

}
