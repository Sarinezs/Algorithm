#include<iostream>
using namespace std;

int Least_Difference_Sum_Array(int a[], int n, int k){
    int least_diff = INT16_MAX;
    int ans[2];

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(a[i] + a[j] == k){
                if(abs(a[i] - a[j]) < least_diff){
                    least_diff = abs(a[i] - a[j]);
                    // cout<<a[i]<<" "<<a[j]<<endl;
                    ans[0] = a[i];
                    ans[1] = a[j];
                }
            }
        }
    }

    cout<<ans[0]<<" "<<ans[1];
}

int main(){
    int n, k;
    cin>>n;
    cin>>k;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    Least_Difference_Sum_Array(a, n, k);
}