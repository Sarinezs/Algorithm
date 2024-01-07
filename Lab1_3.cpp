#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n > 1 && n < 1000000){
        int a[n],b[n],timein = 0,timeout = 0,count = 0;
        int size_a = sizeof(a)/sizeof(a[0]);
        int size_b = sizeof(b)/sizeof(b[0]);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        for(int i = 0; i<n; i++){
            cin>>b[i];
        }        

        timein = a[0];
        timeout = b[0];

        for(int i = 0; i<size_a; i++){
            if((timein <= a[i] && a[i] <= timeout) || (timeout >= b[i] && b[i] )){
                    if(timein <= a[i] && a[i] <= timeout){
                        timein = a[i];
                    }
                    if(timeout >= b[i] && b[i] > timein){
                        timeout = b[i];
                    }
                    count++;
            }
        }
        cout<<timein<<" "<<count<<endl;
        // for(int i = 0; i<size_a; i++){
        //     int c = 1;
        //     timein = a[i];
        //     timeout = b[i];
        //     for(int j = i+1; j<size_b; j++){
                // if(timein <= a[j] || timeout >= b[j]){
                //     if(timein <= a[j]){
                //         timein = a[j];
                //     }
                //     if(timeout >= b[j]){
                //         timeout = b[j];
                //     }
                //     c++;
                //     cout<<timein<<timeout<<count<<endl;
        //         }
        //     }
        //     count = c;
        // }


    }
}