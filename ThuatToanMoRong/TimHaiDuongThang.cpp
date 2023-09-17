#include<iostream>
using namespace std;
struct Duongthang
{
    double a;
    double b;
};
double TinhY(Duongthang d,double x)
{
    return d.a*x+d.b;
}
int main()
{
    Duongthang arr[5];
    arr[0].a=2;arr[0].b=1;
    arr[1].a=3;arr[1].b=1;
    arr[2].a=4;arr[2].b=1;
    arr[3].a=5;arr[3].b=1;
    arr[4].a=6;arr[4].b=1;
    double x=0.5,y=7.5,temp1,temp2;
    for(int i=0;i<4;i++)
    {
        temp1=TinhY(arr[i],x);
        temp2=TinhY(arr[i+1],x);
        cout<<"temp1: "<<temp1<<"   temp2:"<<temp2<<"  Y: "<<y<<endl;
        if(y>temp1&&y<temp2)
        {
            cout<<"duong thang thu "<<i+1<<" va "<<i+2;
            break;
        }
    }
}