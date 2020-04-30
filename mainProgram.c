#include<stdio.h>
#include<stack.h>
#include<queue.h>
#include<stdlib.h>
#include"node.h"
#include"graphFunctions.h"
void deapthFirstSearchPrint( Gnode *a)
{

}
int main()
{
    edge g1[8]={{'A','B'},{'A','C'},{'B','A'},{'B','C'},{'C','B'},{'D','A'},{'D','B'},{'D','C'}};

    addEdge(g1[0]);
    addEdge(g1[1]);
    addEdge(g1[2]);
    addEdge(g1[3]);
    addEdge(g1[4]);
    addEdge(g1[5]);
    addEdge(g1[6]);
    addEdge(g1[7]);
    printGraph(start);

deleteNode('D');

printGraph(start);

}