#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    long long arr[k];
    for (int i = 0; i < k; i++){
        long long x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        if (y1 > y2){
            arr[i] = y1;
        }
        else arr[i] = y2;
    }
    sort(arr, arr+k);
    cout << arr[n-1];
    
}