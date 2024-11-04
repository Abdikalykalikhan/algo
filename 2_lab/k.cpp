#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void process_stream(const vector<char>& stream) {
    unordered_map<char, int> freq;
    queue<char> q;
    vector<string> results;

    for (char c : stream) {
        // Update frequency map
        freq[c]++;
        
        // Update queue
        if (freq[c] == 1) {
            q.push(c);
        } else {
            // Remove from queue if it becomes repeating
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
        }
        
        // Output the first non-repeating character or -1 if none
        if (!q.empty()) {
            results.push_back(string(1, q.front()));
        } else {
            results.push_back("-1");
        }
    }

    // Print results
    for (const string& result : results) {
        cout << result << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<char> stream(N);
        for (int i = 0; i < N; i++) {
            cin >> stream[i];
        }
        process_stream(stream);
    }
    return 0;
}