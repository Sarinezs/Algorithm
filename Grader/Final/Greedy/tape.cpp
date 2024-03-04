#include<iostream>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);      
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n], sum=0;
    double mean = 0.0;

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    bubble_sort(a, n);

    for(int i = 0; i<n; i++){
        sum += a[i];
        mean += (double)sum/n;
    }
    cout<<fixed;
    cout.precision(2);
    cout<<mean;


}