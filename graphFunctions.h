Gnode *createGnode(char c)
{
    Gnode *temp =(Gnode *) malloc(sizeof(Gnode));
    temp->data=c;
    temp->next=NULL;
    temp->Nlist=NULL;
    return  temp;
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