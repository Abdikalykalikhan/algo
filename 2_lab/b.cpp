#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<string> line(n);

    for(int i=0; i<n; i++){
        cin >> line[i];
    }

    for(int i=k; i<n; i++){
        cout << line[i] <<" ";
    }

    for(int i=0; i<k; i++){
        cout << line[i] <<" ";
    }

    return 0;
}