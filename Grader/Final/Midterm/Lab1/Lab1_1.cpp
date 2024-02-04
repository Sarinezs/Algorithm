#include<iostream>
using namespace std;

int divide(int a[], int l, int r){
    if(l == r){
        return a[l];
    }
    int m = (l + r)/2;
    int left = divide(a, l, m);
    int right = divide(a, m+1, r);

    int mid_count = 0;


    for(int i = m+1; i<r-1; i++){
        if(a[i] - a[i+1] != 1){
            mid_count++;
        }
    }
    for(int i = m; i>=1; i--){
        if(a[i] - a[i-1] != 1){
            mid_count++;
        }
    }

    return max(max(left, right), mid_count);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<divide(a, 0, n-1);
}