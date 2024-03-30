#include<iostream>
using namespace std;
int memo[1000][1000], a[1000][2], n;

int topdown(int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }
    else if(memo[i][j] != 0){
        return memo[i][j];
    }
    else{
        if(j < a[i][1]){
            memo[i][j] = topdown(i-1,j);
            return memo[i][j];
        }
        else{
            memo[i][j] = max(a[i][0] + topdown(i-1,j-a[i][1]), topdown(i-1, j));
            return memo[i][j];
        }
    }

}

int main(){
    for(int i = 0; i<8; i++){
        cin>>a[i][0];
        cin>>a[i][1];
    }
    cout<<topdown(7, 15);
}