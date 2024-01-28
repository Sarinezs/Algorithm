#include<iostream>
using namespace std;

int main(){
    int n,x,ans[2],check = 0;
    cin>>n;
    cin>>x;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }    

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if((a[i] + a[j] == x)){
                check = 1;
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }

    if(check == 1){
        cout<<ans[0]<<" "<<ans[1];
    }
    else{
        cout<<-1;
    }

}