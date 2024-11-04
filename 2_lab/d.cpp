#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // для сортировки
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> counts; // Счетчик для чисел

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        counts[x]++; // Увеличиваем счетчик для числа x
    }

    int maxCount = 0;
    for (map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
        if (it->second > maxCount) {
            maxCount = it->second; // Находим максимальное количество
        }
    }

    vector<int> modes; // Вектор для хранения чисел с максимальным количеством
    for (map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
        if (it->second == maxCount) {
            modes.push_back(it->first); // Добавляем число в вектор, если его количество равно максимальному
        }
    }

    sort(modes.rbegin(), modes.rend()); // Сортируем вектор по убыванию

    for (vector<int>::iterator it = modes.begin(); it != modes.end(); ++it) {
        cout << *it << " "; // Выводим числа
    }

    return 0;
}
