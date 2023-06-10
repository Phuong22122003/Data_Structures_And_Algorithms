#include<iostream>
using namespace std;
void chuyendia(int a,string c,string d){
    cout<<"Chuyen dia thu "<<a<<" tu cot "<<c<<" sang cot "<<d<<endl;
};
void ThapHaNoi(int n,string A,string B,string C){
    if(n==1)cout<<"Chuyen dia  tu cot "<<A<<" sang cot "<<C<<endl;
    else{
        ThapHaNoi(n-1,A,C,B);
        ThapHaNoi(1,A,B,C);
        ThapHaNoi(n-1,B,A,C);
    }
};
int main(){
    int n;
    cout<<"Nhap vao so cot can chuyen"<<endl;
    cin>>n;
    ThapHaNoi(n,"A","B","C");
    return 0;
}