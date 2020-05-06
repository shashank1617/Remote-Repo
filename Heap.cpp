#include<bits/stdc++.h>
using namespace std;

void TopDownHeapify(int A[],int i,int n);

void swap(int A[],int i,int j)
{
    int temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

void Delete(int A[],int n)
{
    int temp=A[n-1];
    A[n-1]=A[0];
    A[0]=temp;
    n--;
    TopDownHeapify(A,0,n);
    
}

void BottomUpHeapify(int A[],int i)
{
    int parent=(i-1)/2;
    while(parent>=0)
    {
        if(A[parent]>A[i])
        {
            swap(A,parent,i);
            i=parent;
            parent=(i-1)/2;
        }
        else
            break;
    }
}

void DecreaseKey(int A[],int d, int n)
{
    A[d]=A[0]-1;
    BottomUpHeapify(A,d);
}

void DeleteArbitrary(int A[],int d,int n)
{
    DecreaseKey(A,d,n);
    Delete(A,n);
}


void TopDownHeapify(int A[],int i,int n)
{   int temp;
    int left=2*i+1;
    int right=2*i+2;
    
    while(right<n)
    {
        if(A[left]<A[right])
            temp=left;
        else 
            temp=right;
        
        if(A[temp]<A[i])
        {
            swap(A,temp,i);
            i=temp;
            left=2*i+1;
            right=2*i+2;
        }
        else
            break;
    }
    if(left<n && A[left]<A[i])
        swap(A,i,left);
}


int main()
{
    int A[]={5,1,17,2,3,4};
    int n=sizeof(A)/sizeof(A[0]);
    int i,d;
    
    for(i=(n/2)-1;i>=0;i--)
        TopDownHeapify(A,i,n);
    
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    cout<<"Enter the element you want to delete";
    cin>>d;
    
    DeleteArbitrary(A,d,n);
    cout<<endl;
    for(int i=0;i<n-1;i++)
        cout<<A[i]<<" ";
    
    
    return 0;
    
}
