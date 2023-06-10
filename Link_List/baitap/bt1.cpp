#include<iostream>
#include<string>
using namespace std;
struct SinhVien{
	string ten;
	float diemTB;
	int Hang;
};
struct node{
	SinhVien sv;
	node*next;
};
typedef node*ptr;
void Insert_first(ptr&list,SinhVien sv)
{
	ptr n=new node;
	n->sv=sv;
	n->next=list;
	list=n;
}
void Insert_last(ptr&list,SinhVien sv){
	ptr n=new node;
	n->sv=sv;
	if(list==NULL)list=n;
	else
	{
	ptr run=list;
	while(run->next!=NULL){
		run=run->next;
	}
	run->next=n;
	}
}
void Insert_after(ptr &list,ptr p,SinhVien sv){
	if(p==NULL)cout<<"Danh sach hien tai rong"<<endl;
	else{
		if(p==list)Insert_last(list,p->sv);
		else
		{
			ptr q=new node;
			q->sv=sv;
			q->next=p->next;
			p->next=q;
		}
	}
}
int InsertOder(ptr&List,ptr temp){
	ptr run1,run2;
	for(run1=List;run1!=NULL&&run1->sv.diemTB>temp->sv.diemTB;run2=run1,run1=run1->next);
	if(run1==List){
		temp->next=List;
		List=temp;
	}
	else{
		temp->next=run1;
		run2->next=temp;
	}
	return 1;
}
int XepHang(ptr&list){
	ptr run=list;
	int i=1;
	if(list==NULL)return 0;
	while(run->next!=NULL){
		run->sv.Hang=i;
		if(run->sv.diemTB>run->next->sv.diemTB)i++;
		run=run->next;
	}
	run->sv.Hang=i;
	return 1;
}
ptr Nhap(){
	ptr List=NULL;
	ptr temp;
	while(1){
		temp=new node;
		cout<<"Nhap ten:";
		getline(cin,temp->sv.ten);
		if(temp->sv.ten==" ")break;
		cout<<"Nhap diem trung binh:";
		cin>>temp->sv.diemTB;
		cin.ignore();
		temp->sv.Hang=0;
		InsertOder(List,temp);
	}
	XepHang(List);
	return List;
}
void In(ptr &List){
	ptr run=List;
	while(run!=NULL){
		cout<<"Hang:"<<run->sv.Hang<<" Ten:"<<run->sv.ten<<" DiemTB:"<<run->sv.diemTB<<endl;
		run=run->next;
	}
}
void deleteAll(ptr List){
	ptr run,temp;
	if(List==NULL)return;
	else{
		run=List;
		while(run!=NULL){
			temp=run;
			run=run->next;
			delete temp;
		}
	}
}
int main(){
	ptr List=Nhap();
	In(List);
	deleteAll(List);
}
