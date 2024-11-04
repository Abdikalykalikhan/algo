#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Max-heap to store the number of free seats in rows
    priority_queue<int> maxHeap;

    // Input the number of free seats in each row and push them into the max-heap
    for (int i = 0; i < n; i++) {
        int seats;
        cin >> seats;
        maxHeap.push(seats);
    }

    long long totalEarnings = 0;

    // Process all the fans in line
    for (int i = 0; i < m; i++) {
        // Get the row with the maximum free seats
        int maxSeats = maxHeap.top();
        maxHeap.pop();

        // Add the current number of seats (price of the ticket) to the total earnings
        totalEarnings += maxSeats;

        // Decrease the number of free seats in that row and push it back if there are still seats left
        if (maxSeats > 1) {
            maxHeap.push(maxSeats - 1);
        }
    }

    // Output the total earnings
    cout << totalEarnings << endl;

    return 0;
}