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
    // printf("\n Get address function and function parameter is : %c ", c);
    Gnode *temp=start;
    
    while (temp)
    {
        // printf("\n in loop %c", temp->data);
        if(temp->data==c)
            break;
        temp=temp->next;
    }
    // printf("\n Get address function over and temp data is : %c", temp->data);
    return temp;
}
void printGraph(Gnode *temp)
{
    printf("\n printGraph function");
    Nnode *ntemp;

    while(temp!=NULL)
    {
        printf("\n NODE %c : ",temp->data);

        ntemp=temp->Nlist;
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
    temp->next=NULL;
    temp->Nlist=NULL;
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
    deleteGnode(getGadd(c));
}
void deleteEdge(char from, char to)
{
    // printf("\n from %c  to %c",from,to );
    // printf("\n Edge deletion function");

    Gnode *temp=getGadd(from);
    Gnode *toAdd=getGadd(to);
    if(temp==NULL)
        printf(" Address is NULL");
    // printf("\n Address recieved from getGadd function");
    // printf("\n temp data %c",temp->data);
    // printf("\n toAdd data %c",toAdd->data);
    

    Nnode *mover=temp->Nlist;
    /*
    if (mover==NULL)
        printf("\n Its NULL");
    else
        printf("\n Not NULL");
    */
    // printf("\n delay");
    if(mover->next ==NULL)
    {
        free(mover); temp->Nlist=NULL;
    }
    else
    {    
        while (mover->next->Gadd->data!=to)
        {
            
            mover=mover->next;
        }
        Nnode *del=mover->next;
        mover->next=mover->next->next;
        free(del); 
    }   
}
int main()
{
    edge g1[4]={{'A','B'},{'A','C'},{'B','A'},{'B','C'}};

    addEdge(g1[0]);
    addEdge(g1[1]);
    addEdge(g1[2]);
    addEdge(g1[3]);
    printGraph(start);
    // printf("\n 1");
    /*
        printf("\n %d",start);
        printf("\n%c",start->data);
        printf("\n%d",start->next);
        printf("\n%d",start->Nlist);
        printf("\n%d",start->Nlist->next);
        printf("\n%d",start->Nlist->Gadd);
        printf("\n%c",start->Nlist->Gadd->data);
    */
   
    deleteEdge('A','C');
    printGraph(start);
    // printf("\n 2");
    deleteEdge('A','B');
    printGraph(start);
    // printf("\n 3");
    deleteEdge('B','C');
    // printf("\n Edge deleted");
    printGraph(start);
    // printf("\n 4");
    deleteEdge('B','A');
    printGraph(start);
    // printf("\n5");
}