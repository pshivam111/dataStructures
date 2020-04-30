/*
Program for selection sort
Just for remembering the selection sort 
Date 25 Aug 2017
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int s;
 printf("\n Enter the size of an array : ");
 scanf("%d",&s);

 int *ptr=(int*) malloc(s*(sizeof(int)));

 printf(" Enter array elements");
 for(int i=0;i<s;i++)
 {
 	scanf("%d",ptr+i);
 }

 int min,temp,pos;
 for(int i=0;i<(s-1);i++)
 { min=*(ptr+i);pos=i;
	for(int j=i+1;j<s;j++)
	{
	if(*(ptr+j)<min)
		{ min=*(ptr+j);pos=j;}
	}
   temp=*(ptr+i);
   *(ptr+i)=min;
   *(ptr+pos)=temp;
printf("\n Array after %dth pass",i);
for(int i=0;i<s;i++)
 {
 	printf("%d",*(ptr+i));printf(" ");
 }
	
 }
 
 printf("\n Array after sorting is ");
 for(int i=0;i<s;i++)
 {
 	printf("%d",*(ptr+i));printf(" ");
 }
free(ptr);
printf("\n");
return 0;
}

