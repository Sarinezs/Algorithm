#include <iostream>
using namespace std;

void subset(int a[], int k, int n){
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int j = (k==0)? 1: a[k] += 1;
    for(int i = j; i<n+1; i++){
        a[k+1] = i;
        subset(a, k+1, n);
    }
}

int main(){
    int a[] = {1,2,3};
    int n = sizeof(a) / sizeof(a[0]);
    subset(a, 0, n);
}