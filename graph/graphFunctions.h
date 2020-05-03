Gnode *createGnode(char c)
{
    Gnode *temp =(Gnode *) malloc(sizeof(Gnode));
    temp->data=c;
    temp->visited=0;
    temp->next=NULL;
    temp->Nlist=NULL;
    return  temp;
}
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

    //if it exist then store its address if dosen exist then create node 
    //and store data.
    //search for a node with data =e.to
    //if it exists then store its address if dosent exist then creat node
    //and store data
    
    //if both are not null then add to node in the neighbour list of from node
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