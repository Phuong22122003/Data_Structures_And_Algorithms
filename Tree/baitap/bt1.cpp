#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
void postOrder(Node*root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
void Insert(Node *&tree,int data){
    Node *temp=new Node(data);
    if(tree==NULL){
        tree=temp;
        return;
    }
    else if(tree->data<data){
        Insert(tree->right,data);
    }
    else if(tree->data>data){
        Insert(tree->left,data);
    }
}
int main(){
    int n;
    cin>>n;
    Node*tree=NULL;
    while(n--){
        int data;
        cin>>data;
        Insert(tree,data);
    }
    postOrder(tree);
    return 0;
}