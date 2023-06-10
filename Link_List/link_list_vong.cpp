#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int infor;
    node*next;
    node(){};
    node(int data){
        this->infor=data;
        this->next=NULL;
    }
};
typedef node* ptr;
void Ins_first(ptr&last,int x){
    node* newnode=new node(x);
    if(last==NULL){
        last=newnode;  
    }
    else{
        newnode->next=last->next; 
    }
    last->next=newnode;
}
void Ins_last(ptr&last,int x){
    ptr newnode=new node(x);
    if(last==NULL){
        newnode->next=newnode;
    }else{
        newnode->next=last->next;
        last->next=newnode;
    }
    last=newnode;
}
void Del_first(ptr&last){
    if(last==NULL){
        cout<<"The list is empty"<<endl;
    }
    else{
        ptr p=last->next;
        if(last==p){
            last=NULL;
        }
        else{
            last->next=p->next;
        }
        delete p;
    }
}
void Traverse(ptr &last){
   
    if(last==NULL){
        cout<<"The list is empty"<<endl;
        return;
    } 
    ptr p=last->next;
    while(p!=last){
        cout<<p->infor<<" ";
        p=p->next;
    }
    cout<<p->infor<<" ";
}
int main(){
    ptr last=NULL;
    Ins_first(last,1);
    Ins_first(last,2);
    Ins_first(last,3);
    Ins_last(last,0);
    Del_first(last);
    Del_first(last);
    Ins_last(last,1);
    Traverse(last);
    return 0;
}