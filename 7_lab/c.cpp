#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int arn[n];
    int arm[m];
    
    for (int i =0 ; i < n ; i++){
        cin >> arn[i];
    }
    for (int i = 0; i < m ; i++){
        cin >> arm[i];
    }
    sort(arn, arn+n);
    sort(arm, arm+m);
    
    for (int i = 0; i < n;i++){
        bool isfound = false;
        for (int j = 0; j < m ; j++){
            if (arn[i] == arm[j]){
                isfound = true;
                arm[j] = -99;
                break;
            }
        }
        if (isfound) cout << arn[i]<< ' ';
        
    }
}