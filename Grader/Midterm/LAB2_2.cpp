#include<iostream>
using namespace std;

void* sort(int a[], int n){
    int max = a[0];
    for(int i = 1; i<n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    int count[max + 1], sorted[n];
    for(int i = 0; i<max+1; i++){
        count[i] = 0;
    }

    for(int i = 0; i<n; i++){
        count[a[i]]++;
    }

    for(int i = 1; i<=max; i++){
        count[i] += count[i-1];
    }

    for(int i = n-1; i >= 0; i--){
        sorted[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    for(int i = 0; i<n; i++){
        a[i] = sorted[i];
    }
    
    
}

int main(){
    int n = 0;
    cin>>n;
    if(n>=1 && n<=10000){
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        sort(a,n);

        int count = 1;
    
        for(int i = 0; i<n-1; i++){
            if(a[i] != a[i+1]){
                count++;
            }
        }
    
        cout<<count;
    }
    
}