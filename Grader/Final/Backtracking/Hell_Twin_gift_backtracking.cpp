#include<iostream>
#include<cmath>
using namespace std;

int subset(int a[], int b[], int g[], int k, int n, int &diff_min, int &count){
    int bigbros = 0;
    int bros = 0;
    int diff = 0;
    
    for(int i = 0; i<k; i++){

        if(g[i] == 1){ // 1 ของพี่ 0 ของน้อง อิงตาม array a
            bigbros += a[i];
            bros += b[i];
        }
        else{
            bigbros += b[i];
            bros += a[i];
        }

        diff = abs(bigbros - bros);
        if(diff > diff_min){
            return diff_min;
        }
    }

    if(k == n){
        count++;
        diff_min = diff; // เก็บผลต่างที่น้อยที่สุด
        return diff;
    }
    else{
        g[k] = 1;
        int sum1 = subset(a, b, g, k+1, n, diff_min, count); 
        g[k] = 0;
        int sum2 = subset(a, b, g, k+1, n, diff_min, count);

        int min = (sum1 < sum2) ? sum1 : sum2;

        return min;
    }
}

int main(){
    int n, diff_min = 10000, count = 0;
    cin>>n;
    int a[n], b[n], g[n];
    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    cout<<subset(a, b, g, 0, n, diff_min, count);
    // cout<<endl<<count;
}