/*
Library for graph implementation in c
This file contain graph functions.
By Shivam Patil
email: shivam.patil16@vit.edu
*/

//-----------------------------------------------FUNCTION TO CREATE NODE--------------------------------------------
Gnode *createGnode(char c)
{
    Gnode *temp =(Gnode *) malloc(sizeof(Gnode));
    temp->data=c;
    temp->visited=0;
    temp->next=NULL;
    temp->Nlist=NULL;
    return  temp;
}

//---------------------------------------FUNCTION TO GET ADDRESS OF A NODE------------------------------------
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

//------------------------------------FUNCTION TO 'MAKE 'B' AS 'A''s NEIGHBOUR---------------------------------
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

//----------------------------FUNCTION TO REMOVE A PARTICULAR NEIGHBOUR------------------------------
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
            int i=0;    
            while(1)
            {              
                m2=m1;
                m1=m1->next;
                if(m1==NULL)
                    break;
                if(m1->Gadd==f )
                {
                    m2->next=m1->next;
                    free(m1);
                    break;
                }
                i++;
            }
        }      
    }    
}

//--------------------------------------FUNCTION TO DELETE ALL NEIGHBOUR-------------------------------------
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
        node->Nlist=NULL;
    }
}

//----------------------------------------FUNCTION TO DELETE A NODE------------------------------------------------
void deleteGnode(Gnode *a)
{
    Gnode *mover=start,*premover=NULL;
    while(mover!=NULL)
    {
        if(mover!=a)
        {            
            filterNeighbour(mover,a);
        }
        premover=mover;
        mover=mover->next;
    }
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

//----------------------------------------FUNCTION TO DELETE A NODE------------------------------------------------ 
void deleteNode(char c)
{
    deleteGnode(getGadd(c));
}

//--------------------------FUNCTION TO DELETE A PARTICULAR EDGE FROM GRAP-----------------------
void deleteEdge(char from, char to)
{
    Gnode *temp=getGadd(from);
    Gnode *toAdd=getGadd(to);
    if(temp==NULL)
        printf(" Address is NULL");

    Nnode *mover=temp->Nlist;

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

}//----------------------------------A SUB FUNCTION ----------------------------------------------------------
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

void inspectDFS(Gnode *a)
{
    Nnode *mover;
    if (a!=NULL)
    {   printf(" %c ",a->data);
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
    if (a!=NULL)
    {
        printf(" %c ",a->data);
        (a->visited)++;
        mover=a->Nlist; 
        while(mover!=NULL)
        {   
            if(mover->Gadd->visited==0)
                {
                    enqueue(mover->Gadd);                
                }
            mover=mover->next;
        }
    }    
}
void breadthFirstSearchPrint(Gnode *a)
{
    printf("\n Breadth First Search");
    Gnode *tra;
    enqueue(a);
    while(!Emptyqueue())
    {   tra=dequeue();
        inspectBFS(tra);
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