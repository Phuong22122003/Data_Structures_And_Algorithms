#include<cstdlib>
#include<iostream>
#include<conio.h>
using namespace std;
int main(int argc, char *argv){
    int pn[10];
    int arr[10], bur[10], finish[10],star[10],tat[10],wt[10],i,n;
    int totwt = 0, tottat = 0;
    cout<<"Nhap so luong tien trinh: ";
    cin>>n;
    for(i = 0;i<n;i++){
        cout<<"Nhap ten tien trinh: ";
        cin>>pn[i];
        cout<<"Nhap thoi gian den: ";
        cin>>arr[i];
        cout<<"Nhap thoi gian can thuc thi (Burst time): ";
        cin>>bur[i];
    }
    for(i =0;i<n;i++){
        if(i==0){
            star[i] = arr[i];
            wt[i] = star[i]-arr[i];
            finish[i]=star[i] + bur[i];
            tat[i]=finish[i]-arr[i];
        }
        else {
            star[i] = finish[i-1];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i]=finish[i]-arr[i];
        }
    }
    cout<<"\nTien trinh    T/g den    Brust time   Start    TAT    Finish\n";
    for (i=0;i<n;i++){
        cout<<pn[i]<<"              " <<arr[i]<<"          "<<bur[i]<<"            "<<star[i]<<"        "<<tat[i]<<"       "<<finish[i]<<endl;
        totwt += wt[i];
        tottat += tat[i];
    }
    getch();
    return 0;
}