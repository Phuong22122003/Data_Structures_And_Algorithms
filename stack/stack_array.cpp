#include<iostream>
using namespace std;
#define MAX 100
struct stack{
    int A[MAX];
    int top;
};
void InitStack(stack &list){
    list.top=-1;
    return ;
}
bool EmptyStack(stack a){
    if(a.top==-1)return true;
    return false;
}
bool FullStack(stack a){
    if(a.top==MAX-1)return true;
    return false;
}
int push(int n,stack& list){
    if(FullStack(list)){
        cout<<"Stack is full"<<endl;
        return 0;
    }
    list.A[++list.top]=n;
    return 1;
}
int pop(stack&list){
    if(EmptyStack(list)){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    return list.A[list.top--];
}
void show(stack list){
    if(EmptyStack(list))cout<<"Stack is empty"<<endl;
    for(int i=0;i<=list.top;i++){
        cout<<list.A[i]<<" ";
    }
}
int main(){
    stack list;
    InitStack(list);
    push(5,list);
    push(6,list);
    pop(list);
    show(list);
    return 0;
}