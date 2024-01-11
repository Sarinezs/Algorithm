#include<iostream>
using namespace std;

bool isSorted(int a[], int size){

    // Base case
    if(size == 1){
        return true;
    }

    // check คู่หลัง ไล่มาข้างหน้า
    if(a[size-2] > a[size-1]){
        return false;
    }

    return isSorted(a, size-1);
}

int main(){
    int size;
    cin>>size;
    if(size > 1 && size < 1000000){
        int a[size];
    
        for(int i = 0; i<size; i++){
            cin>>a[i];
        }
    
        if(isSorted(a, size)){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
    
}
