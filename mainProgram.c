#include<stdio.h>
#include<stdlib.h>
#include"node.h"

struct edge
{
    char from;
    char to;
};
typedef struct edge edge;

Gnode *getGadd(char c)
{
    Gnode *temp=start;
    while (temp)
    {
        temp=temp->next;
        if(temp->data=c)
            break;
    }
    return temp;
}
void printGraph(Gnode *temp)
{
    Nnode *ntemp;
    while(temp!=NULL)
    {
        ntemp=temp->Nlist;
        printf("\n NODE %c : ",temp->data);
        while (ntemp!=NULL)
        {
            printf("-> %c ",ntemp->Gadd->data);
            ntemp=ntemp->next;
        }
        temp=temp->next;
    }
}
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
Gnode *createGnode(char c)
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
void  addEdge(edge e)
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
void deleteGnode(Gnode *a)
{
    Gnode *mover=start;
    Nnode *m1,*m2;
    while(mover)
    {
        if(mover==a)
        {
            Gnode *temp=mover;
            mover=mover->next;
            m1=temp->Nlist;
            free(temp);
            m2=m1;
            m1=m1->next;
            while (m1)
            {
                free(m2);
                m2=m1;
                m1=m1->next;
            }
            free(m2);
        }
        else
        {
            m1=mover->Nlist;
            while(m1->next->Gadd!=a&&m1)
            {
                m1=m1->next;
            }
            m2=m1->next;
            m1->next=m1->next->next;
            free(m2);
            mover=mover->next;
        }
        
    }
    
    
}

void deleteNode(char c)
{
    deleteGnode(getGadd(c))
}
void deleteEdge(char from, char to)
{
    Gnode *temp=getGadd(from);
    Nnode *mover=temp->Nlist;
    while (mover->next->Gadd->data!=to)
    {
        mover=mover->next;
    }
    Nnode *del=mover->next;
    mover=mover->next->next;
    free(del);    
}
int main()
{
    edge g1[4]={{'A','B'},{'A','C'},{'B','A'},{'B','C'}};

    addEdge(g1[0]);
    addEdge(g1[1]);
    addEdge(g1[2]);
    addEdge(g1[3]);
    /*
        printf("\n %d",start);
        printf("\n%c",start->data);
        printf("\n%d",start->next);
        printf("\n%d",start->Nlist);
        printf("\n%d",start->Nlist->next);
        printf("\n%d",start->Nlist->Gadd);
        printf("\n%c",start->Nlist->Gadd->data);
    */

    printGraph(start);
    printf("\n");
}