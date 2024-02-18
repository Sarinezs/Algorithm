#include<iostream>
using namespace std;

void bubblesort(int a[], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void combination(int a[], int n, int k, int r, int b[], int b_size, int coupon, int &count, int ans[]){
    int cost = 0;
    for(int i = 0; i<b_size; i++){
        cost += b[i];
        if(cost > coupon){
            return;
        }
    }

    if(r == 0){
        count++;
        for(int i = 0; i<b_size; i++){
            cout<<b[i]<<" ";
            ans[i] = b[i];
            if(i == b_size-1){
                cout<<"sum = "<<cost<<endl;
            }
        }
        
    }
    for(int i = k; i<n; i++){
        b[b_size] = a[i];
        combination(a, n, i+1, r-1, b, b_size+1, coupon, count, ans);
    }
}

int main(){
    int n, b_size = 0, count = 0, coupon, r = 3;
    cin>>n>>coupon;
    int a[n], b[n], ans[n];
    for(int i = 0; i<n; i++){
        // a[i] = i+1;
        cin>>a[i];
    }
    cout<<endl;
    combination(a, n, 0, r, b, b_size, coupon, count, ans);
    bubblesort(ans, r);
    for(int i = 0; i<r; i++){
        cout<<ans[i]<<" ";
    }
    // cout<<count;
}