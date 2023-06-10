#include<iostream>
#include<math.h>
using namespace std;
struct node {
    int x;
    node *next;
};
typedef node* ptr;
ptr NewNode(int x){
    ptr p=new node;
    p->x=x;
    p->next=NULL;
    return p;
}
void Insert_first(ptr&list,int x){
    ptr p=NewNode(x);
    p->next=list;
    list=p;
}
void Insert_last(ptr&list,int x){
    ptr p=NewNode(x),run=list;
    if(list==NULL)list=p;
    else {
        while(run->next!=NULL)run=run->next;
        run->next=p;
    }
}
void Nhap(ptr &list){
    int x;
    while(true)
    {
        cout<<"NHAP X:";
        cin>>x;
        Insert_first(list,x);
    }
}
ptr Copy_List(ptr&list1){
    ptr list2=NULL,run=list1,last;
    while(run!=NULL){
        ptr p=NewNode(run->x);
        run=run->next;
        if(list2==NULL){
            list2=p;
            last=p;
        }
        else {
            last->next=p;
            last=last->next;
        }
    }
    return list2;
}
void Loc(ptr&list){
    ptr p,q;
    if(list==NULL)return;
    if(list->next==NULL)return;
    p=list,q=list->next;
    while(q!=NULL){
        if(p->x==q->x){
            p->next=q->next;
            delete q;
            q=p->next;
            continue;
        }
        p=q,q=q->next;
    }
}
void Reverse(ptr&list){
    ptr pre=NULL,next;
    if(list==NULL)return;
    while(list!=NULL)
    {
        next=list->next;
        list->next=pre;
        pre=list;
        list=next;
    }
    list=pre;
}
void Traverse(ptr list){
    if(list==NULL)cout<<"DANH SACH RONG";
    ptr p=list;
    while(p!=NULL){
        cout<<p->x<<" ";
        p=p->next;
    }
}
bool NguyenTo(int x){
    if(x<2)return false;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return false;
    }
    return true;
}
ptr Seperate(ptr &list1){
    ptr list2,p1,p2,run=list1;
    if(list1==NULL)return list1;
    list1=p1=new node,list2=p2=new node;
    while(run!=NULL){
        if(NguyenTo(run->x)){
            if(p1->next!=run)p1->next=run;// hai so nguyen to ke nhau
            p1=run;//cap nhat p1
        }
        else {
            if( p2->next!=run) p2->next=run;// hai so binh thuong ke nhau
            p2=run;
        }
        run=run->next;
    }
    p1->next=NULL;
    p2->next=NULL;
    p1=list1;list1=list1->next;delete p1;
    p2=list2;list2=list2->next;delete p2;
    return list2;
}
ptr merge(ptr &List1,ptr &List2){
    ptr result=new node,current=result;
    while(List1!=NULL&&List2!=NULL){
        if(List1->x<List2->x){
            current->next=List1;
            current=List1;
            List1=List1->next;
        }
        else{
            current->next=List2;
            current=List2;
            List2=List2->next;
        }
    }
    if(List1==NULL)current->next=List2;
    else current->next=List1;
    current=result;
    result=result->next;
    delete current;
    return result;
}
void del(ptr& list){
    ptr p;
    while(list!=NULL){
        p=list;
        list=list->next;
        delete p;
    }
}
int main(){
    ptr list=NULL,list1=NULL;
    Insert_first(list,7);
    Insert_first(list,6);
    Insert_first(list,5);
    Insert_first(list,4);
    Insert_first(list1,8);
    Insert_first(list1,7);
    Insert_first(list1,6);
    Insert_first(list1,5);
    Seperate(list);
    Traverse(list);
    del(list);
    del(list1);
    return 0;
}