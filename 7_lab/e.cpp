#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const vector<int>& row1, const vector<int>& row2){
    int sum1 = 0;
    int sum2 = 0;
    for (int num : row1) sum1 += num;
    for (int num : row2) sum2 += num;
    
    if (sum1 != sum2) return sum1 > sum2;
    
    return row1 < row2;
    
}


int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> rows(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> rows[i][j];
        }
    }
    
    sort(rows.begin(), rows.end(), compare);
    
    for (const auto& row:rows){
        for (int num : row){
            cout << num << ' ';
        }
        cout << endl;
    }
}