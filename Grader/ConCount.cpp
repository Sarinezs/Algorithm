#include<iostream>
using namespace std;

int* counting_sort(int a[], int size){
    int max = a[0];
    for(int i = 1; i<size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    
    int count[max + 1], sorted[size];

    for(int i = 0; i<max + 1; i++){
        count[i] = 0;
    }

    for(int i = 0; i<size; i++){
        count[a[i]]++;
    }
    
    for(int i = 1; i<=max; i++){
        count[i] += count[i-1];
    }

    for(int i = size-1; i>=0; i--){ 
        sorted[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    for(int i = 0; i<size; i++){
        a[i] = sorted[i];
    }

    return a;
}

int main(){
    int n;
    cin>>n;
    if(n>1 && n < 100000){
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        int size = sizeof(a) / sizeof(a[0]);
        int* sorted = counting_sort(a,size);
        int concount=1, max_concount=1;

        // for(int i = 0; i<size; i++){
        //     cout<<a[i]<<" ";
        // }

        for(int i = 0; i<size-1; i++){
            if((a[i+1] - a[i]) != 1){
                concount++;
            }    
        }

        cout<<concount;

    }
    
}