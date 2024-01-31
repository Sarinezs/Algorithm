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
    return i+1;
}

int quickselect(int a[], int l, int r, int k){
    if(l <= r){
        int loop = 0;
        int index = partition(a, l, r);
        if(k == index){
            return 0;
        }

        if(k - 1 < index){
            loop++;
            loop += quickselect(a, l, index-1, k);
        }
        else{
            loop++;
            loop += quickselect(a, index+1, r, k);
        }
        return loop;

    }
}

int main(){
    int size,k;
    cin>>size;
    cin>>k;
    int a[size];
    for(int i = 0; i<size; i++){
        cin>>a[i];
    }
    int n = sizeof(a) / sizeof(a[0]);
    cout<<a[k-1]<<" "<<quickselect(a,0, n-1, k-1);
}