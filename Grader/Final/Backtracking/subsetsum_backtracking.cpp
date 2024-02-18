#include<iostream>
using namespace std;

void Subset(int a[], int g[], int k, int n, int subset[], int index, int target){
    if(k == n){
        index = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            target -= a[i]*g[i];
            subset[index] = a[i]*g[i];
            index++;
            if(target == 0){

            }
        }
        cout<<endl;
    }
    else{
        g[k] = 1;
        Subset(a, g, k+1, n, subset, index, target);
        g[k] = 0;
        Subset(a, g, k+1, n, subset, index, target);
    }
}

int main(){
    int n = 3, target = 3;
    int a[n] = {1,2,3};
    int g[n], subset[n], index = 0;
    Subset(a, g, 0, n, subset, index, target);
}