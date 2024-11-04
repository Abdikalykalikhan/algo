#include <iostream> 
#include <algorithm> 
using namespace std; 
 
// Структура узла дерева 
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
 
    Node(int data) { 
        this->data = data; 
        left = NULL; 
        right = NULL; 
    } 
}; 
 
// Вставка узла в дерево 
Node* insert(Node* root, int data) { 
    if (root == NULL) { 
        return new Node(data); 
    }  
    if (data < root->data) { 
        root->left = insert(root->left, data); 
    } else if (data > root->data) { 
        root->right = insert(root->right, data); 
    } 
    return root; 
} 
 
// Функция для нахождения диаметра дерева и высоты поддеревьев 
int findDiameter(Node* root, int& diameter) { 
    if (root == NULL) return 0; 
 
    // Высота левого и правого поддеревьев 
    int leftHeight = findDiameter(root->left, diameter); 
    int rightHeight = findDiameter(root->right, diameter); 
 
    // Обновляем диаметр, используя текущий узел 
    diameter = max(diameter, leftHeight + rightHeight); 
 
    // Возвращаем высоту текущего поддерева 
    return max(leftHeight, rightHeight) + 1; 
} 
 
int main() { 
    int n; 
    cin >> n; 
    Node* root = NULL; 
 
    // Чтение данных и построение дерева 
    for (int i = 0; i < n; ++i) { 
        int x; 
        cin >> x; 
        root = insert(root, x); 
    } 
 
    // Поиск диаметра дерева 
    int diameter = 0; 
    findDiameter(root, diameter); 
 
    // Вывод диаметра (в количестве рёбер) 
    cout << diameter + 1 << endl; 
    return 0; 
}