#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> dq;
    string command;

    while (cin >> command) {
        if (command == "!") {
            break; // Завершение программы
        } else if (command == "+") {
            int x;
            cin >> x;
            dq.push_front(x); // Добавляем элемент в начало
        } else if (command == "-") {
            int x;
            cin >> x;
            dq.push_back(x); // Добавляем элемент в конец
        } else if (command == "*") {
            if (dq.empty()) {
                cout << "error" << endl; // Если очередь пуста
            } else {
                // Суммируем первый и последний элемент
                int sum = dq.front() + dq.back();
                cout << sum << endl;
                
                // Удаляем первый и последний элемент
                dq.pop_front();
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
        }
    }

    return 0;
}
