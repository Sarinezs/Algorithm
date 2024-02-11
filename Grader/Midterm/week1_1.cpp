#include<iostream>
using namespace std;

int main(){
    int n,x,check = 0;
    cin>>n;
    cin>>x;
    int a[n],ans[n],ans_index = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }    

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if((a[i] + a[j] == x)){
                check = 1; // เพิ่มเข้าอาร์เรย์คำตอบทีละ2ตัว
                // ans[ans_index++] = i;
                // ans[ans_index++] = j;
                cout<<i<<" "<<j<<" ";
                // cout<<a[i]<<" "<<a[j]<<endl;
                break;
            }
        }
    }

    if(check != 1){
        cout<<-1<<" ";
    }

}