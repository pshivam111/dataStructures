#include<stdio.h>
#include<queue.h>
int main()
{
	int p,q,r,s,t;
	int *a=&p,*b=&q,*c=&r,*d=&s,*e=&t;
	enqueue(a);
	enqueue(b);
	printf("\n Queue size : %d",qSize());
	int * temp=dequeue();
	printf("\n Queue size : %d",qSize());
}
