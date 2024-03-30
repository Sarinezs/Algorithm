#include<iostream>
using namespace std;
int memo[1000][1000] = {0}, a[1000][1000]={0}, m,n;

int topdown(int m, int n){
    if(m < 0 || n < 0){
        return -1;
    }
    else if(memo[m][n] != 0){
        return memo[m][n];
    }
    else{
        int a1 = topdown(m-1,n);
        int a2 = topdown
        return memo[m][n] = a[m][n] + min(topdown(m-1,n), topdown(m, n-1)) ;
    }
}

int main(){
    n = 3; m = 3;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cout<<topdown(0, 2);
}