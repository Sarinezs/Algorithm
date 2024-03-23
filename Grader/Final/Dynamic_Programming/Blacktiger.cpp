#include<bits/stdc++.h>
using namespace std;
int d = 1;

int topdown(int m, int n){
    if(m == 1 || n == 1){
        return 0;
    }
    
    else{
        d++;
        return topdown(m-1,n) + topdown(m, n-1);
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    topdown(m, n);
    cout<<d;
}