#include<iostream>
using namespace std;

int find_target(int a[], int low, int high, int target){
    if(low == high){
        int n = (a[low] == target)? 1 : 0;
        return n;
    }

    int mid = (low + high)/2;
    int left = find_target(a, low, mid, target);
    int right = find_target(a, mid+1, high, target);

    return left + right;
}

int main(){
    int n, target;
    cin>>n;
    cin>>target;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int result = find_target(a,0,n-1,target);

    if(result == 0){
        cout<<-1;
    }
    else{
        cout<<result;
    }
}