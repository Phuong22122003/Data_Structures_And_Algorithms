#include<iostream>
using namespace std;
struct node{
    int value;
    node*next;
};
typedef node* listnode;
//insert a node into the list at the starting position
void insertnode(int data,listnode &list){
    listnode p=new node;
    p->value=data;
    p->next=list;
    list=p;
}
//testok
void insertbeginning(int n,listnode &list){
    node*newnode=new node;
    newnode->value=n;
    newnode->next=list;
    list=newnode;
}
//insert a node into the list at the end
//testok
void insertend(int n,listnode &list){
    node*p=new node;
    p->value=n;
    p->next=NULL;
    if(list==NULL){
        list=p;
        return;
    }
    else{
        node *runner=list;
        while(runner->next!=NULL){
            runner=runner->next;
          }
        runner->next=p;
    }
}
//insert a node in front of the other node
//testok
void insertmiddle(int n, int position,listnode &list){
    node*temp=new node;
    temp->value=n;
    temp->next=NULL;
    int found=0,count=1;
    node*run=list;
    while(run!=NULL&&found!=1){
        if(count==position){
            temp->next=run->next;
            run->next=temp;
            found=1;
            break;
        }
        run=run->next;
        count++;
    }
    if(found==0)cout<<"Not found the position"<<endl;
}
//delete a node from the list at the starting position
//testok
int delete_begin(listnode&list){
    if(list==NULL)return 0;
    node*temp=list;
    list=list->next;
    delete[]temp;
    return 1;
}
//testok
void delete_end(listnode &list){
    if(list==NULL)return;
    if(list->next==NULL){
        delete_begin(list);
        return;
    }
    node*runner=list,*behind_runner=list;
    while(runner->next!=NULL){
        behind_runner=runner;
        runner=runner->next;
    }
    behind_runner->next=NULL;
    delete[]runner;
}
void shownode1(listnode list){
    while(list!=NULL){
        cout<<list->value<<endl;
        list=list->next;
    }
}
void shownode2(listnode list){
    node*p=NULL;
    if(list==NULL)return ;
    for(p=list;p!=NULL;p=p->next){
        cout<<p->value<<" ";
    }
}
////////////////////////////////******************************************************////////////////////////////////////////////////////
// sort
void Selection_sort(listnode&list){
    node*p,*pmin,*q;
    int min=0;
    for(p=list;p!=NULL;p=p->next){
        pmin=p;
        min=p->value;
        for(q=p->next;q!=NULL;q=q->next){
            if(q->value<min){
                min=q->value;
                pmin=q;
            }
        }
        pmin->value=p->value;
        p->value=min;
    }
}
void sort(listnode&list)
{
    if(list==NULL||list->next==NULL)return;
    listnode runner1,runner2,p;
    for(runner1=list;runner1->next!=NULL;runner1=runner1->next)
    {
        p=runner1->next;
        for(runner2=runner1->next;runner2!=NULL;runner2=runner2->next)
        {
            if(p->value>runner2->value)p=runner2;
        }
        swap(runner1->value,p->value);
    }
}
void Insert_Order(listnode&list,int x){
    node* newnode=new node;
    newnode->value=x;
    node*t,*s;
    for(s=list;s!=NULL&&s->value<x;t=s,s=s->next);
    if(s==list){
        newnode->next=list;
        list=newnode;
    }else{
        newnode->next=s;
        t->next=newnode;
    }
}
listnode Merge_order(listnode&list1,listnode&list2){
    listnode list=new node;
    listnode p=list1,q=list2,run=list;
    while(p!=NULL&&q!=NULL){
        if(p->value<q->value){
           run->next=p;
           run=p;
           p=p->next;
        }
       else{
           run->next=q;
           run=q;
           q=q->next;
        }
    }
    if(p==NULL){
        run->next=q;
    }else run->next=p;
    run=list;
    list=run->next;
    delete[]run;
    p=NULL;q=NULL;
    return list;
}
void ReleaseMemory(listnode&list)
{
    for(node*runner=list,*p;runner!=NULL;)
    {
        p=runner;
        runner=runner->next;
        delete p;
    }
}
int main(){
    listnode list1=NULL;
    Insert_Order(list1,1);
    Insert_Order(list1,3);
    Insert_Order(list1,2);
    Insert_Order(list1,0);
    listnode list2=NULL;
    Insert_Order(list2,4);
    Insert_Order(list2,7);
    Insert_Order(list2,5);
    Insert_Order(list2,8);
    listnode p=Merge_order(list1,list2);
    insertbeginning(2,p);
    insertbeginning(8,p);
    insertbeginning(3,p);
    insertbeginning(1,p);
    Selection_sort(p);
    //sort(p);
    shownode2(p);
    ReleaseMemory(p);
    return 0;
}