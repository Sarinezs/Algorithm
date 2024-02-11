#include<iostream>
using namespace std;

void lexiperm(char x[], int n, int k){
    if(k == n){
        for(int i = 0; i<n; i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i = k; i<n; i++){
            // x[k+1] = i;
            swap(x[k], x[i]);
            int j = 1;
            while(j <= k && x[j] != x[k+1]){
                ++j;
            }
            if(j > k){
                lexiperm(x, n, k+1);
                swap(x[k], x[i]);
            }
        }
    }
}

int main(){
    char a[4] = {'a','b','c','d'};
    int n = 4;
    lexiperm(a, n, 0);
}