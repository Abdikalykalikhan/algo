#include <iostream>

using namespace std;

// Функция для проверки простого числа
bool isPrime(int num) {

    if (num <= 1) return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;  
    // Индекс простого числа

    int count = 0;  
    // Счётчик простых чисел

    int num = 2;    
    // Начинаем проверку с числа 2

    while (true) {
        if (isPrime(num)) {
            count++;  
            // Увеличиваем счётчик, если число простое

        }
        if (count == n) {
            cout << num << endl;  
            // Выводим n-е простое число

            break;
        }
        num++;  // Переходим к следующему числу
    }

    return 0;
}
