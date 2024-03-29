#include<iostream>
using namespace std;
int count = 0;
int subset(int a[],int w[], int g[], int k, int n, int c){
    if(c < 0){
        return 0;
    }
    if(k == n){
        int sum = 0;
        count++;
        for(int i = 0; i<n; i++){
            sum += a[i]*g[i];
        }
        // cout<<sum;
        // cout<<endl;
        return sum;
    }
    else{
        g[k] = 1;
        int sum1 = subset(a, w, g, k+1, n, c-w[k]*g[k]);
        g[k] = 0;
        int sum2 = subset(a, w, g, k+1, n, c-w[k]*g[k]);

        return max(sum1, sum2);
    }
}

int main(){
    int a[] = {12,5,4,2};
    int w[] = {8,7,4,2};
    int g[4];
    cout<<subset(a, w, g, 0, 4, 18);
    // cout<<count;
}