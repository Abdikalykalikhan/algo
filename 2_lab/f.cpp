#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

class LinkedList{
    Node* head;

public:
    LinkedList() : head(nullptr){}


    void insert(int value){
        Node* cur = new Node();
        cur->data = value;
        cur->next = nullptr;
        if(!head){
            head = cur;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = cur;
    }

    void inserttopos(int value, int pos){
        Node* cur = new Node();
        cur->data = value;
        cur->next = nullptr;

        if(pos < 1){
            cur->next = head;
            head = cur;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp->next == nullptr){
                delete cur;
                return;
            }
            temp = temp->next;
        }
        cur->next = temp->next;
        temp->next = cur;
    }

    void display(){
        if(!head){
            cout << "empty";
            return;
        }
        Node* temp = head;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.insert(x);
    }
    int val;
    cin >> val;
    int pos;
    cin >> pos;
    list.inserttopos(val, pos);
    list.display();

    return 0;
}