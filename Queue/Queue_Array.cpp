#include<iostream>
using namespace std;
#define MAX 100
struct queue{
    int head,tail;
    int A[MAX];
};
void Init(queue &list){
    list.head=-1;
    list.tail=-1;
}
bool EmptyQueue(queue list){
    if(list.head==-1&&list.tail==-1)return true;
    return false;
}
bool FullQueue(queue list){
    if(list.head==list.tail+1||list.head==0&&list.tail==MAX-1)return true;
    return false;
}
int put(int n,queue&list){
    if(FullQueue(list)){
        cout<<"Queue is full"<<endl;
        return 0;
    }
    if(EmptyQueue(list)){list.tail=-1;list.head=0;}
    if(list.tail==MAX-1){
        list.tail=-1;
    }
    list.A[++list.tail]=n;
    return 1;
}
int get(queue &list){
    if(EmptyQueue(list)){
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    int i=list.A[list.head];
    if(list.head==list.tail){ list.head=-1;list.tail=-1;}
    else {
        list.head++;
        if(list.head==MAX-1)list.head=0;
    }
    return i;
    
}
void show(queue a)
{
    for(int i=a.head;i<=a.tail;i++)cout<<a.A[i];
}
int main(){
    queue a;
    Init(a);
    put(1,a);
    put(2,a);
    put(3,a);
    put(4,a);
    get(a);
    //get(a);
    show(a);
    return 0;
}