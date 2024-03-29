#include<iostream>
#include<algorithm>
using namespace std;

void perm(int a[], int k, int n){
    if(k == n){
        for(int i = 0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    for(int i = k; i<n; i++){
        sort(a+k,a+n);
        swap(a[i], a[k]);
        perm(a, k+1, n);
        swap(a[i], a[k]);
    }
}

int main(){
    int a[] = {3, 2, 1, 4};
    int n = 4;
    sort(a,a+n);

    perm(a, 0, n);
}