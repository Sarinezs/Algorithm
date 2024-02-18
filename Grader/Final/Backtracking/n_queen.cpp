#include<iostream>
#include<cmath>
using namespace std;

void n_queen(int a[], int n, int k, int &count){
    int flag = 0;
        for(int i = 1; i<k; i++){
            for(int j = 0; j<i; j++){
                if(abs(j-i) == abs(a[j] - a[i]) || a[j] == a[i]){
                    flag = 1;
                }
            }
        }
    if(k == n){
        

        if(flag == 0){
            count++;
            for(int i = 0; i<k; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(int row = 0; row<n; row++){
            a[k] = row;
            n_queen(a, n, k+1, count);
        }
    }
}

int main(){
    int n = 4, count = 0;
    int a[n];
    n_queen(a, n, 0, count);
    cout<<count;
}