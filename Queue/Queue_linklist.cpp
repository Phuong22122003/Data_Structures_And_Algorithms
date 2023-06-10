#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*next;
};
typedef node*ptr;
struct Queue{
    ptr front,rear;
};
void put(Queue&q,int data){
    node*newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    if(q.front=NULL){  
        q.front=newnode;
    }else{
        q.rear->next=newnode;
    }
    q.rear=newnode;
}
int get(Queue&q,int &data){
    if(q.front==NULL)return 0;
    else{
        data=q.front->data;
        node*oldnode=q.front;
        q.front=oldnode->next;
        delete oldnode;
        return 1;
    }
}
int main(){
    return 0;
}