#include<iostream>
using namespace std;

int binary_search(int a[], int l, int r, int k){
    if(l <= r){
        int m = l + (((k - a[l])*(r - l)) / (a[r] - a[l]));
        if(a[m] == k){
            cout<<m<<" ";
            return m;
        }
        if(a[m] < k){
            cout<<m<<" ";
            return binary_search(a, m+1, r, k);
        }
        else{
            cout<<m<<" ";
            return binary_search(a, l, m-1, k);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    
    binary_search(a, 0, n-1, k);
}