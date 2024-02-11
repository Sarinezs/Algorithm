#include<iostream>
using namespace std;

////// show Max sub-array sum version. /////

int maxsum(int a[], int n, int &start, int & stop){
    int max_so_far = -9999, max_i = 0;
    for(int i = 0; i<n; i++){
        max_i += a[i];
        if(max_i > max_so_far){
            stop = i+1;
            max_so_far = max_i;
        }
        if(max_i < 0){
            start = i+1;
            max_i = 0;
        }
    }

    return max_so_far;
}

int main(){
    int a[] = {16,-25,2,-54,36,9,-12,66};
    int n = sizeof(a) / sizeof(a[0]);
    int start = 0, stop = n;
    cout<<maxsum(a, n, start, stop)<<endl;

    for(int i = start; i<stop; i++){
        cout<<a[i]<<" ";
    }
}