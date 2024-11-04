#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
bool compareByLength(const string &a, const string &b) {
    return a.length() < b.length(); 
}
int main() {
    vector<string> lines;
    string input;
    int numLines;

    cin >> numLines;
    cin.ignore();

   
    for (int i = 0; i < numLines; ++i) {
        getline(cin, input);
        lines.push_back(input); 
    }
    
    for (auto &line : lines) {
        istringstream iss(line);
        vector<string> words;
        string word;
        
        while (iss >> word) {
            words.push_back(word);
        }

        
        stable_sort(words.begin(),words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
        });
        
        line.clear(); 
        for (const auto &w : words) {
            line += w + " "; 
        }
        
        if (!line.empty()) {
            line.pop_back(); 
        }
    }
    
    
    for (const auto& line : lines) {
        cout << line << "\n";
    }

    return 0;
}