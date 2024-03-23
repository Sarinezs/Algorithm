#include<iostream>
using namespace std;

void Subset(int a[], int g[], int k, int n, int target){

    if(target < 0){
        return;
    }

    if( k == n ){ 
        if(target == 0){// subset == target
            // count++;
            for(int i = 0; i<n; i++){
                if(a[i]*g[i] != 0){
                    cout<<a[i]*g[i]<<" ";
                }
            }
            cout<<endl;
        }
        return;
    }
    else{
        g[k] = 1;
        Subset(a, g, k+1, n, target-(a[k]*g[k]));
        g[k] = 0;
        Subset(a, g, k+1, n, target-(a[k]*g[k]) );
    }
}

int main(){
    int n, target, count = 0;
    cin>>n>>target;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int g[n], index = 0;
    Subset(a, g, 0, n, target);
    // cout<<count;
}