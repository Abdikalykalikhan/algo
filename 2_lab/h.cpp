#include <iostream>

using namespace std;

typedef struct Node{
    int value;
    Node* next;
}Node;

class LinkedList{

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int pos, int val) {
        Node* newNode = new Node();
        newNode->value = val;
        newNode->next = nullptr;

        if (pos == 0) {  
            newNode->next = head;  
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr) {
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr) {
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }


    void remove(int pos){
        Node* temp = head;
        if(!head){
            return;
        }
        if(pos == 0){
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }
        for(int i = 0; i < pos - 1; i++){
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void print(){
        Node* temp = head;
        if(!head){
            cout << "-1" << endl;
            return;
        }
        while(temp != nullptr){
            cout << temp->value << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
    void replace(int pos, int postoinsert) {
        if (head == nullptr || pos == postoinsert) {
            return;
        }

        Node* temp = head;
        Node* toIns = nullptr;

        // Извлечение узла из позиции pos
        if (pos == 0) {  // Если узел извлекается с начала списка
            toIns = head;
            head = head->next;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                if (temp == nullptr || temp->next == nullptr) {
                    return;  // Если позиция вне списка
                }
                temp = temp->next;
            }

            toIns = temp->next;  // Узел, который нужно переместить
            if (toIns == nullptr) return;  // Если узел пуст
            temp->next = toIns->next;  // Удаление узла
        }

        // Вставка узла на позицию postoinsert
        if (postoinsert == 0) {
            toIns->next = head;
            head = toIns;
        } else {
            temp = head;
            for (int i = 0; i < postoinsert - 1; i++) {
                if (temp == nullptr) return;  // Проверка границ
                temp = temp->next;
            }

            toIns->next = temp->next;  // Вставка узла
            temp->next = toIns;
        }
    }



    
    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev; 
    }

    void cyclic_left(int t){
        if (!head || t == 0) return;  

        Node* temp = head;
        int length = 1;

        // Вычисляем длину списка
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        // Соединяем последний элемент с головой для создания кольца
        temp->next = head; 

        // t может быть больше длины списка, поэтому используем остаток
        t = t % length;

        // Найти новый хвост (узел, который будет перед новым началом)
        Node* newTail = head;
        for (int i = 1; i < t; ++i) {
            newTail = newTail->next;
        }

        // Новый голова — следующий элемент за новым хвостом
        head = newTail->next;

        // Разрываем кольцо
        newTail->next = nullptr;
    }


    void cyclic_right(int t){
        if (!head || t == 0) return;  
        Node* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        temp->next = head;

        t = t % length;
        int newHeadPos = length - t;

        Node* newHead = head;
        Node* newTail = nullptr;
        for (int i = 1; i < newHeadPos; ++i) {
            newHead = newHead->next;
        }
        newTail = newHead;

        head = newHead->next;
        newTail->next = nullptr;
    }

};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    while(n != 0){
        if(n == 1){
            int val;
            int pos;
            cin >> val >> pos;
            list.insert(pos, val);
        }
        else if(n == 2){
            int pos;
            cin >> pos;
            list.remove(pos);
        }
        else if(n == 3){
            list.print();
        }
        else if(n == 4){
            int pos1;
            int pos2;
            cin >> pos1 >> pos2;
            list.replace(pos1, pos2);
        }
        else if(n == 5){
            list.reverse();
        }
        else if(n == 6){
            int pos;
            cin >> pos;
            list.cyclic_left(pos);
        }
        else if(n == 7){
            int pos;
            cin >> pos;
            list.cyclic_right(pos);
        }
        cin >> n;
    }


    return 0;
}