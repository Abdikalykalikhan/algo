#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    // Input and processing for the list of numbers
    int n;
    cin >> n; 
    vector<int> numbers(n);
    set<int> numbers_set;
    
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        numbers_set.insert(numbers[i]);
    }

    // Input for height and width
    int height, width;
    cin >> height >> width;
    
    vector<vector<int>> matrix(height, vector<int>(width));

    // Input for matrix
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> matrix[i][j];
        }
    }

    unordered_map<int, pair<int, int>> result;

    // Find numbers that are in both the set and the matrix
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (numbers_set.find(matrix[i][j]) != numbers_set.end()) {
                result[matrix[i][j]] = {i, j};
            }
        }
    }

    // Output the result
    for (int num : numbers) {
        if (result.find(num) != result.end()) {
            cout << result[num].first << " " << result[num].second << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
