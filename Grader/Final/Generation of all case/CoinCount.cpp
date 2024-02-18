#include<iostream>
using namespace std;

int subset(int a[], int x[], int k, int n){
    if(k == n){
        int sum = 0;
        for(int i = 0; i<n-1; i++){
            if(x[i] == x[i+1]){ // ถ้าตำแหน่งติดกัน ให้ == 0
                x[i+1] = 0;
            }
        }

        for(int i = 0; i<n; i++){
            if(x[i] == 1){
                sum += a[i];
            }
        }
        
        return sum;
    }
    else{
        x[k] = 1;
        int sum1 = subset(a, x, k+1, n);
        x[k] = 0;
        int sum2 = subset(a, x, k+1, n);

        int max = (sum1 > sum2) ? sum1 : sum2;

        return max;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

   
    cout<<subset(a, b, 0, n);
    
}