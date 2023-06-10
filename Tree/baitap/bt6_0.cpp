#include<iostream>
#include<conio.h>
#include<cctype>
#include<vector>
#include<Queue>
#include<math.h>
#include<fstream>
using namespace std;
// template <typename T>
// struct node
// {
//     T info;
//     node<T> *next;
// };
// template <typename T>
// class Queue
// {
// private:
//     int number ;
//     node<T> *front = NULL;
//     node<T> *rear = NULL;

// public:
// 	Queue(){
// 		number=0;
// 		front=NULL;
// 		rear=NULL;
// 	}
//     void Push(T data)
//     {
//         node<T> *temp = new node<T>;
//         temp->info = data;
//         if (front == NULL)
//             front = temp;
//         else
//             rear->next = temp;
//         rear = temp;
//         number++;
//     }
//     T pop()
//     {
//         if (!this->empty())
//         {
//             node<T> *run = front;
//             T data = front->info;
//             if (front == rear && front != NULL)
//                 front = rear = NULL;
//             else
//                 front = front->next;
//             delete run;
//             number--;
//             return data;
//         }
//     }
//     bool empty()
//     {
//         if (front == NULL)
//             return true;
//         else
//             return false;
//     }
//     int GetNumber() { return number; }
// };
// struct CauHoi
// {
//     int ID ;
//     char maMonHoc[16];
//     unsigned short answer;
//     char ans1[100];
//     char ans2[100];
//     char ans3[100];
//     char ans4[100];
//     char question[200];
// };
// typedef CauHoi *ptrCauHoi;
// struct nodeCauHoi
// {
//     CauHoi info; // key = info.ID;
//     nodeCauHoi *left = NULL;
//     nodeCauHoi *right = NULL;
// };

// typedef nodeCauHoi *STreeCH;
// void Store(createID root, vector<createID> &nodes)
// {
//     if (root != NULL)
//     {
//         Store(root->left, nodes);
//         nodes.push_back(root);
//         Store(root->right, nodes);
//     }
// }
// createID Convert(vector<createID> &nodes, int max, int min)
// {
//     if (max < min)
//         return NULL;
//     int mid = (max + min) / 2;
//     createID root = nodes[mid];
//     root->left = Convert(nodes, mid - 1, min);
//     root->right = Convert(nodes, max, mid + 1);
//     return root;
// }
// void Balance(createID &root)
// {
//     vector<createID> nodes;
//     Store(root, nodes);
//     root=Convert(nodes, nodes.size() - 1, 0);
// }
// void a(int arr[],createID root){
//     queue<ID*>q;
//     int i=0;
//     q.push(root);
//     while(!q.empty())
//     {
//         arr[i++]=q.front()->id;
//         cout<<q.front()->id<<endl;
//         if(q.front()->left!=NULL)q.push(q.front()->left);
//         if(q.front()->right!=NULL)q.push(q.front()->right);
//         q.pop();   
//     }
// }
// int getHeight(ID* root){
//         if ( root == NULL ){
//             return -1;
//         }
//         else{
//             return 1 + max( getHeight(root->left), getHeight(root->right) );
//         }
// }



// void INTree(ID* tree)
// {
//     queue<ID*>q;
//     q.push(tree);
//     int i=0;
    
//          while(!q.empty())
//         {   
//                 cout<<i<<":"<<q.front()->id<<" ";
//                 if(q.front()->left!=NULL)q.push(q.front()->left);
//                 if(q.front()->right!=NULL)q.push(q.front()->right);
//                 q.pop();
//                 i++;
//         }
// }
// int InsertQuestion(STreeCH &root, STreeCH question)
// {
//     if (root == NULL)
//     {
//         root = question;
//         return 1;
//     }
//     else
//     {
//         if (root->info.ID > question->info.ID)
//             return InsertQuestion(root->left, question);
//         else if (root->info.ID < question->info.ID)
//             return InsertQuestion(root->right, question);
//         else
//             return 0;
//     }
// }
// int doc_danhSachCauHoi(STreeCH &dsch)
// {
//     ifstream docfile("DanhSachCauHoi.txt");
//     STreeCH question;
//     string temp;
//     if (!docfile)
//         return 0;
//     while (!docfile.eof())
//     {
//         question = new nodeCauHoi;
//         docfile.getline(question->info.maMonHoc, 16);
//         docfile >> question->info.ID;
//         docfile.ignore();
//         docfile.getline(question->info.question, 200);
//         docfile.getline(question->info.ans1, 100);
//         docfile.getline(question->info.ans2, 100);
//         docfile.getline(question->info.ans3, 100);
//         docfile.getline(question->info.ans4, 100);
//         docfile >> question->info.answer;
//         docfile.ignore();
//         InsertQuestion(dsch, question);
//     }
//     docfile.close();
// }

// int ghi_danhSachCauHoi(STreeCH dsch)
// {
//     int *arr=new int[8191];
//     int i=0;
//     newID(arr,i);
//     i=0;
//      ofstream ghifile("DanhSachCauHoi.txt");

//     Queue<STreeCH> q;
//     STreeCH temp;

