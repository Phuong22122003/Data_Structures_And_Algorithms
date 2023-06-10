#include<iostream>
#include<math.h>
using namespace std;
void Bubble_sort(int Arr[],int start,int end)
{
    for(int i=start;i<end;i++)
    {
        for(int j=end;j>i;j--)
        {
            if(Arr[j]<Arr[j-1])
            {
                swap(Arr[j],Arr[j-1]);
            }
        }
    }
}
void Insertion_sort(int Arr[],int start,int end)
{
    int x,i,j;
    for(i=start+1;i<=end;i++)
    {
         x=Arr[i];
        // for(j=i;j>start&&x<Arr[j-1];j--)
        // {
        //     Arr[j]=Arr[j-1];
        // }
        // Arr[j]=x;
        for(j=i-1;j>=start&&x<Arr[j];j--)
        {
            Arr[j+1]=Arr[j];
        }
        Arr[j+1]=x;
    }
}
void Selection_sort(int A[],int start,int end)
{
    int x;
    for(int i=start;i<end;i++)
    {
        x=i;
        for(int j=i+1;j<=end;j++)
        {
            if(A[x]>A[j])x=j;
        }
        swap(A[i],A[x]);
    }   
}
void Quick_sort(int A[],int start,int end)
{
    int i,j,mid;
    i=start;
    j=end;
    mid=(i+j)/2;
    do
    {
        while(A[i]<A[mid])i++;
        while(A[j]>A[mid])j--;
        if(j>=i)
        {
            swap(A[i],A[j]);
            j--;
            i++;
        }
    }while(j>=i);
    if(i<end)Quick_sort(A,i,end);
    if(j>start)Quick_sort(A,start,j);
}
void Adjust(int A[],int r,int n)
{
    int j=2*r+1;//Nút con bên trái
    int x=A[r];//lưu lại giá trị nút cha
    int cont=1;
    while(j<=n-1&&cont)
    {
        if(j<n-1&&A[j]<A[j+1])j++;//xem thử có nút con bên phải ko và nút trái có bé hơn nút phải
        if(A[j]<=x)cont=0;
        else
        {
            A[r]=A[j];
            r=j;
            j=2*r+1;
        }
    }
    A[r]=x;
}
void Heap_sort(int A[],int n)
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)Adjust(A,i,n);
    //for(i=0;i<n;i++)cout<<A[i]<<" ";
    //cout<<endl;
    for(i=n-2;i>=0;i--)
    {
        swap(A[0],A[i+1]);
        if(i>0)Adjust(A,0,i+1);
        // for(int j=0;j<n;j++)cout<<A[j]<<" ";
        // cout<<endl;
    }
}