#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int z=0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            z++;
        }
    }
    if(z==2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}