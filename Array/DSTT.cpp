#include<iostream>
using namespace std;
#define MAXLIST 100
typedef struct List{
    int n;//n la so luong phan tu
    int nodes[MAXLIST];
};
int empty(List plist){
    return(plist.n==0?1:0);
}
int full(List plist){
    return(plist.n==MAXLIST?1:0);
}
void create_list(List&plist){
    cout<<"Nhap so phan tu cua danh sach: "<<endl;
    cin>>plist.n;
    for(int i=0;i<plist.n;i++){
        cout<<"List["<<i+1<<"]=";
        cin>>plist.nodes[i];
    }
}
void insert_item(List&plist,int i,int infor)
{
    if(i<0||i>plist.n){
        cout<<"Vi tri chen khong phu hop"<<endl;
    }
    else if(full(plist))cout<<"Danh sach day"<<endl;
    else
    {
        for(int j=plist.n;j>i;j--)
            plist.nodes[j]=plist.nodes[j-1];
        plist.nodes[i]=infor;
        plist.n++;
    }
}
void delete_item(List&plist,int i){
    if(empty(plist))cout<<"Danh sach rong"<<endl;
    else if(i<0||i>=plist.n)cout<<"Vi tri khong phu hop";
    else {
        for(int j=i+1;j<plist.n;j++)
        plist.nodes[j-1]=plist.nodes[j];
        plist.n--;
    }
}
void clearlist(List&plist)
{
    plist.n=0;
}
void traverse(List plist)
{
    if(empty(plist)){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    for(int i=0;i<plist.n;i++)
    cout<<plist.nodes[i]<<endl;
}
int search_infor(List plist,int infor)
{
    int vitri=0;
    while(vitri<plist.n&&plist.nodes[vitri]!=infor)vitri++;
    return(vitri==plist.n?-1:vitri);
}
int menu()
{
    int chucnang;
    system("cls");
    cout<<"1.Nhap danh sach\n";
    cout<<"2. Xem danh sach\n";
    cout<<"3. Them mot phan tu vao danh sach\n";
    cout<<"4. Xoa phan tu dau tien co infor\n";
    cout<<"5. Xoa toan bo danh sach\n";
    cout<<"Chuc nang ban chon: ";
    do cin>>chucnang;
    while(chucnang<0||chucnang>5);
    cin.ignore();
    return chucnang;
}
int main(){
    int chucnang;
    List list;
    do {
    chucnang=menu();
    switch(chucnang){
        case 1: 
        {
            cout<<"Nhap danh sach\n";
            create_list(list);
            cin.ignore();
            break;
        }
        case 2: 
        {
            traverse(list);
            cin.ignore();
            break;
        }
        case 3: 
        {
            int i,infor;
            cout<<"Nhap vi tri them: ";
            cin>>i;
            cout<<"Nhap gia tri can them: ";
            cin>>infor;
            insert_item(list,i,infor);
            cin.ignore();
            break;
        }
        case 4:
        {
            int infor;
            cout<<"Nhap gia tri can xoa: \n";
            cin>>infor;
            int index=search_infor(list,infor);
            if(index==-1)cout<<"Khong co trong danh sach";
            else delete_item(list,index);
            break;
        }
        case 5:
        {
            cout<<"Ban co chac muon xoa hay khong";
            char c;
            cin>>c;
            if(c=='c')clearlist(list);
            else break;
        }
    }
    }while(chucnang!=0);
}