#include<iostream>
using namespace std;
template <typename T>
struct node
{
    T info;
    node<T> *next;
};
template <typename T>
class Queue
{
private:
    int number;
    node<T> *front;
    node<T> *rear;

public:
    Queue()
    {
        number = 0;
        front = NULL;
        rear = NULL;
    }
    void Push(T data)
    {
        node<T> *temp = new node<T>;
        temp->info = data;
        if (front == NULL)
            front = temp;
        else
            rear->next = temp;
        rear = temp;
        number++;
    }
    T pop()
    {
        if (!this->empty())
        {
            node<T> *run = front;
            T data = front->info;
            if (front == rear && front != NULL)
                front = rear = NULL;
            else
                front = front->next;
            delete run;
            number--;
            return data;
        }
    }
    bool empty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    int GetNumber() { return number; }
};
struct node1
{
    int key;
    int info;
    struct node1 *left;
    struct node1 *right;
};
typedef node1 *NODEPTR;
NODEPTR newnode(int key,int info)
{
        NODEPTR p = new node1;
        p->key = key;
        p->info = info;
        p->left = NULL;
        p->right = NULL;   
        return p;
}
void Insert_node(NODEPTR &p, int x, int a)
{
    
    if (p == NULL) // nút p hiện tại sẽ là nút lá
    {
        p = newnode(x,a);
        cout<<x<<endl;
    }
    else if (x < p->key)
        {
            Insert_node(p->left, x, a);
        }
    else if (x > p->key)
    {
        Insert_node(p->right, x, a);
    } 
    else return;
}

void Insert_node1(NODEPTR &p, int x, int a)
{
    cout<<x<<endl;
    if(p==NULL)
    {
        p = newnode(x,a);
    }
    else
    {
        NODEPTR temp=p;
        while(1)
            if(x<temp->key)
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode(x,a);
                    break;
                }
                temp=temp->left;

            }
            else if(x>temp->key) {
                if(temp->right==NULL)
                {
                    temp->right=newnode(x,a);
                    break;
                }
                temp=temp->right;
            }
            else break;
        
    }
}
NODEPTR rp ;  
void remove_case_3(NODEPTR &r)
{
    if (r->left != NULL)
        remove_case_3(r->left);
    // den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
    else
    {
        rp->key = r->key;   // Chep noi dung cua r sang rp ";
        rp->info = r->info; //  de lat nua free(rp)
        rp = r;
        r = rp->right;
    }
    delete rp; // giải phóng bộ nhớ đã cấp phát cho rp
}

void remove(int x, NODEPTR &p)
{
    if (p == NULL)
        printf("Khong tim thay");
    else if (x < p->key)
        remove(x, p->left);
    else if (x > p->key)
        remove(x, p->right);
    else // p->key = x
    {
        rp = p;
        if (rp->right == NULL)
            p = rp->left;
        // p là nút lá hoac la nut chi co cay con ben trai
        else if (rp->left == NULL)
            p = rp->right; // p là nut co cay con ben phai
        else
            remove_case_3(rp->right);
        delete rp;
    }
}
void XoaTheoND(NODEPTR& p,int content)
{
    if(p==NULL)return;
    Queue <NODEPTR>q;
    NODEPTR temp[100],temp1;
    int i=0;
    q.Push(p);
    while(!q.empty())
    {
        temp1=q.pop();
        if(temp1->info==content)temp[i++]=temp1;
        if(temp1->left!=NULL)q.Push(temp1->left);
        if(temp1->right!=NULL)q.Push(temp1->right);  
    }
    for(i=i-1;i>=0;i--)
    {
        if(temp[i]->info==content)
        {
            //cout<<temp[i]->key<<" "<<temp[i]->info<<endl;
            remove(temp[i]->key,p);
        }
    }
}
void TaoCay(NODEPTR&p)
{
    for(int i=1;i<=50000;i++)
    {
        if(i%2==0)
        Insert_node(p,i,1);
        else Insert_node(p,i,2);
    }
}
void in1(NODEPTR &p)
{
    if(p!=NULL)
    {
        cout<<p->key<<" "<<p->info<<endl;
        in1(p->left);
        in1(p->right);
    }
}
void in2(NODEPTR&p)
{
    if(p==NULL)return;
    Queue<NODEPTR>q;
    NODEPTR p1;
    q.Push(p);
    while(!q.empty())
    {
        p1=q.pop();
        cout<<p1->key<<" "<<p1->info<<endl;
        if(p1->left!=NULL)q.Push(p1->left);
        if(p1->right!=NULL)q.Push(p1->right);
    }
}
void deleteALL(NODEPTR &p)
{
    if(p!=NULL)
    {
        deleteALL(p->left);
        deleteALL(p->right);
        delete p;
        p=NULL;
    }
}
#include<time.h>
int main()
{
    clock_t start,end;
    start=clock();
    NODEPTR p=NULL;
    TaoCay(p);
    //XoaTheoND(p,1);
    
    //in1(p);
    //system("cls");
    end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<time;
    deleteALL(p);
    return 0;
}