#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int q, k;
    cin >> q >> k;

    // Min-heap to keep track of the largest k boxes
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long totalCookies = 0;

    // Process each query
    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;
        
        if (command == "insert") {
            int cookies;
            cin >> cookies;
            
            // If we have less than k boxes, simply add the new box
            if (minHeap.size() < k) {
                minHeap.push(cookies);
                totalCookies += cookies;
            }
            // Otherwise, check if the new box has more cookies than the smallest in the heap
            else if (cookies > minHeap.top()) {
                totalCookies -= minHeap.top();  // Remove the smallest box
                minHeap.pop();
                minHeap.push(cookies);  // Add the new box
                totalCookies += cookies;
            }
        }
        else if (command == "print") {
            // Print the sum of cookies in the largest k boxes
            cout << totalCookies << endl;
        }
    }

    return 0;
}