#include <iostream>
#include <string>

using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x; 
    cin >> x;
    
    bool isfound = false;
    
    for (int i =0; i<n; i++){
        if (arr[i] == x){
            isfound = true;
        }
    }
    if (isfound){
        cout << "Yes";
    }
    else cout <<"No";
}