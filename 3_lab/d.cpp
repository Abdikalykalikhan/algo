#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upper_bound(vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int lower_bound(vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int get_answer(vector<int>& arr, int l, int r) {
    return upper_bound(arr, r) - lower_bound(arr, l) + 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++) {
        int cord[4];
        for (int j = 0; j < 4; j++) {
            cin >> cord[j];
        }
        if (cord[0] > cord[2]) {
            swap(cord[0], cord[2]);
            swap(cord[1], cord[3]);
        }

        if (cord[1] >= cord[2]) {
            if (cord[0] <= cord[2]) {
                cout << get_answer(arr, cord[0], max(cord[1], cord[3])) << endl;
            } else {
                cout << get_answer(arr, cord[2], max(cord[1], cord[3])) << endl;
            }
        } else {
            cout << get_answer(arr, cord[0], cord[1]) + get_answer(arr, cord[2], cord[3]) << endl;
        }
    }
    return 0;
}