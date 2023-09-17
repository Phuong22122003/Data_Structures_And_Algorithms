#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    int key;
    node*left;
    node*right;
    node(){};
    node(int key,int value)
    {
        this->key=key;
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};
typedef node*Nodeptr;
void Inti(Nodeptr&root){
    root=NULL;
}
void Insert(Nodeptr&root,int key,int data){
    if(root==NULL){
        root=new node;
        root->key=key;
        root->value=data;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        if(root->key<key){
            Insert(root->right,key,data);
        }
        else{
            Insert(root->left,key,data);
        }
    }
}
void InsertNotRecursive(Nodeptr&root,int key,int data)
{
    Nodeptr p=new node(key,data);
    if(root==NULL)root=p;
    else 
    {
        Nodeptr runner =root;
        while(1)
        {
            if(runner->key>key)
            {
                if(runner->left==NULL)
                {
                    runner->left=p;
                    return ;
                }
                runner=runner->left;
            }
            else if(runner->key<key)
            {
                if(runner->right==NULL)
                {
                    runner->right=p;
                    return ;
                }
                runner=runner->left;
            }
            else {delete p;return ;}
        }
    }
}
Nodeptr Search(Nodeptr root,int x){
    Nodeptr p=root;
    while(p!=NULL&&x!=p->key){
        if(x>p->key)p=p->right;
        else p=p->left;
    }
    return p;
}
Nodeptr rp;
void remove_case_3(Nodeptr&tree){
    if(tree->left!=NULL)remove_case_3(tree->left);
    else 
    {
        rp->key=tree->key;
        rp->value=tree->value;
        rp=tree;
        tree=rp->right;
    }
}
void remove(int x,Nodeptr&tree){
    if(tree==NULL)cout<<"Khong tim thay"<<endl;
    else
      if(x<tree->key)remove(x,tree->left);
      else if(x>tree->key)remove(x,tree->right);
      else {
        rp=tree;
        if(rp->right==NULL)tree=rp->left;
        else if(rp->left==NULL)tree=rp->right;
        else remove_case_3(rp->right);
        delete rp;
      }
}
// Queue
void LevelOrder(Nodeptr&root){
    if(root==NULL)return ;
    queue<Nodeptr>q;
    q.push(root);
    Nodeptr temp;
    while(!q.empty()){
        temp=q.front();
        cout<<temp->value<<" ";
        q.pop();
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
    }
}
void PreOrder(node*root){
    if(root!=NULL){
    cout<<root->value<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    }
}
void InOrder(node*root){
    if(root!=NULL){
        InOrder(root->left);
        cout<<root->value<<" ";
        InOrder(root->right);
    }
}
void PostOrder(node*root){
    if(root!=NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->value<<" ";
    }
}
//
void PreOrder1(node*root){
    node*stack[20];
    int sp=-1;
    node*p=root;
    while(p!=NULL)
    {
        cout<<p->key<<" ";
        if(p->right!=NULL)stack[++sp]=p->right;
        if(p->left!=NULL)p=p->left;
        else if(sp==-1)break;
        else p=stack[sp--];
    }
}
void PreOrder2(node* root)
{
    node* stack[10],*p=root;
    int sp=-1,x;
    while(p!=NULL)
    {
        cout<<p->key<<" ";
        if(p->right!=NULL)stack[++sp]=p->right;
        if(p->left!=NULL)p=p->left;
        else if(sp!=-1)p=stack[sp--];
        else break;
    }
}
void InOrder1(node* root)
{
    if(root==NULL)return ;
    node*stack[10],*run=root;
    int sp=-1;
    do
    {
        while(run!=NULL)
        {
            stack[++sp]=run;
            run=run->left;
        }
        if(sp!=-1)
        {
            run=stack[sp--];
            cout<<run->key<<" ";
            run=run->right;
        }else break;

    }while(1);
}
void InOrder2(node*root)
{
    node* stack[10];
    int sp=-1;
    node*p=root;
    do
    {
        while(p!=NULL)
        {
            stack[++sp]=p;
            p=p->left;
        }
        if(sp!=-1)
        {
            p=stack[sp--];
            cout<<p->key<<" ";
            p=p->right;
        }else break;
    }while(1);
}
void PostOrder1(node*root)
{
    struct phantu
    {
        int kieu;
        Nodeptr diachi;
    };
    phantu stack[20];
    int type,sp;
    Nodeptr p=root; sp=0; type=true;
    stack[0].diachi=NULL;
    do
    {
        while(p!=NULL&&type)
        {
            stack[++sp].diachi=p;stack[sp].kieu=false;
            if(p->right!=NULL)
            {
                stack[++sp].diachi=p->right;stack[sp].kieu=true;
            }
            p=p->left;
        }
        if(p!=NULL)cout<<p->key<<" ";
        p=stack[sp].diachi;type=stack[sp--].kieu;
    }while(p!=NULL);
}
void PostOrder2(Nodeptr Root)
{
    struct PT
    {
        Nodeptr Node;
        bool type;
    };
    PT stack[100];
    int sp=-1,type=1;
    Nodeptr p=Root;
    do
    {
        while(p!=NULL&&type)
        {
            stack[++sp].Node=p;stack[sp].type=false;
            if(p->right!=NULL)
            {
                stack[++sp].Node=p->right;
                stack[sp].type=true;
            }
            p=p->left;
        }
        if(p!=NULL)cout<<p->key<<" ";
        p=stack[sp].Node;
        type=stack[sp--].type;
    }while(p!=NULL);
}
void releasememory(Nodeptr &p)
{
    if(p!=NULL)
    {
        releasememory(p->left);
        releasememory(p->right);
        delete p;
    }
}
int main(){
    Nodeptr tree;
    Inti(tree);
    Insert(tree,4,10);
    Insert(tree,2,10);
    Insert(tree,1,10);
    Insert(tree,3,10);
    Insert(tree,6,10);
    Insert(tree,5,10);
    Insert(tree,7,10);
    PreOrder1(tree);
    cout<<'\n';
    PreOrder2(tree);
    releasememory(tree);
    return 0;
}