#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <cmath>

using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        std::cout << "Khong du bo nho!" << std::endl;
        return NULL;
    }
    newNode->info = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    Node* newNode = createNode(value);
    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (value < current->info) {
            current = current->left;
        } else if (value > current->info) {
            current = current->right;
        } else {
            // Giá trị đã tồn tại trong cây
            delete newNode;
            return root;
        }
    }

    if (value < parent->info) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        std::cout << root->info << " ";
        inorderTraversal(root->right);
    }
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

int get_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int height = 0;
    stack<pair<Node*, int> > stk;
    stk.push(make_pair(node, 1));
    while (!stk.empty()) {
        pair<Node*, int> current = stk.top();
        stk.pop();
        Node* currNode = current.first;
        int currHeight = current.second;
        if (currNode != NULL) {
            height = max(height, currHeight);
            stk.push(make_pair(currNode->left, currHeight + 1));
            stk.push(make_pair(currNode->right, currHeight + 1));
        }
    }
    return height;
}

Node* rotate_left(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

Node* rotate_right(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

Node* balance_left(Node* node) {
    if (get_height(node->right) - get_height(node->left) > 1) {
        if (get_height(node->right->left) > get_height(node->right->right)) {
            node->right = rotate_right(node->right);
        }
        node = rotate_left(node);
    }
    return node;
}

Node* balance_right(Node* node) {
    if (get_height(node->left) - get_height(node->right) > 1) {
        if (get_height(node->left->right) > get_height(node->left->left)) {
            node->left = rotate_left(node->left);
        }
        node = rotate_right(node);
    }
    return node;
}

Node* remove(Node* root, int value) {
    if (root == NULL) {
        std::cout << "Khong the xoa duoc nut " << value << " tren cay" << std::endl;
        return root;
    }

    Node* current = root;
    Node* parent = NULL;
    while (current != NULL && current->info != value) {
        parent = current;
        if (value < current->info) {
            current = current->left;
        } else {
            current = current->right;
        }
    }//log2(N)truong hop xau nhat

    if (current == NULL) {
        // Không tìm thấy giá trị cần xóa
        return root;
    }

    if (current->left == NULL && current->right == NULL) {
        // Xóa nút lá
        if (parent == NULL) {
            // Xóa gốc cây
            delete current;
            return NULL;
        }

        if (current == parent->left) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        delete current;
    } else if (current->left == NULL || current->right == NULL) {
        // Xóa nút có 1 con
        Node* child;
        if (current->left != NULL) {
            child = current->left;
        } else {
            child = current->right;
        }

        if (parent == NULL) {
            // Xóa gốc cây
            delete current;
            return child;
        }

        if (current == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;
    } else {
        // Xóa nút có 2 con
        Node* successor = findMinNode(current->right);
        current->info = successor->info;
        current->right = remove(current->right, successor->info);
    }

    // Cân bằng lại cây sau khi xóa
    root = balance_left(root);//N
    root = balance_right(root);//N
    //tong thoi gian 2N+log2(N)+...giảm dần
    return root;
}

void storeNodeValues(Node* root, vector<int>& node_values) {
    stack<Node*> stk;
    Node* current = root;
    while (current != NULL || !stk.empty()) {
        while (current != NULL) {
            stk.push(current);
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        node_values.push_back(current->info);
        current = current->right;
    }
}

Node* buildTreeFromArray(vector<int>& node_values, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* root = createNode(node_values[mid]);

    root->left = buildTreeFromArray(node_values, start, mid - 1);
    root->right = buildTreeFromArray(node_values, mid + 1, end);

    return root;
}

Node* convertBSTtoAVL(Node* root) {
    vector<int> node_values;
    storeNodeValues(root, node_values);
    return buildTreeFromArray(node_values, 0, node_values.size() - 1);
}

bool isBalanced(Node* root) {
    if (root == NULL) {
        return true;
    }

    stack<pair<Node*, int> > stk;
    stk.push(make_pair(root, 1));

    while (!stk.empty()) {
        pair<Node*, int> current = stk.top();
        stk.pop();
        Node* node = current.first;
        int height = current.second;

        if (node->left == NULL && node->right == NULL) {
            continue;
        }

        if (node->left != NULL) {
            stk.push(make_pair(node->left, height + 1));
        }
        if (node->right != NULL) {
            stk.push(make_pair(node->right, height + 1));
        }

        if (abs(get_height(node->left) - get_height(node->right)) > 1) {
            return false;
        }
    }

    return true;
}

void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }

    stack<Node*> stk;
    stk.push(root);

    while (!stk.empty()) {
        Node* current = stk.top();
        stk.pop();

        if (current->left != NULL) {
            stk.push(current->left);
        }
        if (current->right != NULL) {
            stk.push(current->right);
        }

        delete current;
    }
}

int main() {
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;
    Node* root = NULL;
    int n=20000;
    for (int i = 0; i < n; i++) {
        root = insert(root, i);
    }
    root = convertBSTtoAVL(root);
    start = clock();
    Node*temp=root;
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout << "Thoi gian chay getheight: " << time_use << '\n';
    start = clock();
    get_height(root->left);
    get_height(root->right);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout << "Thoi gian chay 2 getheight: " << time_use << '\n';
    start = clock();
    root = convertBSTtoAVL(root);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout << "Thoi gian chay convert: " << time_use << '\n';
    start = clock();
    root = remove(root, 99999);
    end = clock();

    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout << "Thoi gian chay remove: " << time_use << '\n';

    // if (isBalanced(root)) {
    //     cout << "Cay can bang" << endl;
    // } else {
    //     cout << "Cay khong can bang" << endl;
    // }
    root=insert(root,99999);
    start = clock();
    //root = remove(root, 60);
    root = convertBSTtoAVL(root);
    end = clock();

    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout << "Thoi gian chay convertBSTtoAVL: " << time_use << '\n';

    // if (isBalanced(root)) {
    //     cout << "Cay can bang" << endl;
    // } else {
    //     cout << "Cay khong can bang" << endl;
    // }

    deleteTree(root);

    return 0;
}
