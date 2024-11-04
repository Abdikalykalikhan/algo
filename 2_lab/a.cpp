#include <iostream>
#include <vector>
#include <cmath> // для функции abs
using namespace std;

int main() {
    int n, x;
    cin >> n;  // Читаем количество элементов в списке
    vector<int> arr(n);

    // Чтение списка
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Чтение числа x
    cin >> x;

    // Переменные для хранения минимальной разницы и соответствующего индекса
    int min_diff = abs(arr[0] - x); // минимальная разница
    int min_index = 0;              // индекс элемента с минимальной разницей

    // Проход по списку для нахождения ближайшего числа
    for (int i = 1; i < n; i++) {
        int diff = abs(arr[i] - x); // разница между текущим элементом и x

        // Если нашли элемент с меньшей разницей, обновляем минимальные значения
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }

    // Выводим индекс элемента с минимальной разницей
    cout << min_index << endl;

    return 0;
}
