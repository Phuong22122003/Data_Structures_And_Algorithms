#include<iostream>
#include<math.h>
using namespace std;
#define max 80
struct stack{
    int n;
    double Arr[max];
};
int push(stack &sp,int n){
    if(sp.n==max-1)return 0;
    else sp.Arr[++sp.n]=n;
    return 1;
}
int pop(stack&sp,double &x){
    if(sp.n<0)return 0;
    else x=sp.Arr[sp.n--];
    return 1;
}
double tinh(char toantu,double toanhang1,double toanhang2)
{
    switch(toantu){
        case '+':{
            return toanhang1+toanhang2;
        }
        case '-':{
            return toanhang1-toanhang2;
        }
        case '*':{
            return toanhang1*toanhang2;
        }
        case '/':return toanhang1/toanhang2;
        case '^':return pow(toanhang1,toanhang2);
        default:{
            cout<<"loi";
            exit(1);
        }
    }
}
double hauto(char a[]){
    stack sp;
    sp.n=-1;
    double toanhang1,toanhang2;
    int i,c;
    for(i=0;(c=a[i])!='\0';i++)
        if(c>='0'&&c<='9')
        push(sp,c-'0');
        else 
        {
            pop(sp,toanhang2);
            pop(sp,toanhang1);
            push(sp,tinh(c,toanhang1,toanhang2));
        }
    pop(sp,toanhang1);
    return toanhang1;
}
int main(){
    char a[80];
    cin>>a;
    cout<<hauto(a);
    return 0;
}