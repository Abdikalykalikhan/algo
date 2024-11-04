#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for ( int i = 0; i < n; i++){
        cin >> arr[i];
    }
   
    while(n > 1){
        
        sort(arr, arr+n);
        
        int art[n];
        for ( int i = 0; i < n - 2; i++){
            art[i] = arr[i];
        }
        if (arr[n-1] > arr[n-2]){
            art[n-2] = arr[n-1] - arr[n-2];
            n--;
        }
        else n=n-2;
        
        int x = 0;
        for (auto i: art){
            x++;
        }
        for ( int i = 0; i < x; i++){
            arr[i] = art[i];
        }
    }
    if (n == 0){
        cout << 0;
    }
    else cout << arr[0];
    return 0;
}