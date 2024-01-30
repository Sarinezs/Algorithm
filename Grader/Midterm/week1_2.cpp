#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int n){
    int current_max = INT32_MIN, max_i = 0;
    for(int i = 0; i<n; i++){
        max_i += a[i];
        if(current_max < max_i){
            current_max = max_i;
        }

        if(max_i < 0){
            max_i = 0;
        }
    }

    return current_max;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<maxSubArraySum(a, n);
}