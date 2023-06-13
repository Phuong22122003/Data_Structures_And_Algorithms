#include <iostream>
#include <conio.h>
#include <cctype>
#include <vector>
#include <Queue>
#include <math.h>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;
//***************************************************************************************************//
template <typename T>
struct Array
{
private:
    T *ptr;
    int number;
    int index_last;

public:
    Array()
    {
        ptr = NULL;
        number = 0;
        index_last = -1;
    }
    Array(int number_in)
    {
        ptr = new T[number_in];
        number = number_in;
        index_last = -1;
    }
    int GetIndexLast() { return index_last; }
    T &operator[](int i)
    {
        return ptr[i];
    }

    void push(T New)
    {
        if (index_last == number - 1)
        {
            T *temp;
            temp = new T[number + 10]; // tạo mảng mới
            for (int i = 0; i < number; i++)
            {
                temp[i] = ptr[i];
            }
            temp[index_last + 1] = New;
            delete[] ptr; // xóa mảng cũ
            ptr = temp;   // gán con trỏ vào mảng mới
            index_last++;
            number += 10;
        }
        else
        {
            ptr[++index_last] = New;
        }
    }
    void clear()
    {
        index_last = -1;
    }
    void erase(int i)
    {
        if (i < 0 || i > index_last)
            return;
        if (i == index_last)
        {
            index_last--;
            return;
        }
        for (int k = i; k < index_last; k++)
        {
            ptr[k] = ptr[k + 1];
        }
        index_last--;
    }

    void destroy()
    {
        delete[] ptr;
    }
};
struct ID
{
    int id;
    ID *left = NULL;
    ID *right = NULL;
};
typedef ID *createID;

