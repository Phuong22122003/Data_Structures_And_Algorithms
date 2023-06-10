#include<iostream>
#include<Queue>
#include<algorithm>
using namespace std;
typedef int DoThi[50][50];
void Depth_traverse(DoThi G,int n,int u)
{
    //n đỉnh u là đỉnh bắt đầu
    int *dinh=new int[n];
    int stack[50];
    int sp=-1;
    int x,i;
    for(i=0;i<n;dinh[i++]=0);
    dinh[u]=1;
    stack[++sp]=u;//stack chứa đỉnh đầu tiên
    while(sp>=0)
    {
        x=stack[sp--];
        cout<<x<<" ";
        for(i=0;i<n;i++)
            if(G[x][i]==1&&dinh[i]==0)
            {
                stack[++sp]=i;
                dinh[i]=1;
            }
    }
}
void width_traverse(DoThi G,int n,int u)
{
    queue<int> q;
    int *dinh=new int[n];
    int i,x;
    for(i=0;i<n;dinh[i++]=0);
    dinh[u]=1;
    q.push(u);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        cout<<x<<" ";
        for(i=0;i<n;i++)
            if(G[x][i]==1&&dinh[i]==0)//kiểm tra các đỉnh kề với x và chưa được duyệt
            {
                q.push(i);
                dinh[i]=1;
            }
    }
}
int* width_traverse1(DoThi G,int n,int u)
{
    queue<int> q;
    int *dinh=new int[n];
    int i,x,dem=1;
    for(i=0;i<n;dinh[i++]=0);
    dinh[u]=1;
    q.push(u);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        cout<<x<<" ";
        for(i=0;i<n;i++)
            if(G[x][i]==1&&dinh[i]==0)//kiểm tra các đỉnh kề với x và chưa được duyệt
            {
                q.push(i);
                dinh[i]=dem;
            }
        if(q.empty())//kiểm tra xem còn đỉnh nào chưa duyệt thuộc thành phần liên thông khác
        {
            for(i=0;i<n;i++)
            {
                if(dinh[i]==0){
                    q.push(i);
                    dinh[i]=++dem;
                    break;
                }
            }
        }
    }
    return dinh;
}
int SoThanhPhanLT(int *a,int n)
{
    int dem=1;
    for(int i=0;i<n;i++)
    {
        if(dem<a[i])dem=a[i];
    }
    for(int i=1;i<=dem;i++){
        cout<<"CAC DINH THUOC THANH PHAN LIEN THON THU "<<i<<endl;
        for(int j=0;j<n;j++)
        {
            if(a[j]==i)cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main()
{
}