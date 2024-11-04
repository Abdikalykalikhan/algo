#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input
    int n;
    cin >> n;
    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }
    sort(powers.begin(), powers.end());
    int rounds;
    cin >> rounds;
    for (int i = 0; i < rounds; i++) {
        int mark_power;
        cin >> mark_power;
        int count = 0;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (powers[j] <= mark_power) {
                count++;
                sum += powers[j];
            } else {
                break;
            }
        }
        cout << count << " " << sum << endl;
    }
    return 0;
}