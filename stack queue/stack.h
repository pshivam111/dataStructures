struct node
{
  void *data;
  struct node *next;
}*tOp=NULL;	//HERE TOP IS A GLOBAL VARIABLE FOR THAT PARTICULAR STACK


//________________________________________________________________________
void push(void *x)
{
	if(tOp==NULL)
	{
		tOp=(struct node*) malloc(sizeof(struct node));
		tOp->data=x;
		tOp->next=NULL;
	}
	else
	{
		struct node *temp=(struct node*) malloc(sizeof(struct node));
		temp->next=tOp;
		temp->data=x;
		tOp=temp;
	}
}

//________________________________________________________________________
void * pop()
{
	if(tOp==NULL)
	{
		return NULL;
	}
	else
	{
		struct node *temp=tOp;
		tOp=tOp->next;
		void *a=temp->data;
		free(temp);
		return a;
	}
}

int Emptystack()
{
	return (tOp==NULL);
}