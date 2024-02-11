#include<iostream>
using namespace std;

int max_sum(int a[], int low, int high){
    if(low == high){
        return a[low];
    }

    int mid = (low + high) / 2;
    int Lmss = max_sum(a, low, mid);
    int Rmss = max_sum(a, mid+1, high);

    int left_sum = -1000, right_sum = -1000, sum = 0;
    for(int i = mid+1; i<high; i++){
        sum += a[i];
        right_sum = max(right_sum, sum);
    }
    sum = 0;
    for(int i = mid; i>= 0; i--){
        sum += a[i];
        left_sum = max(left_sum, sum);
    }
    return max(max(Lmss, Rmss), left_sum + right_sum);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<max_sum(a,0,n-1);
}