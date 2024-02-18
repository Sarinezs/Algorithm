#include<iostream>
#include<cmath>
using namespace std;

int subset(int a[], int b[], int g[], int k, int n){
    if(k == n){
        int bigbros = 0;
        int bros = 0;
        for(int i = 0; i<n; i++){
            if(g[i] == 1){ // 1 ของพี่ 0 ของน้อง
                bigbros += a[i];
                bros += b[i];
            }
            else{
                bigbros += b[i];
                bros += a[i];
            }
        }

        return abs(bigbros - bros);
        
    }
    else{
        g[k] = 1;
        int sum1 = subset(a, b, g, k+1, n); 
        g[k] = 0;
        int sum2 = subset(a, b, g, k+1, n);

        int min = (sum1 < sum2) ? sum1 : sum2;

        return min;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n], b[n], g[n];
    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    cout<<subset(a, b, g, 0, n);
}