#include"Function.cpp"
#include<time.h>
#include<time.h>
#include<stdlib.h>
int main()
{

    clock_t start, end;   // Khai báo biến thời gian
    double time_use;
    int n=100000;
    int *arr=new int[n];
    start = clock(); 
    srand(time(0));
    for(int i=0;i<n;i++)arr[i]=rand()%200;
    end = clock();  // lấy thời gian sau khi thực hiện
    cout<<endl;
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay factorial(n): "<<time_use<<endl;
    start = clock(); 
    //mergeSort(arr,0,n);
    //Quick_sort(arr,0,n);
    //Bubble_sort(arr,0,n);
    //Insertion_sort(arr,0,n);
    //Selection_sort(arr,0,n);
    Heap_sort(arr,n);
    end = clock();  // lấy thời gian sau khi thực hiện 
    //for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay factorial(n): "<<time_use<<endl;
    for(int i=0;i<n;i++)arr[i]=rand()%200;
    start = clock(); 
    //Lap(n);
    //Quick_sort(arr,0,n);
    //Bubble_sort(arr,0,sizeof(arr)/4);
    //Insertion_sort(arr,0,n);
    //Selection_sort(arr,0,n);
    //Heap_sort(arr,n);
    mergeSort(arr,0,n-1);
    end = clock();  // lấy thời gian sau khi thực hiện 
    cout<<endl;
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay factorial(n): "<<time_use;
    delete []arr;
}