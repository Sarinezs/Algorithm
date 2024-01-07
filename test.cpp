#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],max = -999999, min = 1000000;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(a[i] == a[j]){
                count++;
            }

            if(count >= max){
                max = count;
            }
            else{
                min = count;
            }
        }
    }

    cout<<(max - min);
}