#include <iostream> 
#include <map> 
using namespace std; 
 
struct Node { 
    int data; 
    int count; // кратность ключа 
    Node* left; 
    Node* right; 
 
    Node(int data) { 
        this->data = data; 
        this->count = 1; // при создании узла кратность равна 1 
        left = NULL; 
        right = NULL; 
    } 
}; 
 
// Функция для поиска минимального значения в дереве 
Node* getMin(Node* root) { 
    while (root->left != NULL) { 
        root = root->left; 
    } 
    return root; 
} 
 
// Функция для добавления узла в дерево 
Node* add(Node* root, int data) { 
    if (root == NULL) { 
        return new Node(data); 
    } else if (root->data > data) { 
        root->left = add(root->left, data); 
    } else if (root->data < data) { 
        root->right = add(root->right, data); 
    } else { 
        // Если ключ уже есть, увеличиваем кратность 
        root->count++; 
    } 
    return root; 
} 
 
// Функция для удаления узла из дерева 
Node* deleteNode(Node* root, int data) { 
    if (root == NULL) { 
        return NULL; 
    } else if (root->data > data) { 
        root->left = deleteNode(root->left, data); 
    } else if (root->data < data) { 
        root->right = deleteNode(root->right, data); 
    } else { 
        // Если кратность больше 1, просто уменьшаем кратность 
        if (root->count > 1) { 
            root->count--; 
            return root; 
        } 
        // Если кратность 1, нужно удалить узел 
        if (root->left == NULL && root->right == NULL) { 
            delete root; 
            return NULL; 
        } else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } else if (root->left == NULL) { 
            Node* temp = root->right; 
            delete root; 
            return temp; 
        } else { 
            Node* temp = getMin(root->right); 
            root->data = temp->data; 
            root->count = temp->count; // не забываем перенести кратность 
            root->right = deleteNode(root->right, temp->data); 
            return root; 
        } 
    } 
    return root; 
} 
 
// Функция для поиска узла в дереве 
Node* find(Node* root, int data) { 
    if (root == NULL) { 
        return NULL; 
    } else if (root->data == data) { 
        return root; 
    } else if (root->data < data) { 
        return find(root->right, data); 
    } else { 
        return find(root->left, data); 
    } 
} 
 
int main() { 
    int q; 
    cin >> q; // Читаем количество запросов 
    Node* root = NULL; 
 
    while (q--) { 
        string query; 
        int x; 
        cin >> query >> x; 
 
        if (query == "insert") { 
            root = add(root, x); 
        } else if (query == "delete") { 
            root = deleteNode(root, x); 
        } else if (query == "cnt") { 
            Node* node = find(root, x); 
            if (node == NULL) { 
                cout << 0 << endl; // если узел не найден, кратность равна 0 
            } else { 
                cout << node->count << endl; // выводим кратность найденного узла 
            } 
        } 
    } 
 
    return 0; 
}