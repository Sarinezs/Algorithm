#include<iostream>
using namespace std;

// input
// 0 0
// 3 2
// 4 3
// 5 4
// 25 15
// 20 10
// 12 8
// 11 7


int memo[1000][1000] = {0}, t[1000][2] = {0};

int bottomup(int a, int b){
    memo[0][0] = 0;
    for(int i = 0; i<a; i++){
        memo[i][0] = 0;
    }
    for(int i = 0; i<b; i++){
        memo[0][i] = 0;
    }
    for(int i = 1; i<=a; i++){
        for(int j = 1; j<=b; j++){
            if(j < t[i][1] ){
                memo[i][j] = memo[i-1][j];
            }
            else{
                memo[i][j] = max(t[i][0] + memo[i-1][j-t[i][1]], memo[i-1][j]);
            }
        }
    }
    return memo[a][b];
}

int topdown(int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }
    else if(memo[i][j] != 0){
        return memo[i][j];
    }
    else{
        if(j < t[i][1]){
            memo[i][j] = topdown(i-1,j);
            return memo[i][j];
        }
        else{
            memo[i][j] = max(t[i][0] + topdown(i-1,j-t[i][1]), topdown(i-1, j));
            return memo[i][j];
        }
    }

}

int main(){
    int v,w;
    for(int i = 0; i<8; i++){
        cin>>v>>w;
        t[i][0] = v;
        t[i][1] = w;
    }

    // cout<<bottomup(7,15)<<endl;
    cout<<topdown(7,15)<<endl;

    for(int i = 0; i<8; i++){
        for(int j = 0; j<16; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
}


