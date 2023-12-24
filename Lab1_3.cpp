#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n > 1 && n < 1000000){
        int a[n],b[n],time,count = 0;
        int size_a = sizeof(a)/sizeof(a[0]);
        int size_b = sizeof(b)/sizeof(b[0]);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        for(int i = 0; i<n; i++){
            cin>>b[i];
        }        

        for(int i = 0; i<size_a; i++){
            int c = 1;
            for(int j = 0; j<size_b; j++){
                if(a[i] == b[j]){
                    c++;
                }
            }
            if(c > count){
                time = a[i];
                count = c;
            }
        }

        cout<<time<<" "<<count;
    }
}