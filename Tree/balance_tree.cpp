#include<iostream>
using namespace std;
struct nodetype
{
    int key;
    int infor;
    int bf;
    struct nodetype*left,*right;
};
typedef nodetype*Nodeptr;
Nodeptr Rotate_left(Nodeptr root)
{
    Nodeptr p;
    if(root==NULL)cout<<"Khong the xoay trai vi cai bi rong"<<endl;
    else if(root->right==NULL)cout<<"Khong the xoay trai vi khong co nut phai"<<endl;
    else 
    {
        p=root->right;
        root->right=p->left;
        p->left=root;
    }
    return p;
}
Nodeptr Rotate_right(Nodeptr root)
{
    Nodeptr p;
    if(root==NULL)cout<<"Khong the xoay trai vi cai bi rong"<<endl;
    else if(root->left==NULL)cout<<"Khong the xoay trai vi khong co nut trai"<<endl;
    else 
    {
        p=root->left;
        root->left=p->right;
        p->right=root;
    }
    return p;
}
void Insert(Nodeptr&root, int x,int a)//x is key, a is info
{
    Nodeptr fb,p,q,
            fya,ya,//ya là nút gần nhất bị mất cân bằng
            s;//nut theo huong mat can bang
    int imbal;// imbal=1 lech trai||imbal=-1 lech phai
    fb=NULL; p=root;
    fya=NULL;ya=p;
    while(p!=NULL){
        if(x==p->key)return;
        if(x<p->key)q=p->left;
        else q=p->right;
        if(q!=NULL)
         if(q->bf!=0){// nut mat can bang
            fya=p;
            ya=q;
        }
        fb=p;// la nut cha cua nut can them
        p=q;
    }
    // them nut moi vao
    q=new nodetype;
    q->key=x;q->infor=a;q->bf=0;
    q->left=NULL;q->right=NULL;
    if(x<fb->key)fb->left=q;
    else fb->right=q;
    //hieu chinh chi so can bang cua tat cua cac nut tu
    // ya den q
    if(x<ya->key)
        p=ya->left;
    else 
        p=ya->right;
    s=p;//s la nut co chi so can bang
    while(p!=q)
    {
        if(x<p->key)
        {
            p->bf=1;
            p=p->left;
        }
        else 
        {
            p->bf=-1;
            p=p->right;
        }
    }
    if(x<ya->key)imbal=1;
    else imbal=-1;
    if(ya->bf==0)// truong hop them vao cay khong co bf!=0 can bang
    {
        ya->bf=imbal;
        return ;
    }
    if(ya->bf!=imbal)//truong hop them cay vao nhung van can bang
    {                  //do dua nut moi vao huong nguoc lai
        ya->bf=0;
        return ;
    }
    // cay mat can bang

    // bat dau xet truong hop
    if(s->bf==imbal)//xoay don
    {
        if(imbal==1)// cung lech trai hoac cung lech phai
            p=Rotate_right(ya);
        else 
            p=Rotate_left(ya);
        ya->bf=0;
        s->bf=0;
    }
    else
    {
        if(imbal==1)
        {
            ya->left=Rotate_left(s);
            p=Rotate_right(ya);
        }
        else
        {
            ya->right=Rotate_right(s);
            p=Rotate_left(ya);
        }

        //*****************************************//
        // chinh lai bf
        if(p->bf==0)//truong hop p la nut moi them
        {
            ya->bf=0;
            s->bf=0;
        }
        else 
        {
            // truong hop 1b
           if(p->bf==imbal)
           {
            ya->bf=-imbal;
            s->bf=0;
           }
           else// truong hop 2b
           {
            ya->bf=0;
            s->bf=imbal;
           }
        }
        p->bf=0;
    }

    // nối lại 
    if(fya==NULL)// trường hợp nút gốc bị mất cân bằng
    root=p;
    else if(ya==fya->right)
    fya->right=p;
    else 
    fya->left=p;
}
Nodeptr xoay_trai(Nodeptr ya)
{
    if(ya==NULL||(ya->right==NULL))return ya;
    Nodeptr s=ya->right;
    ya->right=s->left;
    s->left=ya;
    return s;
}
Nodeptr xoay_phai(Nodeptr ya)
{
    if(ya==NULL)return ya;
    else if(ya->left==NULL)
    {
        cout<<"khong the xoay";
        return ya;
    }
    Nodeptr s=ya->left;
    ya->left=s->right;
    s->right=ya;
    return s;
}
void chen(Nodeptr&root,int key,int data)
{
    Nodeptr fya=NULL,ya,s,p,q,fb=NULL;
    ya=root;
    int bf;
    p=root;
    while(p!=NULL)
    {
        if(p->key==key)return;
        if(p->key>key)q=p->left;
        else q=p->right;
        if(q!=NULL)
            if(q->bf!=0)
            {
                fya=p;
                ya=q;
            }
        fb=p;
        p=q;
    }
    q=new nodetype;
    q->left=NULL;
    q->right=NULL;
    q->bf=0;
    q->key=key;
    q->infor=data;
    if(fb->key>key)fb->left=q;
    else fb->right=q;
    if(key<ya->key)
        p=ya->left;
    else p=ya->right;
    s=p;
    while(p!=q)
    {
        if(p->key>q->key)
        {
            p->bf=1;
            p=p->left;
        }
        else 
        {
            p->bf=-1;
            p=p->right;
        }
    }
    if(key<ya->key)bf=1;
    else bf=-1;
    if(ya->bf==0)
    {
        ya->bf=bf;
        return ;
    }
    if(ya->bf!=bf)
    {
        ya->bf=0;
        return ;
    }
    if(s->bf==bf)
    {
        if(bf==1)p=xoay_phai(ya);
        else p=xoay_trai(ya);
        ya->bf=0;
        s->bf=0;
    }
    else 
    {
        if(bf==1)
        {
            ya->left=xoay_trai(s);
            p=xoay_phai(ya);
        }
        else 
        {
            ya->right=xoay_phai(s);
            p=xoay_trai(ya);
            if(p->bf==0)
            {
                ya->bf=0;
                s->bf=0;
            }
            else 
            {
                if(p->bf==bf)
                {
                    s->bf=0;
                    ya->bf=-bf;
                }
                else
                {
                    ya->bf=0;
                    s->bf=bf;
                }
            }
            p->bf=0;
        }
    }
    if(fya==NULL)root=p;
    else if(ya==fya->right)fya->right=p;
    else fya->left=p;
}
void in(Nodeptr root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        in(root->left);
        in(root->right);
    }
}
void releasmemory(Nodeptr&root)
{
    if(root!=NULL)
    {
        releasmemory(root->left);
        releasmemory(root->right);
        delete root;
    }
}
int main(){
    Nodeptr root=new nodetype;
    root->key=4;
    chen(root,2,1);
    chen(root,3,1);
    chen(root,1,1);
    chen(root,6,1);
    chen(root,7,1);
    chen(root,5,1);
    in(root);
    releasmemory(root);
    return 0;
}