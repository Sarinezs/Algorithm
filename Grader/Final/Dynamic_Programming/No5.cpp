#include<bits/stdc++.h>
using namespace std;
int memo[100] = {0};

int topdown(int n){
    if(n == 1  || n == 2){
        return 1;
    }
    else if(memo[n] != 0){
        return memo[n];
    }
    else{
        memo[n] = 3*topdown(n-1) + topdown(n-2);
        return memo[n];
    }
}

int bottomup(int n){
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2; i<n; i++){
        memo[i] = 3*memo[i-1] + memo[i-2];
    }
    return memo[n-1];
}

int main(){
    int n;
    cin>>n;
    // cout<<topdown(n);
    cout<<bottomup(n);
}