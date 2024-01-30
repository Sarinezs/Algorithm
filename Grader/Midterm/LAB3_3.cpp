#include<iostream>
using namespace std;

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;

    for(int j = l; j<r; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

int qucikselect(int a[], int l, int r, int k, int n){
    if(l <= r){
        int index = partition(a,l,r);
        
        if(index == k-1){
            return a[index];
        }
        if(index > k-1){
            n += 1;
            return qucikselect(a, l, index-1, k, n);
        }
        else{
            n += 1;
            return qucikselect(a, index+1, r, k, n);
        }
        cout<<1<<endl;
    }
}

int main(){
    int a[] = {1,5,10,4,8,2,6};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4, l = 0;
    int ans = qucikselect(a,0,n-1,k-1, l);
    cout<<ans<<" "<<l;
}