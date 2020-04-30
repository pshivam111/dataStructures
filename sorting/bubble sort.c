/*
Program for bubble sort
Just for remembering the bubble sort 
Date 26 Aug 2017
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
int s,temp;
 printf("\n Enter the size of array : ");
 scanf("%d",&s);

 int *ptr=(int*) malloc(s*(sizeof(int)));

 printf(" Enter array elements");
 for(int i=0;i<s;i++)
 {
 	scanf("%d",ptr+i);
 }

 printf(" Original array is : ");
  for(int i=0;i<s;i++)
 {
 	printf("%d",*(ptr+i));printf(" ");
 }

 

 for(int i=0 ;i<s-1;i++)
 {
   for(int j=0;j<(s-i-1);j++)
	{
	if(*(ptr+j)>*(ptr+j+1))
		{temp=*(ptr+j);*(ptr+j)=*(ptr+j+1); *(ptr+j+1)=temp;}
	}

   printf("\n Array after %dth pass : ",i);
   for(int x=0;x<s;x++)
 {
 	printf("%d",*(ptr+x));printf(" ");
 }

 }

printf("\n");
free(ptr);
return 0;
}

