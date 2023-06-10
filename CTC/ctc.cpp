#include<iostream>
#include<ctime>
#include<cstdlib>
#include<math.h>
using namespace std;
//m,n là tham số hình thức trị nếu &m thì đây là tham số hình thức biến
int* DifferentNumberInArray(int m,int lim)
{
    int *array1,*array2;
    array1=new int[lim];
    array2=new int[m];
    for(int i=0;i<lim;i++)array1[i]=i+1;
    srand(time(0));
    for(int i=0,index;i<m;i++)
    {
        index=rand()%(lim-i)+i;
        swap(array1[i],array1[index]);
        array2[i]=array1[i];
    }
    for(int i=0;i<lim;i++)cout<<array1[i]<<" ";
    cout<<endl;
    delete []array1;
    //((lim-1)-i)+1-> day la khoang cach giua i va lim-1
    return array2;
}
int main()
{
    int* Arr =DifferentNumberInArray(10,100);
    for(int i=0;i<10;i++)cout<<Arr[i]<<" ";
    delete []Arr;
} 