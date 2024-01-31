#include<iostream>
using namespace std;

int divide(int a, int n, int loop[]){
    if(n == 1){
        // loop[1]++;
        return a;
    }
    loop[0] = 1, loop[1] = 0;
    int m = n/2, left, right;
    if(n % 2 == 0){ // even
        left = divide(a, m, loop);
        right = divide(a, m, loop);
        loop[1] += 1;
        loop[0] = left * right;
    }
    else{ // odd
        left = divide(a, m, loop);
        right = divide(a, m+1, loop);
        loop[1] += 1;
        loop[0] = left * right;
    }
    

    return left * right;
}

int main(){
    int a, n, loop[2];
    cin>>a>>n;
    divide(a, n, loop);
    cout<<loop[0]<<" "<<loop[1];
}