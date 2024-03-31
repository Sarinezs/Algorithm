#include<iostream>
using namespace std;
long long int memo[1000][2];

int g(int n){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return 2;
    }
    else if(memo[n][1] != 0){
        return memo[n][1];
    }
    else{
        memo[n][1] = g(n-1) + g(n-2);
        return memo[n][1];
    }
}

int t(int n){
    if(n == 0){
        return 1;
    }
    else if(memo[n][0] != 0){
        return memo[n][0];
    }
    else{
        memo[n][0] = t(n-1) + g(n/2) + n;
        return memo[n][0];
    }
}

int main(){
    long long int result = t(172);
    cout << "Result: " << t(172) << endl;
    return 0;
}
