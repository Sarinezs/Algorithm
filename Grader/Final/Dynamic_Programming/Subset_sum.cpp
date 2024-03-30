#include<iostream>
using namespace std;
int memo[1000][1000] = {0};


int topdown(int a[], int n, int k){
    if(k == 0){
        return 1;
    }
    if(k < 0 || n == 0){
        return 0;
    }
    if(memo[n][k] != 0){
        return memo[n][k];
    }
    else{
        memo[n][k] = topdown(a,n-1, k-a[n-1]) + topdown(a,n-1, k);
        return memo[n][k];
    }

}

int main(){
    int n = 5, k = 4;
    int a[] = {1,1,2,1,3};
    cout<<topdown(a, n, k);

}