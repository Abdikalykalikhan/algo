#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class A {
public:
    TreeNode* root;

    A() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    string solve(const string& path) {
        TreeNode* current = root;
        for (char direction : path) {
            if (direction == 'L') {
                if (current->left == nullptr) {
                    return "NO";
                } else {
                    current = current->left;
                }
            } else { // direction == 'R'
                if (current->right == nullptr) {
                    return "NO";
                } else {
                    current = current->right;
                }
            }
        }
        return "YES";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    getline(cin, input);
    istringstream iss(input);
    int n, m;
    iss >> n >> m;

    A bst;
    getline(cin, input);
    istringstream values(input);
    for (int i = 0; i < n; i++) {
        int val;
        values >> val;
        bst.insert(val);
    }

    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;
        cout << bst.solve(path) << endl;
    }

    return 0;
}
