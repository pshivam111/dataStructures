#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"graphFunctions.h"

void clearNeighbour(Gnode *node)
{
    // printf("\n Clear neighbour function called ");
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
        node->Nlist=NULL;
    }
}


void filterNeighbour(Gnode *H, Gnode *f)
{
    // printf("\n Filtering neighbour started");
    // printf("\n to be filtered %c",f->data);
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
            int i=0;    
            while(1)
            {
                //  printf("\n %d",i);
                
                m2=m1;
                m1=m1->next;
                if(m1==NULL)
                    break;
                if(m1->Gadd==f )
                {
                    // printf("\nInside if");
                    m2->next=m1->next;
                    free(m1);
                    break;
                }
                i++;
            }
        }      
    }    
}




void deleteGnode(Gnode *a)
{
    // printf("\n Inside Delete node function");
    Gnode *mover=start,*premover=NULL;
    
    // printf("\n%c",mover->data);
    // printf("\nclearNeighbour started");
    while(mover!=NULL)
    {
        // printf("\n Mover data%c",mover->data);
        // printf("\nFiltering Neighbour started");
        if(mover!=a)
        {
            // printf("\n other node detected");
            
            filterNeighbour(mover,a);
            // printf("\n filtering over");
        }
        premover=mover;
        mover=mover->next;
        // printf("\n Next node");
    }
    
    // printf("clearNeighbour done");
    mover=start;
    premover=NULL;

    if(mover==a)
    {
        start=mover->next;
        clearNeighbour(mover);
        free(mover);
    }
    else
    {
        while(1)
        {
            premover=mover;
            mover=mover->next;
            if(mover==a)
            {
                clearNeighbour(mover);
                premover->next=mover->next;
                free(mover);
                break;
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
    
     deleteNode('D');
     
    printGraph(start);
    
}