#include <iostream>
#include <string>

using namespace std;

// Функция для обработки строки с учетом символов '#'
string processString(const string& s) {
    string result;
    for (char c : s) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back(); // Удаляем последний символ, если он есть
            }
        } else {
            result.push_back(c); // Добавляем обычный символ
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Обрабатываем обе строки
    string final_s1 = processString(s1);
    string final_s2 = processString(s2);

    // Сравниваем итоговые строки
    if (final_s1 == final_s2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
