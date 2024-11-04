#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> boris, nursik;
    int card, moves = 0;

    // Ввод карт Бориса
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        boris.push(card);
    }

    // Ввод карт Нурсика
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        nursik.push(card);
    }

    // Играем, пока не закончится одна из колод или не пройдет 1,000,000 ходов
    while (!boris.empty() && !nursik.empty() && moves < 1000000) {
        int boris_card = boris.front();
        int nursik_card = nursik.front();
        boris.pop();
        nursik.pop();

        // Проверка, кто выиграл текущий раунд
        if ((boris_card > nursik_card && !(boris_card == 9 && nursik_card == 0)) || 
            (boris_card == 0 && nursik_card == 9)) {
            boris.push(boris_card);
            boris.push(nursik_card);
        } else {
            nursik.push(boris_card);
            nursik.push(nursik_card);
        }

        ++moves;
    }

    // Проверяем результат игры
    if (boris.empty()) {
        cout << "Nursik " << moves << endl;
    } else if (nursik.empty()) {
        cout << "Boris " << moves << endl;
    } else {
        cout << "blin nichya" << endl;
    }

    return 0;
}
