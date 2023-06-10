#include<bits/stdc++.h>
using namespace std;
struct node{
    int infor;
    node*next;
};
typedef node*Stack;
void push(Stack& st,int data){
    node*newnode=new node;
    newnode->infor=data;
    newnode->next=st;
    st=newnode;
}
int pop(Stack&st){
    if(st==NULL)return-1;
    else{
        node*oldnode=new node;
        oldnode=st;
        st=st->next;
        int tam=oldnode->infor;
        delete oldnode;
        return tam;
    }
}
int main(){
    return 0;
}