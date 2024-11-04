#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct Node {
    int val;        // Значение узла
    Node* next;     // Указатель на следующий узел

    // Конструктор для инициализации узла
    Node(int x) : val(x), next(nullptr) {}
};

int findMaxSum(int n, Node* head) {
    int max_sum = head->val;  // Инициализируем максимальную сумму первым элементом
    int current_sum = 0;

    Node* cur = head;

    // Проходим по всем узлам списка
    while (cur != nullptr) {
        current_sum += cur->val;

        // Обновляем максимальную сумму
        max_sum = max(max_sum, current_sum);

        // Если текущая сумма становится меньше нуля, сбрасываем её
        if (current_sum < 0) {
            current_sum = 0;
        }

        cur = cur->next;
    }

    return max_sum;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Создаем односвязный список
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node* cur = new Node(x);  // Создаем новый узел с инициализацией значения

        if (i == 1) {
            head = tail = cur;  // Инициализируем голову и хвост
        } else {
            tail->next = cur;  // Присоединяем следующий элемент
            tail = cur;        // Обновляем хвост
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}