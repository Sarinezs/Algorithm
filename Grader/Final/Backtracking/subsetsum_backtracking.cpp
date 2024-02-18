#include<iostream>
using namespace std;

void Subset(int a[], int g[], int k, int n, int target, int &count){

    if(target < 0){
        return;
    }

    if( k == n ){ 
        if(target == 0){// subset == target
            count++;
            for(int i = 0; i<n; i++){
                cout<<a[i]*g[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    else{
        g[k] = 1;
        Subset(a, g, k+1, n, target-(a[k]*g[k]), count);
        g[k] = 0;
        Subset(a, g, k+1, n, target-(a[k]*g[k]), count);
    }
}

int main(){
    int n = 7, target = 8, count = 0;
    int a[n] = {1,2,3,4,5,6,7};
    int g[n], index = 0;
    Subset(a, g, 0, n, target, count);
    cout<<count;
}