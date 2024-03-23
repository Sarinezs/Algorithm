#include<iostream>
#include<cmath>
using namespace std;

bool isValid(int a[], int k) {
    for (int i = 0; i < k; i++) {
        if (a[i] == a[k] || abs(a[i] - a[k]) == abs(i - k)) {
            return false;
        }
    }
    return true;
}

void n_queen(int a[], int n, int k, int &count){
    if (k == n) {
        count++;
        // Printing the solution
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int row = 0; row < n; row++) {
        a[k] = row;
        if (isValid(a, k)) {
            n_queen(a, n, k + 1, count);
        }
    }
}

int main(){
    int n, count = 0;
    cin >> n;
    int a[n];
    n_queen(a, n, 0, count);
    // cout << count;
    return 0;
}
