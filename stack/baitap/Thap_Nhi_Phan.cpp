#include<iostream>
using namespace std;
#define stacksize 32
struct stack{
    int n;
    int nodes[stacksize];
};
void push(stack&sp,int n){
    if(sp.n==stacksize-1)return;
    else
    sp.nodes[++sp.n]=n;
}
int pop(stack&sp,int &x){
    if(sp.n<0)return 0;
    else 
    x=sp.nodes[sp.n--];
    return 1;
}
int main(){
    stack sp;
    sp.n=-1;
    int n;
    cout<<"Nhap vao so n: ";
    cin>>n;
    while(n>0){
        push(sp,n%2);
        n/=2;
    }
    int x;
    while(sp.n>=0){
        pop(sp,x);
        cout<<x;
    }
    return 0;
}