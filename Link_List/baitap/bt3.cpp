#include<iostream>
using namespace std;
struct HangTu{
    int HeSo;
    int Bac;
};
struct DaThuc{
    HangTu x;
    DaThuc*next;
};
typedef DaThuc*DT;
void InsertOrder(DT&a,HangTu x){
    DT node=new DaThuc,run1,run2;
    node->x.Bac=x.Bac;
    node->x.HeSo=x.HeSo;
    for(run2=a;run2!=NULL&&run2->x.Bac>x.Bac;run1=run2,run2=run2->next);
    if(run2==a){
        node->next=a;
        a=node;
    }else{
        run1->next=node;
        node->next=run2;
    }
}
void InsertFirst(DT&a,HangTu x){
    DT node=new DaThuc;
    node->x.Bac=x.Bac;
    node->x.HeSo=x.HeSo;
    node->next=a;
    a=node;
}
void NhapDaThuc(DT&a){
    HangTu x;
    while(1){
        cout<<"Nhap he so:";cin>>x.HeSo;
        if(x.HeSo==0)return;
        cout<<"Nhap bac:";
        cin>>x.Bac;
        InsertFirst(a,x);
    }
}
void In(DT a){
    if(a==NULL){
        cout<<"0x^0"<<endl;
        return;
    }
    while(a!=NULL){
        cout<<a->x.HeSo;
        if(a->x.Bac!=0)
        cout<<"x^";
        cout<<a->x.Bac;
        if(a->next!=NULL)cout<<"+";
        a=a->next;
    }
    cout<<endl;
}
DT Nhan(DT a,DT b){
    DT run=NULL,result=NULL;
    HangTu x;
    while(a!=NULL){
        run=b;
        while(run!=NULL){
            x.Bac=a->x.Bac;
            x.HeSo=a->x.HeSo;
            x.Bac+=run->x.Bac;
            x.HeSo*=run->x.HeSo;
            InsertOrder(result,x);
            run=run->next;
        }
        a=a->next;
    }
    if(result!=NULL)
        for(a=result;a->next!=NULL;){
            if(a->x.Bac==a->next->x.Bac){
                a->x.HeSo+=a->next->x.HeSo;
                b=a->next;
                a->next=b->next;
                delete b;
                continue;
            }
        a=a->next;
        }
    return result;
}
void del(DT&a){
    DT p;
    while(a!=NULL){
        p=a->next;
        delete a;
        a=p;
    }
}
int main(){
    DT a=NULL,b=NULL,result=NULL;
    NhapDaThuc(a);
     NhapDaThuc(b);
     result=Nhan(a,b);
     In(a);
     In(b);
     In(result);
     del(a);
     del(b);
    del(result);
    return 0;
}