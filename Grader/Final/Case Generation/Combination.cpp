#include<iostream>
using namespace std;
// no 3

void combination(int a[], int n, int k, int r, int b[], int b_size, int &count){
    if(r == 0){
        count++;
        for(int i = 0; i<b_size; i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i = k; i<n; i++){
            b[b_size] = a[i];
            combination(a, n, i+1, r-1, b, b_size+1, count);
        }
    }
}

int main(){
    int n, r, count = 0;
    cin>>n>>r;
    int a[n], b[100];
    for(int i = 0; i<n; i++){
        a[i] = i+1;
    }
    cout<<"--------- output ----------"<<endl;
    combination(a, n, 0, r, b, 0, count);
    cout<<count;
}