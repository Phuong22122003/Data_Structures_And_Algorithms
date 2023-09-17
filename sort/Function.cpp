#include<iostream>
#include<math.h>
using namespace std;
void Bubble_sort(int Arr[],int start,int end)
{
    int i,j,temp;
    for(i=start;i<end;i++)
    {
        for(j=end;j>i;j--)
        {
            if(Arr[j]<Arr[j-1])
            {
                temp=Arr[j-1];Arr[j-1]=Arr[j];Arr[j]=temp;
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
        for(j=i-1;j>=start&&x<Arr[j];j--)
        {
            Arr[j+1]=Arr[j];
        }
        Arr[j+1]=x;
    }
}
void Selection_sort(int A[],int start,int end)
{
    int min,vitrimin,i,j;
    for( i=start;i<end;i++)
    {
        min=A[i];vitrimin=i;
        for( j=i+1;j<=end;j++)
        {
            if(A[j]<min)
            min=A[j];vitrimin=j;
        }
        min=A[vitrimin];A[vitrimin]=A[i];A[i]=min;
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
int Lap(int n)
{
    int j;
    int a,b;
    int A[100000];
    for(int i=0;i<n;i++)
        for(j=n-1;j>=i;j--);
        {swap(A[5000],A[9999]);}

}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo các mảng tạm để lưu giữ các phần tử
    int *L=new int[n1];
    int *R=new int [n2];

    // Sao chép dữ liệu vào các mảng tạm
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Trộn hai mảng con đã được sắp xếp vào mảng gốc
    int i = 0; // Chỉ số đầu tiên của mảng con trái
    int j = 0; // Chỉ số đầu tiên của mảng con phải
    int k = left; // Chỉ số đầu tiên của mảng gốc

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con trái (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con phải (nếu có)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete []L;delete []R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sắp xếp hai nửa đầu và sau của mảng
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai mảng đã được sắp xếp
        merge(arr, left, mid, right);
    }
}