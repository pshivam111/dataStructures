#include<stdio.h>
#include<iostream>
#include"stack.h"
#include"queue.h"
#include<stdlib.h>
#include"node.h"
#include"graphFunctions.h"
using namespace std;
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
    
     deapthFirstSearchPrint(start);
    // breadthFirstSearchPrint(start);
    
}
