#include <iostream>
#include <vector>

using namespace std;

// Функция для нахождения всех простых чисел до maxN с помощью Решета Эратосфена
vector<int> sieve_of_eratosthenes(int maxN) {
    vector<bool> is_prime(maxN + 1, true);
    vector<int> primes;
    
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= maxN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= maxN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    return primes;
}

int main() {
    int n;
    cin >> n;
    
    // Выбираем некоторое разумное ограничение для Решета Эратосфена
    int maxN = 10000;  // Это должно быть достаточно для нахождения 100 суперпростых
    
    // Находим все простые числа до maxN
    vector<int> primes = sieve_of_eratosthenes(maxN);
    
    // Создаем массив суперпростых чисел
    vector<int> superprimes;
    
    // Проходим по простым числам и выбираем те, у которых индекс тоже прост
    for (int i = 1; i <= primes.size(); ++i) {
        if (i <= primes.size() && primes[i - 1] <= primes.size()) {
            superprimes.push_back(primes[primes[i - 1] - 1]);
        }
    }

    // Выводим n-е суперпростое число
    cout << superprimes[n - 1] << endl;

    return 0;
}
