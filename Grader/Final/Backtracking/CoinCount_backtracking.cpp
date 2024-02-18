#include<iostream>
#include<cmath>
using namespace std;

int subset(int a[], int g[], int k, int n, int &count){

    for(int i = 0; i<k; i++){ // เช็คว่ามีเลข 1 ติดกันไหม
        if(g[i] == 1 && g[i+1] == 1){
            return 0;
        }
    }

    if(k == n){
        int sum = 0;
        count++;
        for(int i = 0; i<n; i++){
            sum += a[i]*g[i];
        }

        return sum;
    }

    g[k] = 1;
    int sum1 =  subset(a, g, k+1, n, count);
    g[k] = 0;
    int sum2 = subset(a, g, k+1, n, count);

    int max = (sum1 > sum2) ? sum1 : sum2;

    return max; 
    
}

int main(){;
    int n, count = 0;
    cin>>n;
    int a[n], g[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<subset(a, g, 0, n, count);
    cout<<endl<<count;

}