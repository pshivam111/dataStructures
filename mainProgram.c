#include<stdio.h>
#include"node.h"

struct edge
{
    char from;
    char to;
};
typedef struct edge edge;

void attachGnode(Gnode *node)
{
    if (start==NULL)
        start=node;
    else
    {
        Gnode *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=node;
        temp->next->next=NULL;
    }
}
void addNeighbour(Gnode *a, Gnode *b)
{
    Nnode *node=(Nnode *)malloc(sizeof(Nnode)),*temp;
    node->Gadd=b;
    node->next=NULL;

    
    if (a->Nlist==NULL)
        a->Nlist=node;
    else
    {
        temp=a->Nlist;
        while (temp->next!=NULL)         
            temp=temp->next;
        temp->next=node;
    }
    
    
    
}
Nnode *createGnode(char c)
{
    Gnode *temp =(Gnode *) malloc(sizeof(Gnode));
    temp->data=c;
    return  temp;
}
Gnode *searchGnode(char c)
{
    if (start==NULL)
        return NULL;
    else
    {
        Gnode *temp=start;
        while (temp!=NULL)
        {
            if (temp->data==c)
                break;
            else
                temp=temp->next;     
        }
        return temp;
    
    }
    
    
}
Gnode *addGnode(edge e)
{
    //search for a note with data = e.from
    Gnode *firstnode,*secondnode;;
    firstnode=searchGnode(e.from);
    secondnode=searchGnode(e.to);
    
    if (firstnode==NULL)
    {
        firstnode=createGnode(e.from);
        attachGnode(firstnode);
    }
    if (secondnode==NULL)
    {
        secondnode=createGnode(e.to);
        attachGnode(secondnode);
    }
    
    addNeighbour(firstnode,secondnode);

    //if it exist then store its address if dosen exist then create node 
    //and store data.

    //search for a node with data =e.to

    //if it exists then store its address if dosent exist then creat node
    //and store data
    

    //if both are not null then add to node in the neighbour list of from node
}
int main()
{
    edge g1[4]={{'A','B'},{'A','C'},{'B','A'},{'B','C'}};

    
}