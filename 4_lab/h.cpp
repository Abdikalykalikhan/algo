#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BinarySearchTree {
public:
    Node* root;
    int sum;

    BinarySearchTree() {
        root = nullptr;
        sum = 0;
    }

    Node* add(int data) {
        root = recursivelyInsert(data, root);
        return root;
    }

    Node* recursivelyInsert(int data, Node* root) {
        if (root == nullptr) {
            return new Node(data);
        }
        if (root->data >= data) {
            root->left = recursivelyInsert(data, root->left);
        } else {
            root->right = recursivelyInsert(data, root->right);
        }
        return root;
    }

    void newValuesForTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        newValuesForTree(node->right);
        sum += node->data;
        node->data = sum;
        newValuesForTree(node->left);
    }

    void printValues(Node* node) {
        if (node == nullptr) {
            return;
        }
        printValues(node->right);
        cout << node->data << " ";
        printValues(node->left);
    }
};

int main() {
    int size;
    cin >> size;

    vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    BinarySearchTree bst;
    for (int i : array) {
        bst.add(i);
    }

    bst.newValuesForTree(bst.root);
    bst.printValues(bst.root);
    cout << endl;

    return 0;
}
