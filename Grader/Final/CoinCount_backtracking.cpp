#include<iostream>
#include<cmath>
using namespace std;

int subset(int a[], int g[], int k, int n){
    if(k == n){
        int sum = 0;
        for(int i = 0; i<n-1; i++){
            if(g[i] == 1 && g[i+1] == 1){
                return 0;
            }
        }
        for(int i = 0; i<n; i++){
            sum += a[i]*g[i];
        }

        return sum;
    }
    else{
        g[k] = 1;
        int sum1 =  subset(a, g, k+1, n);
        g[k] = 0;
        int sum2 = subset(a, g, k+1, n);

        int max = (sum1 > sum2) ? sum1 : sum2;

        return max; 
    }
}

int main(){;
    int n;
    cin>>n;
    int a[n], g[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<subset(a, g, 0, n);

}