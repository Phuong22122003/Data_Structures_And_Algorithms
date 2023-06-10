#include <bits/stdc++.h>

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

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        int height(Node* root) {
            if(root==NULL)return -1;
            int maxright=0;
            int maxleft=0;
            if(root!=NULL){
            if(root->left!=NULL){
                maxleft+=height(root->left);
            }
           if(root->right!=NULL){
                maxright+=height(root->right);
            }
            }
            else if(maxright>maxleft)return 1+maxright;
            else return 1+ maxleft;

        }
        int getHeight(Node* root){
        if ( root == NULL ){
            return -1;
        }
        else{
            return 1 + max( getHeight(root->left), getHeight(root->right) );
        }
}

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.getHeight(root);
    
  	std::cout << height;

    return 0;
}
