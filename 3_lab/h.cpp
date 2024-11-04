#include <iostream>
#include <string>
using namespace std;

int main(){
    int block, mistake;
    cin >> block >> mistake;
    int arrb[block];
    long long arrm[mistake];
    long long prefixSum[block + 1]; // prefix sum array

    // initialize prefix sum array
    prefixSum[0] = 0;
    for (int i = 0; i < block; i++){
        cin >> arrb[i];
        prefixSum[i + 1] = prefixSum[i] + arrb[i];
    }

    for ( int i =0; i < mistake;i++){
        cin >> arrm[i];
    }

    for (int i = 0; i < mistake; i++){
        int low = 0, high = block;
        while (low < high) {
            int mid = (low + high) / 2;
            if (prefixSum[mid + 1] < arrm[i]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        cout << low + 1 << endl;
    }

    return 0;
}