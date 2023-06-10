#include<iostream>
#include<time.h>
using namespace std;
const int M=1000;
#define free -1
struct item
{
    int key;
    string infor;
    int next;
};
item T[M+1];
int r;
int Hash(int key)
{
    return key%M;
}
int Hash1(string khoa)
{
    int key=0;
    for(int i=0;i<khoa.size();i++)key+=khoa[i]-'A'+1;
    return key%M;
}
void Init()
{
    for(int i=0;i<=M;i++)
        T[i].key=T[i].next=-1;
    r=M;
}
int Insert(int khoa,string noidung)
{
    int index=Hash(khoa);
    while(1)
    {
        if(T[index].key==free)
        {
            T[index].key=khoa;
            T[index].infor=noidung;
            T[index].next=free;
            return 1;
        }
        else if(T[index].key==khoa)return 0;
        else 
        {
            if(T[index].next==free)
            {
                while(r>0&&T[r].key!=free)r--;
                if(r==0){return 0;}
                T[index].next=r;
                T[r].infor=noidung;
                T[r].key=khoa;
                r--;
                return 1;
            }
            else index=T[index].next;
        }
    }

}
string Get(int khoa)
{
    int index=Hash(khoa);
    while(1)
    {
        if(T[index].key==khoa)return T[index].infor;
        else if(T[index].next!=-1)
        {
            index=T[index].next;
        }
        else
        {
            return "Khong co";
        }
    }
}
void In()
{
    for(int i=0;i<=M;i++)
    {
        cout<<"KEY:"<<T[i].key<<"  INFOR:"<<T[i].infor<<"  NEXT:"<<T[i].next<<endl;
    }
}
int main()
{
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;
    Init();
    Insert(1,"chao");
    Insert(2,"kkk2");
    Insert(3,"kkk3");
    Insert(4,"kkk4");
    Insert(10000,"kkk5");
    //In();
    //cout<<Get(2);
    //Insert(4,"kkk");
    // Insert(105,"kkk");
    // Insert(106,"kkk");
    start = clock(); 
    for(int i=0;i<100001;i++)if(T[i].key==1)cout<<T[i].infor;
    //cout<<Get(5)<<endl;
    end = clock(); 
    cout<<endl;
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay factorial(n): "<<time_use;
    // cout<<Get(5)<<endl;
    // cout<<Get(102);
}