#include <iostream> 
#include <queue> 
using namespace std; 
 
int main() { 
    int n; 
    cin >> n; 
    string s; 
    cin >> s; 
 
    queue<int> S_queue, K_queue; 
 
    // Populate the queues based on the input 
    for (int i = 0; i < n; i++) { 
        if (s[i] == 'S') { 
            S_queue.push(i); 
        } else { 
            K_queue.push(i); 
        } 
    } 
 
    // Process until one faction remains 
    while (!S_queue.empty() && !K_queue.empty()) { 
        int S_front = S_queue.front(); 
        int K_front = K_queue.front(); 
        S_queue.pop(); 
        K_queue.pop(); 
 
        // The smaller index kicks the other, and then goes to the back with a new position 
        if (S_front < K_front) { 
            S_queue.push(S_front + n);  // Push back with an incremented index 
        } else { 
            K_queue.push(K_front + n);  // Push back with an incremented index 
        } 
    } 
 
    // Determine the winner 
    if (S_queue.empty()) { 
        cout << "KATSURAGI" << endl; 
    } else { 
        cout << "SAKAYANAGI" << endl; 
    } 
 
    return 0; 
}