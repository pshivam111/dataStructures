struct qnode
{
  void *data;
  struct qnode *next;
}*frOnt=NULL,*rEar=NULL;	//HERE front and rear are GLOBAL VARIABLE FOR THAT PARTICULAR STACK

void enqueue(void *x)
{
	if(rEar==NULL)
	{
		rEar=(struct qnode*) malloc(sizeof(struct qnode));
		rEar->data=x;
		rEar->next=NULL;
		frOnt=rEar;
	}
	else
	{
		struct qnode *temp=(struct qnode*) malloc(sizeof(struct qnode));
		temp->next=NULL;
		temp->data=x;
		rEar->next=temp;
		rEar=temp;
		
	}
}

int dequeue()
{
	if(frOnt==NULL)
	{
		return -1;
	}
	else
	{
		struct qnode *temp=frOnt;
		frOnt=frOnt->next;
		void *a=temp->data;
		free(temp);
		return a;		
		
	}
}
