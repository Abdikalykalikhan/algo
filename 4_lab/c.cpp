#include <iostream> 
 
using namespace std; 
 
class Node 
{ 
public: 
 
    Node* parent; 
    Node* left; 
    Node* right; 
    int data; 
 
    Node(int data){ 
        parent = nullptr; 
        left = nullptr; 
        right = nullptr; 
        this->data = data; 
    } 
}; 
 
 
class BST 
{ 
private: 
    Node* root; 
public: 
    BST(){ 
        root = nullptr; 
    } 
    ~BST(){ 
        clear(root); 
    } 
    void clear(Node* node){ 
        if(node){ 
            clear(node->left); 
            clear(node->right); 
            delete node; 
        } 
    } 
 
    void insert(int newData){ 
        Node* newNode = new Node(newData); 
         
        Node* x = root; 
        Node* y = nullptr; 
        while(x){ 
            y = x; 
            if(newData<x->data) 
                x = x->left; 
            else 
                x = x->right; 
        } 
 
        if(y == nullptr){ 
            root = newNode; 
        } 
        else if(newData<y->data){ 
            newNode->parent = y; 
            y->left = newNode; 
        } 
        else{ 
            newNode->parent = y; 
            y->right = newNode; 
        } 
    } 
 
    Node* find(Node* node, int value){ 
        if(node == nullptr || node->data == value){ 
            return node; 
        } 
        if(value < node->data){ 
            return find(node->left, value); 
        }else{ 
            return find(node->right, value); 
        } 
    } 
     
    void printall(Node* node){ 
        if(node){ 
            cout << node->data << ' '; 
            printall(node->left); 
            printall(node->right); 
        } 
    } 
 
    void print(int value){ 
        Node* target = find(root, value); 
        if(target != nullptr){ 
            printall(target); 
        } 
    } 
 
}; 
 
 
 
main(){ 
 
    BST b; 
    int n; 
    cin >> n; 
    int arr[n]; 
    for (int i = 0; i < n; i++){ 
        cin >> arr[i]; 
        b.insert(arr[i]); 
    } 
     
    int m; 
    cin >> m; 
 
    b.print(m); 
 
    return 0; 
}