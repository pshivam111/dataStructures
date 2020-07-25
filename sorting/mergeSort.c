#include<stdio.h>
int *mergeSort(int *arr, int n)
{
    if(n==1)
    {
        return arr;
    }
    else
    {

        int *arr1=mergeSort(arr,n/2)
        int  *arr2=mergeSort(arr+n/2+1,n/2);
    }
    
}
int main()
{

}