int numNode(ID *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + numNode(root->left) + numNode(root->right);
}
void Insert(ID *&tree, int data)
{
    if (tree == NULL)
    {
        createID p = new ID;
        p->id = data;
        tree = p;
        return;
    }
    else if (tree->id < data)
    {
        Insert(tree->right, data);
    }
    else if (tree->id > data)
    {
        Insert(tree->left, data);
    }
    else
        return;
}
int InsertToBalance(ID *&root, int min, int max, ofstream &file)
{
    if (root == NULL)
    {
        root = new ID;
        root->id = (min + max) / 2;
        root->left = root->right = NULL;
        // Insert(root,(min+max)/2);
        file << (min + max) / 2 << endl;
        return 1;
    }
    else
    {
        if (numNode(root->left) == numNode(root->right))
        {
            max = root->id;
            InsertToBalance(root->left, min, max, file);
        }
        else
        {
            min = root->id;
            InsertToBalance(root->right, min, max, file);
        }
    }
}
void TaoFileID(int number=5)
{
    createID root = NULL;
    int n = number;
    ofstream file("key2.txt");
    file << 1 << endl;
    for (int i = 1; i <= pow(2, n) - 1; i++)
        InsertToBalance(root, 1, pow(2, n), file); // lay can duoi
    file.close();
}
int ReadID()
{
    int number, temp = 1;
    fstream docID("key2.txt", ios::in | ios::out);
    docID.seekg(ios::beg);
    docID >> number;
    for (int i = 1; i <= number; i++)
    {
        docID >> temp;
    }
    docID.close();
    ofstream a("key2.txt",ios::in);
    number++;
    docID << number;
    a.close();
    return temp;
}
//////////////////////////////////////////////////////////////////////////////
struct node
{
    int key;
    node *left = NULL;
    node *right = NULL;
};
void insertnode(node *&p, int key)
{
    if (p == NULL)
    {
        p = new node;
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    }
    else if (key < p->key)
        insertnode(p->left, key);
    else if (key > p->key)
        insertnode(p->right, key);
    else
        return;
}
void insert1(node *&p, node *in)
{
    if (p == NULL)
    {
        p = in;
        in->left = NULL;
        in->right = NULL;
        return;
    }
    else if (in->key < p->key)
    {
        insert1(p->left, in);
    }
    else if (in->key > p->key)
    {
        insert1(p->right, in);
    }
    else
    {
        return;
    }
}
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(node *root)
{
    if (root == NULL)
        return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

void printTreeHelper(node *root, int indent)
{
    if (root == NULL)
        return;
    printTreeHelper(root->right, indent + 4);
    for (int i = 0; i < indent; i++)
    {
        cout << " ";
    }
    cout << root->key << "\n";
    printTreeHelper(root->left, indent + 4);
}

void printTree(node *root)
{
    if (root == NULL)
        return;
    printTreeHelper(root, 0);
}
void Intraversal(Array<node *> &a, node *root)
{
    if (root != NULL)
    {
        Intraversal(a, root->left);
        a.push(root);
        Intraversal(a, root->right);
    }
}
node *convert(Array<node *> &a, int min, int max)
{
    if (min > max)
        return NULL;
    int mid = (min + max) / 2;
    node *temp = a[mid];
    temp->left = convert(a, min, mid - 1);
    temp->right = convert(a, mid + 1, max);
    return temp;
}
node *balance(node *root)
{
    Array<node *> a;
    Intraversal(a, root);
    node *root1;
    root1 = convert(a, 0, a.GetIndexLast());
    a.destroy();
    return root1;
}
void delAll(node *p)
{
    if (p != NULL)
    {
        delAll(p->left);
        delAll(p->right);
        delete p;
    }
}
node *search(node *p, int Id)
{
    if (p == NULL)
        return NULL;
    node *temp = p;
    while (1)
    {
        if (temp->key > Id)
            temp = temp->left;
        else if (temp->key < Id)
            temp = temp->right;
        else
            return temp;
    }
}
node *origintree(node *p)
{
    int number, temp = 1;
    fstream docID("key2.txt", ios::in | ios::out);
    docID.seekg(ios::beg);
    docID >> number;
    vector<node *> a(pow(2,14));
    number=pow(2,14);
    for (int i = 1; i < number; i++)//(N(2+log2(N)))
    {
        docID >> temp;
        a[i] = search(p, temp);
    }
    for (int i = 1; i < number; i++)//3N
    {
        a[i]->left = NULL;
        a[i]->right = NULL;
    }
    p = NULL;
    node *root = NULL;
    for (int i = 1; i < number; i++)//Nlog2(N)
    {
        insert1(root, a[i]);
    }
    return root;
}
node *temp;
void deleteHelper(node *&root)
{
    if (root->left != NULL)
        deleteHelper(root->left);
    else
    {
        temp->key = root->key;
        temp = root;
        root = temp->left;
    }
}
void deleteNode(node *&root, int id)
{
    if (root == NULL)
        return;
    if (root->key > id)
        deleteNode(root->left, id);
    else if (root->key < id)
        deleteNode(root->right, id);
    else
    {
        temp = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        else
        {
            deleteHelper(root->right);
        }
        delete temp;
    }
}
void SaveKEY(node *root)
{
    queue<node *> q;
    ofstream a("key1.txt");
    q.push(root);
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        q.pop();
        a << temp->key << endl;
    }
}
#include<time.h>
int main()
{
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;
    int number=7;
    TaoFileID(number);
    int id;
    node *root = NULL;
    start = clock();
    for (int i = 1; i < pow(2,number); i++)
    {
     
        
        insertnode(root, i);
        ReadID();
    }
    if(isBalanced(root))cout<<"\ncay can bang";
    else cout<<"cay ko can bang";
    end = clock(); 
    cout<<endl;
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay factorial(n): "<<time_use<<endl;
    cout<<"////////////////////////////////////////////////\n";
    start = clock();
    root=origintree(root);
    end = clock(); 
    cout<<endl;
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay factorial(n): "<<time_use<<'\n';
    printTree(root);
    if(isBalanced(root))cout<<"\ncay can bang";
    delAll(root);
}