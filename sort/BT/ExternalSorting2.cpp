#include<iostream>
#include<cstring>
using namespace std;
struct SV
{
    string MSSV;
    string HO;
    string TEN;
};
typedef SV*ptr;
void quicksort(ptr &DSSV,int start,int end)
{
    SV temp;
    int i=start;
    int j=end;
    SV x=DSSV[(start+end)/2];
    do
    {
        while(DSSV[i].MSSV.compare(x.MSSV)<0)i++;
        while(DSSV[j].MSSV.compare(x.MSSV)>0)j--;

        if(i<=j)
        {
            temp=DSSV[i];
            DSSV[i]=DSSV[j];
            DSSV[j]=temp;
            i++;i--;
        }
    }while(j<=j);
    if(start<j)quicksort(DSSV,start,j);
    if(i<end)quicksort(DSSV,i,end);
}
void docfile(ptr&temp)
{
    
}
#include<fstream>
int main()
{
}