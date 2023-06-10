#include<iostream>
using namespace std;
#define queuesize 100
struct queue{
    int front,rear;
    int Arr[queuesize];
};
struct queue q;
void inti(queue &q){
    q.front=q.rear=-1;
}
int empty(queue q){
    return ((q.front==-1)?1:0);
}
int full(queue q){
    return (q.front-q.rear==1||q.rear-q.front+1==queuesize)?1:0;
}
int insert_queue(queue&q,int x){
    if(full(q))return 0;
    if(q.front==-1)
    {
        q.front=0;
        q.rear=-1;
    }
    if(q.rear==queuesize-1)q.rear=-1;
    q.rear++;
    q.Arr[q.rear]=x;
    return 1;
}
int delete_queue(queue&q,int &x){
    if(empty(q))return 0;
    x=q.Arr[q.front];
    if(q.front==q.rear)
    {
        q.front=-1;
        q.rear=-1;
    }
    else
    {
        q.front++;
        if(q.front==queuesize)
        q.front=0;
    }
    return 1;
}
double modf(double n,double *x){
    *x=(int)n;
    return n-*x;
}
void dec_bin(double n){
    double positive;
    double r,le;
    le=modf(n,&positive);
    int i=0;
    do
    {
        r=le*2;
        le=modf(r,&positive);
        insert_queue(q,positive);
        i++;
    } while (i<8&&r!=1);
    int x;
    while(!empty(q))
    {
        delete_queue(q,x);
        cout<<x<<endl;
    }
}
int main(){
    float n;
    inti(q);
    cin>>n;
    dec_bin(n);
}