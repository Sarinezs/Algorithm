#include<iostream>
using namespace std;
void bubblesort(char a[], int start, int end){
    for(int i =  start; i<end; i++){
        for(int j = start; j<end - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void display(char a[], int n){
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void perm(char a[], int n, int k){
    if(k == n-1){
        display(a,n);
    }
    else{
        for(int i = k; i<n; i++){
            swap(a[k], a[i]);
            // bubblesort(a, k+1, n);
            perm(a, n, k+1);
            swap(a[k], a[i]);
            
        }
    }
}

int main(){
    char a[4] = {'C','A','B','\0'};
    int n = 3;
    bubblesort(a, 0, n);
    perm(a, n, 0);
    
}