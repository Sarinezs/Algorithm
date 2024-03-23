#include<iostream>
using namespace std;
int count = 0;

// void bubblesort(char a[], int start, int end){
//     for(int i =  start; i<end; i++){
//         for(int j = start; j<end - 1; j++){
//             if(a[j] > a[j+1]){
//                 swap(a[j], a[j+1]);
//             }
//         }
//     }
// }

void perm(int a[], int n, int k){
    if(k == n-1){
        count++;
        // for(int i = 0; i<n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
    }
    else{
        // bubblesort(a, k, n);
        for(int i = k; i<n-1; i++){
            // swap(a[k], a[i]);
            perm(a, n, k+1);
            // swap(a[k], a[i]);
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    // char a[n+1];
    int a[n];
    for(int i = 0; i<n; i++){
        // cin>>a[i];
        a[i] = i+1;
    }
    // a[n] = '\0';
    // cout<<endl;
    // bubblesort(a, 1, n);
    perm(a, n, 0);
    cout<<count*2;
    // for(int i = 0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
 
}