//     if (!ghifile)
//         return 0;
//     q.Push(dsch);
//     while (!q.empty())
//     {
//         temp = q.pop();
//         if (temp->left != NULL)
//             q.Push(temp->left);
//         if (temp->right != NULL)
//             q.Push(temp->right);
//         ghifile << temp->info.maMonHoc << endl
//                 << arr[i++]<< endl
//                 << temp->info.question << endl
//                 << temp->info.ans1 << endl
//                 << temp->info.ans2 << endl
//                 << temp->info.ans3 << endl
//                 << temp->info.ans4 <<endl
//                 << temp->info.answer;
//         if (!q.empty())
//             ghifile << endl;
//     }
//     ghifile.close();
//     delete []arr;
// }
// int findend(createID &root){
//     if(root==NULL)return -1;
//     else{
//         {
//             if(root->left==NULL&&root->right==NULL){
//                  i=root->id;
//                 //delete root;
//                 root=NULL;
//                 return i;
//             }
//             else if(numNode(root->left)>numNode(root->right))findend(root->left);
//             else findend(root->right);
//         }
//     }
// }
// int newID(int arr[],int &i){
//     ifstream file("key.txt");
//     while(!file.eof()){
//         file>>arr[i++];
//         file.ignore();
//     }
// }

//***************************************************************************************************//
struct ID{
    int id;
    ID*left=NULL;
    ID*right=NULL;
};
typedef ID*createID;

int numNode(ID*root){
    if(root==NULL)return 0;
    else return 1+numNode(root->left)+numNode(root->right);
}
void deleteAll(ID * root)
{
    deleteAll (root->left);
    deleteAll(root->right);
    delete root;
}
void Insert(ID *&tree,int data){
    if(tree==NULL){
        createID p=new ID;
        p->id=data;
        tree=p;
        return;
    }
    else if(tree->id<data){
        Insert(tree->right,data);
    }
    else if(tree->id>data){
        Insert(tree->left,data);
    }
    else return ;
}
int InsertToBalance(ID*&root,int min,int max,int &value,ofstream &file){
    if(root==NULL)
    {
        Insert(root,(min+max)/2);
        value=(min+max)/2;
        //cout<<temp<<endl;
        file.write(reinterpret_cast<const char *>(&value),sizeof(int));
    }
    else{
        if(numNode(root->left)==numNode(root->right)){
            max=root->id;
            InsertToBalance(root->left,min,max,value,file);
        }
        else{
            min=root->id;
            InsertToBalance(root->right,min,max,value,file);
        }
    }
}
void TaoFileID()
{
    createID root=NULL;
    int n=14,i=1,value;
    ofstream file("KeyID.bin",ios::binary);
    file.write(reinterpret_cast<char*>(&i),sizeof(int));
    for(i=1;i<=pow(2,n)-1;i++)InsertToBalance(root,1,pow(2,n),value,file);//lay can duoi
    deleteAll(root);
    file.close();
}
int ReadID()
{
    int number=1,temp=0;
    ifstream docID1("key2.bin",ios::binary);
    docID1.read(reinterpret_cast<char *>(&number),sizeof(int));
    docID1.seekg(number*sizeof(int),ios::beg);
    docID1.read(reinterpret_cast<char *>(&temp),sizeof(int));
    docID1.close();
    fstream docID2("key2.bin",ios::binary|ios::out|ios::in);
    number++;
    docID2.write(reinterpret_cast<char*>(&number),sizeof(int));
    docID2.close();
    return temp;
}
void restoreID(){
    int number;
    fstream docID("key.bin",ios::in|ios::out|ios::binary);
    if(!docID.is_open())
    {
        TaoFileID();
    }
    docID>>number;
    docID.seekp(ios::beg);
    docID<<--number;
}
struct node{
    int key;
    node*left;
    node*right;
};
void insertnode(node*&p,int key){
    if(p==NULL)
    {
        p=new node;
        p->key=key;
        p->left=NULL;
        p->right=NULL;
    }
    else if(key<p->key)insertnode(p->left,key);
    else if(key>p->key)insertnode(p->right,key);
    else return;
}
int getHeight(node* root) {
    if (root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(node* root) {
    if (root == NULL) return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

void printTreeHelper(node* root, int indent) {
    if (root == NULL) return;
    printTreeHelper(root->right, indent + 4);
    for (int i = 0; i < indent; i++) {
        cout << " ";
    }
    cout << root->key << "\n";
    printTreeHelper(root->left, indent + 4);
}

void printTree(node* root) {
    if (root == NULL) return;
    printTreeHelper(root, 0);
}
void deleteA(node* root)
{
    deleteA(root->left);
    deleteA(root->right);
    delete root;
}
#include<conio.h>
#include <Windows.h>
int main(){
    // int k;
    // node*p=NULL;
    // for(int i=0;i<pow(2,14);i++)
    // {
    //     k=ReadID();
    //     insertnode(p,k);
    // }
    
    // if(isBalanced(p))cout<<"cay can bang ";
    // else cout<<"cay khong can bang";
    // deleteA(p);
    //TaoFileID();
   // cout<<ReadID();
    fstream a("KeyID.bin",ios::binary|ios::out|ios::in);
    if(!a.is_open()){cout<<"khong mo dc";}
    a.seekp(ios::beg);
    int t=58;
    a.write(reinterpret_cast<char*>(&t),4);
    a.seekg(0*4,ios::beg);
    a.read(reinterpret_cast<char*>(&t),4);
    cout<<t;
}
