#include<iostream>
using namespace std;
class node{
    public:
    int infor;
    node*left,*right;
    node(void);
    node(int data){
        this->infor=data;
        left=NULL;
        right=NULL;
    }
};
typedef node*ptr;
class list{
    public:
    ptr first,last;
    list(void)
    {
        first=NULL;
        last=NULL;
    }
};
void Ins_first(list&l,int x){
    ptr newnode=new node(x);
    newnode->right=l.first;
    if(l.first==NULL){
        l.last=newnode;
    }else{
        l.first->left=newnode;
    }
    l.first=newnode;
}
void Ins_left(list&l,ptr p,int x){
    ptr left,newnode;
    if(p==NULL){
        cout<<"Node p dont exist"<<endl;
        return ;
    }
    else{
        if(p==l.first){
            Ins_first(l,x);
            return;
        }
        newnode=new node(x);
        left=p->left;
        newnode->left=left;
        left->right=newnode;
        newnode->right=p;
        p->left=newnode;
    }
}
void Right_traverse(list&l){
    if(l.first==NULL){
        cout<<"The list is empty"<<endl;
        return ;
    }
    ptr p=l.first;
    while(p!=NULL){
        cout<<p->infor<<" ";
        p=p->right;
    }
}
int main(){
    list l;
    Ins_first(l,1);
    Ins_first(l,2);
    Ins_left(l,l.first,3);
    Ins_left(l,l.last,3);
    Right_traverse(l);
    return 0;
}