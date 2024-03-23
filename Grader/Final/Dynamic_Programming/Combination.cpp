#include<bits/stdc++.h>
using namespace std;
int memo[100][100] = {0}, a[1000];

int topdown(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }
    if(n == 0){
        return 0;
    }

    if(memo[n][k] != 0){
        return memo[n][k];
    }
    else{
        return memo[n][k] = topdown(n-1, k-1) + topdown(n - 1, k); 
        
    }

}

int main(){
    int n, k;
    cin>>n>>k;

    cout<<topdown(n, k);
}