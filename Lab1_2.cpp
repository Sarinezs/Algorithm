#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n > 1 && n < 1000000){
        int a[n], F_min = 1000000, F_max = -999999;
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        for(int i = 0; i<n; i++){
            int F_count = 0;
            for(int j = 0; j<n; j++){
                if(a[i] == a[j]){
                    F_count++;
                }
            }
            if(F_count > F_max){
                F_max = F_count;
            }
            if(F_count < F_min){
                F_min = F_count;
            }
        }

        cout<<(F_max - F_min);
    }
}