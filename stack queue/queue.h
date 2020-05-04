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
		struct qnode *te_mp=(struct qnode*) malloc(sizeof(struct qnode));
		te_mp->next=NULL;
		te_mp->data=x;
		rEar->next=te_mp;
		rEar=te_mp;
		
	}
}

void *dequeue()
{
	if(frOnt==NULL)
	{
		return NULL;
	}
	else
	{
		struct qnode *teMp=frOnt;
		frOnt=frOnt->next;
		if(frOnt==NULL)
			rEar=NULL;
		void *a=teMp->data;
		free(teMp);
		return a;		
		
	}
}

int Emptyqueue()
{
	return (frOnt==NULL||rEar==NULL);
}

int qSize()
{
struct qnode *tempO=frOnt;
int i=0;
while(tempO!=NULL)
	{
		
		i++;
//		printf("\n Variable i : %d",i);
		tempO=tempO->next;
	}
return i;
}
