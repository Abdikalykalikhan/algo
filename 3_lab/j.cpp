#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_steal(int n, int h, int x, vector<int>& bags) {
    int hours = 0;
    for (int i = 0; i < n; i++) {
        hours += (bags[i] + x - 1) / x;
    }
    return hours <= h;
}

int main() {
    // Read input
    int n, h;
    cin >> n >> h;
    vector<int> bags(n);
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    // Find the minimum number of bars that can be stolen per hour
    int low = 1;
    int high = *max_element(bags.begin(), bags.end());
    while (low < high) {
        int mid = (low + high) / 2;
        if (can_steal(n, h, mid, bags)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    // Print output
    cout << low << endl;

    return 0;
}