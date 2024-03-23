#include<iostream>
using namespace std;

double findMean(double a[], int n){
    if(n == 0){
        return 0;
    }
    return (a[n-1] + findMean(a, n-1));
}

int main(){
    int n;
    cin>>n;
    double a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<fixed;
    cout.precision(2);
    cout<<findMean(a, n);
}