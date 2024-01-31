#include<iostream>
using namespace std;

void counting_sort(int a[], int size){
    int max = a[0];
    for(int i = 1; i<size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    
    int count[max + 1], sorted[size];

    for(int i = 0; i<max + 1; i++){
        count[i] = 0;
    }

    for(int i = 0; i<size; i++){
        count[a[i]]++;
    }
    
    for(int i = 1; i<=max; i++){
        count[i] += count[i-1];
    }

    for(int i = size-1; i>=0; i--){ 
        sorted[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    for(int i = 0; i<size; i++){
        a[i] = sorted[i];
    }

    // return a;
}

int main(){
    int a[10] = {2,3,5,6,10,9,4,106,102,101};
    int size = sizeof(a) / sizeof(a[0]);
    counting_sort(a,size);

    int concount=0, max_concount=0;

    for(int i = 0; i<10; i++){
        cout<<a[i]<<" ";
    }

}