#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> m;
    int two[m];
    for (int i = 0; i < m; i++){
        cin >> two[i];
    }
    int c = n + m;
    int all[c];
    for (int i = 0; i < n; i++){
            all[i] = arr[i];
    }
    for (int i = 0; i < m; i++){
        all[i + n] = two[i];
    }
    
    sort(all, all+c);
    for (int i = 0; i < c; i++){
        cout << all[i]<<' ';
    }
    
}