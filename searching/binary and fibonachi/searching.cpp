#include<iostream>
#include<stdlib.h>
using namespace std;

int fiboS(int array[], int x, int n)
{
    int n2 = 0;   
    int n1 = 1;  
    int N = n2 + n1;  

    while (N < n)
    {
        n2 = n1;
        n1 = N;
        N  = n2 + n1;
    }

    int offset = -1;

    while (N > 1)
    {
        int i = min(offset+n2, n-1);

        if (array[i] < x)
        {
            N  = n1;
            n1 = n2;
            n2 = N - n1;
            offset = i;
        }

        else if (array[i] > x)
        {
            N = n2;
            n1 = n1 - n2;
            n2 = N - n1;
        }

        else return i;
    }

    if(n1 && array[offset+1]==x)return offset+1;

    return -1;
}

int main()
{
    int array[100];
    cout<<"Enter array length :";
    int n;
    cin>>n;
    cout<<"Enter array elements :";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<"\nInput array of length "<<n<<" is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl<<"Enter a no. to search for :";
    int num;
    cin>>num;
    cout<<"Enter your choice:"<<endl;
    cout<<"1) Binary Search "<<endl;
    cout<<"2) Fibonacci Search "<<endl;
    int choice;
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            int l=0,mid,u=n-1;
            mid = (u+l)/2;
            while(l<=u)
            {
                if(num>array[mid])
                {
                    l = mid+1;
                }
                if(num<array[mid])
                {
                    u=mid -1;
                }
                if(num==array[mid])
                {
                    cout<<"The element was found at :"<<(mid+1);
                    break;
                }
                mid = (u+l)/2;
            }
            if(l>u)
            {
                cout<<"The no. was not found."<<endl;
            }
        }
    case 2:
        {
            int index = fiboS(array, num, n);
            if(index==(-1))
            {
              cout<<"Element not found";
            }
            else
              cout<<"Element found at position : "<<index<<endl;
        }
    }
    return 0;
}


