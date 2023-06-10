#include<iostream>
struct cauhoi{
    int ID;
    int content;
};
struct tree{
    cauhoi info;
    tree*left=NULL;
    tree*right=NULL;
};
typedef tree* STreeCH;
int SoNode(STreeCH root){
    if(root==NULL)return 0;
    return 1+SoNode(root->left)+SoNode(root->right);
}
int DeleteQuestion(STreeCH &root, STreeCH& Question)
{
    if(root->left==NULL&&root->right==NULL)
	{
    	STreeCH temp;
    	int ID=Question->info.ID;
    	if(root==Question)//truong hop nut Question la nut cuoi
		{
			temp=root;
			Question=NULL;
	        root=NULL;
	        delete temp;
		}
		else// truong hop Question khong phai la nut cuoi
		{
			temp=root;
	        Question->info=root->info;
	        Question->info.ID=ID;
	        root=NULL;
	        delete temp;	
		}
    }
    else 
        if(SoNode(root->left)>SoNode(root->right))DeleteQuestion(root->left,Question);
        else DeleteQuestion(root->right,Question);
}
using namespace std;
void in(STreeCH root){
    if(root!=NULL){
        cout<<root->info.ID<<" "<<root->info.content<<endl;
        in(root->left);
        in(root->right);
    }
}
int main(){
    STreeCH root=new tree;
    root->info.ID=1;
    root->left=new tree;
    root->left->info.ID=2;
    root->right=new tree;
    root->right->info.ID=3;
    root->right->info.content=3;
        root->right->right=new tree;
        root->right->right->info.ID=4;
        root->right->right->info.content=4;
    DeleteQuestion(root,root->left);
    //cout<<root->left->info.ID<<" "<<root->left->info.content;
    in(root);
}