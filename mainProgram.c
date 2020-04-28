#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"graphFunctions.h"

void clearNeighbour(Gnode *node)
{
    if(node!=NULL)
    {
        Nnode *m1,*m2;
        m1=node->Nlist;
        while(m1)
        {
            m2=m1;
            m1=m1->next;
            free(m2);
        }
    }
}


void filterNeighbour(Gnode *H, Gnode *f)
{
    Nnode *m1,*m2;
    m1=H->Nlist;
    if(m1!=NULL)
    {
        if(m1->Gadd==f)
        {
            H->Nlist=m1->next;
            free(m1);
        } 
        else
        {
            m2=m1;
            m1=m1->next;
            while(1)
            {
                if(m1->Gadd==f )
                {
                    m2->next=m1->next;
                    free(m1);
                    break;
                }
                m2=m1;
                m1=m1->next;
            }
        }      
    }    
}




void deleteGnode(Gnode *a)
{
    Gnode *mover=start,*premover;
    if(mover->next==NULL)
    {
        if(mover==a)
        {
            clearNeighbour(a);
            free(mover);
            start=NULL;
        }
        else
        {
            filterNeighbour(mover,a);
        }
    }
    else
    {
        if(mover==a)
        {
            clearNeighbour(a);
            start=mover->next;
            free(mover);
        }
        else{
            premover=mover;
            mover=mover->next;
            while(mover!=NULL)
            {
                if(mover==a)
                {
                    clearNeighbour(a);
                    premover->next=mover->next;
                    free(mover);
                    mover=premover->next;
                }
                else
                {
                    filterNeighbour(mover,a);
                    premover=mover;
                    mover=mover->next;
                }
                
            }
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
   /*
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
    // printf("\n5");*/
     //deleteNode('D ');
    printGraph(start);
}