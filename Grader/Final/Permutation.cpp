#include<iostream>
using namespace std;

void bubblesort(char a[], int start, int end){
    for(int i =  start; i<end; i++){
        for(int j = start; j<end - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void perm(char a[], int n, int k){
    if(k == n-1){
        for(int i = 0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i = k; i<n; i++){
            swap(a[k], a[i]);
            bubblesort(a, k+1, n);
            perm(a, n, k+1);
            swap(a[k], a[i]);
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    char a[n+1];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    a[n] = '\0';
    cout<<endl;
    bubblesort(a, 1, n);
    // perm(a, n, 0);
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
 
}