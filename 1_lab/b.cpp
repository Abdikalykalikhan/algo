#include <iostream>
#include <stack>
using namespace std;
 
int main() { 
    int x; 
    cin >> x; 
     
    int li[x];  // объявляем массив вместо вектора 
 
    for (int i = 0; i < x; ++i) { 
        cin >> li[i];  // заполняем массив 
    } 
 
    cout << -1 << " ";  // выводим первый элемент -1 
 
    for (int i = 1; i < x; ++i) { 
        bool found = false; 
        for (int j = i - 1; j >= 0; --j) { 
            if (li[j] <= li[i]) { 
                cout << li[j] << " ";  // если найден элемент, выводим его 
                found = true; 
                break; 
            } 
        } 
        if (!found) { 
            cout << -1 << " ";  // если не найдено, выводим -1 
        } 
    } 
 
    return 0; 
}



/*
int main() {
    int N;
    cin >> N;  // Число людей в очереди

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];  // Возраст каждого человека
    }

    stack<int> s;  // Стек для хранения индексов людей
    int result[N];

    for (int i = 0; i < N; ++i) {
        // Убираем из стека всех людей старше или равных текущему
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }

        // Если стек пуст, значит, перед текущим нет младшего
        if (s.empty()) {
            result[i] = -1;
        } else {
            // Если стек не пуст, то на вершине стека находится младший человек
            result[i] = a[s.top()];
        }

        // Добавляем текущего человека в стек
        s.push(i);
    }

    // Вывод результата
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
*/