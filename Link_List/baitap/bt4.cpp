#include<iostream>
using namespace std;

struct node{
    int x;
    node* next;
};
typedef node* ptr;
void DeleteFirst(ptr &first){
    if(first==NULL)return;
    ptr p=first;
    first=first->next;
    delete p;
}
void DeleteAfter(ptr &after)
{

    ptr p=after->next;
    if(p!=NULL)after->next=p->next;
    delete p;
}
void DeleteAllX(ptr &first,int x)
{
    if(first->x==x){
        while(first!=NULL&&first->x==x){
        DeleteFirst(first);
        }
       return;
    }

    for(ptr run=first;run!=NULL&&run->next!=NULL;)
    {
        if(run->next->x==x)
        {
            while(run->next!=NULL&&run->next->x==x)DeleteAfter(run);
            return;
        }
        else if(run->x>x)return ;
        run=run->next;
    }
}
void InsertFirst(ptr&root,int x){
    ptr temp=new node;
    temp->x=x;
    temp->next=root;
    root=temp;
}
void InsertOrder(ptr&root,int x){
    ptr temp=new node,run1,run2;
    temp->x=x;
    temp->next=NULL;
    for(run2=root;run2!=NULL&&run2->x<x;run1=run2,run2=run2->next);
    if(run2==root){
        temp->next=root;
        root=temp;
    }else{
        run1->next=temp;
        temp->next=run2;
    }
}
void Nhap(ptr &root){
    int x;
    while(1){
        cout<<"Nhap X:";
        cin>>x;
        if(x==0)break;
        InsertOrder(root,x);
    }
}
void show(ptr root)
{
    while(root!=NULL){
        cout<<root->x<<" ";
        root=root->next;
    }
}
int main(){
    ptr root=NULL;
    Nhap(root);
    DeleteAllX(root,5);
    show(root);
}