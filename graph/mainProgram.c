#include<stdio.h>
#include"stack.h"
#include"queue.h"
#include<stdlib.h>
#include"node.h"
#include"graphFunctions.h"

void inspectDFS(Gnode *a)
{
    Nnode *mover;

    if (a!=NULL)
    {
        printf(" %c ",a->data);
        (a->visited)++;
        mover=a->Nlist; 
        while(mover!=NULL)
        {   
            if(mover->Gadd->visited==0)
                push(mover->Gadd);
            mover=mover->next;
        }
    }    
}
void inspectBFS(Gnode *a)
{
    Nnode *mover;
    printf("inside inspectBFS");
    if (a!=NULL)
    {
        printf(" %c ",a->data);
        (a->visited)++;
        mover=a->Nlist; 
        while(mover!=NULL)
        {   
            printf("\n inside mover");
            if(mover->Gadd->visited==0)
                {
                    printf("\n New node %c :",mover->Gadd->data);
                enqueue(mover->Gadd);
                printf("\n Q size : %d ",qSize());
                }
            mover=mover->next;
            // printf("\n Q size : %d ",qSize());
        }
    }    
    printf("\n First node completeluy inspected");
    printf("\n Q size : %d ",qSize());
}
void breadthFirstSearchPrint(Gnode *a)
{
    printf("\n Breadth First Search");
    Gnode *tra;
    enqueue(a);
    printf("\n enqueue done");
    while(!Emptyqueue())
    {printf("\n Inside inspection while");
        tra=dequeue();
        inspectBFS(tra);
        printf("\n Q size : %d ",qSize());
    }   
}
void deapthFirstSearchPrint( Gnode *a)
{
    printf("\n Deapth FIrst Search : ");
    Gnode *tra;
    push(a);
    while(!Emptystack())
    {
        tra=pop();
        inspectDFS(tra);
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
    breadthFirstSearchPrint(start);

}
