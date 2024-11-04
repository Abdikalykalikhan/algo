#include <iostream>
#include <string>

using namespace std;

class I {
private:
    struct ListNode {
        string data;
        ListNode* next;
        ListNode* previous;
        ListNode(string data) {
            this->data = data;
            next = nullptr;
            previous = nullptr;
        }
    };

    ListNode* head;
    ListNode* tail;

public:
    I() {
        head = nullptr;
        tail = nullptr;
    }

    void add_front(string value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            tail = newNode;
        } else {
            head->previous = newNode;
        }
        newNode->next = head;
        head = newNode;
        cout << "ok" << endl;
    }

    void add_back(string value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
        }
        tail = newNode;
        cout << "ok" << endl;
    }

    string erase_front() {
        if (head == nullptr) {
            return "error";
        }
        ListNode* temp = head;
        string result = temp->data;

        if (head == tail) {
            tail = nullptr;
        } else {
            head->next->previous = nullptr;
        }
        head = head->next;
        delete temp;
        return result;
    }

    string erase_back() {
        if (tail == nullptr) {
            return "error";
        }
        ListNode* temp = tail;
        string result = temp->data;

        if (head == tail) {
            head = nullptr;
        } else {
            tail->previous->next = nullptr;
        }
        tail = tail->previous;
        delete temp;
        return result;
    }

    string front() {
        if (head == nullptr) {
            return "error";
        }
        return head->data;
    }

    string back() {
        if (tail == nullptr) {
            return "error";
        }
        return tail->data;
    }

    void clear() {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok" << endl;
    }

    static void menu() {
        I dll;
        string command;
        string value;
        while (true) {
            cin >> command;
            if (command == "exit") {
                cout << "goodbye" << endl;
                break;
            } else if (command == "add_front") {
                cin >> value;
                dll.add_front(value);
            } else if (command == "add_back") {
                cin >> value;
                dll.add_back(value);
            } else if (command == "erase_front") {
                string result = dll.erase_front();
                cout << result << endl;
            } else if (command == "erase_back") {
                string result = dll.erase_back();
                cout << result << endl;
            } else if (command == "front") {
                string result = dll.front();
                cout << result << endl;
            } else if (command == "back") {
                string result = dll.back();
                cout << result << endl;
            } else if (command == "clear") {
                dll.clear();
            }
        }
    }
};

int main() {
    I::menu();
    return 0;
}
