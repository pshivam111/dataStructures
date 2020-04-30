/*
Program for insertion sort.
date 18 Aug 2017
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
int s,i,j,temp;
 printf("\n Enter the size of array : ");
 scanf("%d",&s);

 int *ptr=(int*) malloc(s*(sizeof(int)));

 printf(" Enter array elements");
 for(i=0;i<s;i++)
 {
 	scanf("%d",ptr+i);
 }

 printf(" Original array is : ");
  for(i=0;i<s;i++)
 {
 	printf("%d",*(ptr+i));printf(" ");
 }
printf("\n");
 for(i=1;i<s;i++)
 {
	for(j=0;j<i;j++)
	{
	if(*(ptr+j)>*(ptr+i))
		{temp=*(ptr+i); *(ptr+i)=*(ptr+j);*(ptr+j)=temp; }
	}
 printf("\n");
 printf(" Array after %dth pass : ",i);
  for(int k=0;k<s;k++)
 {
 	printf("%d",*(ptr+k));printf(" ");
 }

 } 

printf("\n");
 printf(" Sorted array is : ");
  for(i=0;i<s;i++)
 {
 	printf("%d",*(ptr+i));printf(" ");
 }

printf("\n");
free(ptr);
return 3;
}
