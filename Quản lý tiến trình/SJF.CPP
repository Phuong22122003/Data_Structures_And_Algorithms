#include<iostream>
using namespace std;
int main(){
    int n,current,min,index,come[10],start[10] ,brushtime[10],finish[10]={0};
    cout<<"Nhap so tien trinh: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout << "Tien trinh " << i << endl;
        cout << "Nhap thoi gian den: ";
        cin >> come[i];
        cout << "Nhap thoi gian can thuc thi (brushtime): ";
        cin >>brushtime[i];
    }
    current = come [0];
    for(int i=0,j;i<n;i++){
        min = -1;
        for(j = 0;j<n ;j++){
            if(come[j]<=current&&finish[j]==0&&(min == -1||brushtime[j]<min)){
                min = brushtime[j];
                index = j;
            }
        }
        start[index] = current;
        current += brushtime[index];
        finish[index] = current;
    }
    cout<<"Tien trinh\t  Thoi diem den\t batdau\t Brushtime\t  finish\n";
    for(int i =0;i<n; i++){
        cout<<"Tien trinh "<<i+1<<"\t\t"<<come[i]<<"\t   "<<start[i]<<"\t    "<<brushtime[i]<<"\t\t     "<<finish[i]<<endl;
    }
}