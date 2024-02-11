#include<iostream>
using namespace std;

void combination(int a[], int n, int k, int r, int b[], int b_size, int coupon, int &count){
    if(r == 0){
        int cost = 0;
        for(int i = 0; i<b_size; i++){
            cost += b[i];
            if(cost > coupon){
                return;
            }
            count++;
        }
        if(cost <= coupon){
            for(int i = 0; i<b_size; i++){
                cout<<b[i]<<endl;
            }
        }
    }
    for(int i = k; i<n; i++){
        b[b_size] = a[i];
        combination(a, n, i+1, r-1, b, b_size+1, coupon, count);
    }
}

int main(){
    int n, b_size = 0, count = 0, coupon;
    cin>>n>>coupon;
    int a[n], b[n];
    for(int i = 0; i<n; i++){
        // a[i] = i+1;
        cin>>a[i];
    }
    combination(a, n, 0, 3, b, b_size, coupon, count);
    for(int i = 0; i<3; i++){
        cout<<b[i]<<" ";
    }
    // cout<<count;
}