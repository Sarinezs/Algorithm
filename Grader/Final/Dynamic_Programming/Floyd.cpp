#include<iostream>
using namespace std;

// input
// 4
// 0 1 9
// 1 2 1
// 2 0 4
// 0 3 1
// 3 1 2
// 3 2 10
// -1


int main(){
    int n,p,q,d;
    cin>>n;
    int a[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 1000;
            }
        }
    }
   
    while(1){
        cin>>p;
        if(p == -1){
            break;
        }
        cin>>q>>d;
        a[p][q] = d;

    }

    

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
                
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}