#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // Size of the list

    // Min-heap to store the sizes of arrays
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    // Input the sizes of the arrays and push them into the min-heap
    for (int i = 0; i < n; i++) {
        long long size;  // Use long long to handle larger numbers
        cin >> size;
        minHeap.push(size);
    }

    long long totalCost = 0; // Use long long to avoid overflow

    // Continue merging until we have only one array left
    while (minHeap.size() > 1) {
        // Get the two smallest lengths
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();

        // Calculate the cost of merging
        long long cost = first + second; // Ensure this is long long
        totalCost += cost;               // Keep total cost as long long

        // Push the merged array back into the min-heap
        minHeap.push(cost);
    }

    // Output the total minimum cost
    cout << totalCost << endl;

    return 0;
}