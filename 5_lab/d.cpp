#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Min-heap to store the densities
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Input the densities and push into the min-heap
    for (int i = 0; i < n; i++) {
        int density;
        cin >> density;
        minHeap.push(density);
    }

    int operations = 0;

    // Process until the smallest density is >= k
    while (minHeap.size() > 1) {
        // Get the two smallest densities
        int smallest = minHeap.top();
        if (smallest >= k) {
            // All densities are already >= k
            break;
        }
        minHeap.pop();
        int second_smallest = minHeap.top();
        minHeap.pop();

        // Combine the two smallest densities
        int new_density = smallest + 2 * second_smallest;
        minHeap.push(new_density);

        // Increment the number of operations
        operations++;
    }

    // Check if we achieved the goal
    if (minHeap.top() >= k) {
        cout << operations << endl;
    } else {
        // If it's not possible to reach the required density
        cout << -1 << endl;
    }

    return 0;
}