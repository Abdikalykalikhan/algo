#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_deliver(int capacity, int n, int k, vector<int>& islands) {
    int flights = 0;
    for (int i = 0; i < n; i++) {
        flights += (islands[i] + capacity - 1) / capacity;
    }
    return flights <= k;
}

int main() {
    // Read input
    int n, k;
    cin >> n >> k;
    vector<int> islands(n);
    for (int i = 0; i < n; i++) {
        cin >> islands[i];
    }

    // Find the least possible capacity
    int low = 1;
    int high = *max_element(islands.begin(), islands.end());
    while (low < high) {
        int mid = (low + high) / 2;
        if (can_deliver(mid, n, k, islands)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    // Print output
    cout << low << endl;

    return 0;
}