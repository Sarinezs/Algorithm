#include<iostream>
#include<cmath>
using namespace std;
// array a == weight, b == value 

void bubble_sort(int a[], int b[], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n - i - 1; j++){
            if(b[j] < b[j+1]){
                swap(a[j],a[j+1]);
                swap(b[j],b[j+1]);
            }
        }
    }
}
// greedy value น้อย ไป มาก
// 18 15 5 10
// 25 24 8 5

// 10 5 15 18
// 5 8 24 25

float subset(int a[], int b[], int g[], int w, int k, int n, float finalvalue){
    if(k == n){
        // finalvalue = 0.0;
        // for(int i = n-1; i>=0; i--){
        //     cout<<a[i]*g[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = n-1; i>=0; i--){
        //     cout<<b[i]*g[i]<<" ";
        // }
        // cout<<endl;
        for(int i = n-1; i>=0; i--){
            // cout<<g[i]<<" ";
            if(a[i] <= w && g[i] == 1){
                w -= a[i]*g[i];
                finalvalue += b[i]*g[i];
            }
            else if(a[i] > w && g[i] == 1){
                double temp = ((double)w / (double)a[i]*g[i]);
                cout<<" | "<<round(temp * 100.0) / 100.0;
                finalvalue += b[i]*g[i]*temp;
                break;
            }
        }
        // cout<<round(finalvalue *100.0)/ 100.0<<endl;
        // cout<<endl;
        // for(int i = 0; i<n; i++){
        //     cout<<g[i]*b[i]<<" ";
        // }
        // cout<<endl<<endl;
        return finalvalue;
    }
    else{
        g[k] = 0;
        float n1 = subset(a, b, g, w, k+1 ,n, finalvalue);
        g[k] = 1;
        float n2 = subset(a, b, g, w, k+1, n, finalvalue);

        return (n1 > n2) ? n1 : n2;

    }
}

int main(){
    int n = 3, w = 5;
    float finalvalue = 0.0;
    // cin>>n>>w;

    int a[n] = {1,2,3};
    int b[n] = {1,2,2}, g[n];

    // for(int i = 0 ;i<n; i++){
    //     cin>>a[i];
    // }

    // for(int i = 0; i<n; i++){
    //     cin>>b[i];
    // }

    bubble_sort(a, b, n);
    subset(a, b, g, w, 0, n, finalvalue);
    // for(int i = 0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<<b[i]<<" ";
    // }
}