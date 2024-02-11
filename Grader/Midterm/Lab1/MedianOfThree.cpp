#include<iostream>
using namespace std;

int median_of_three(int a[], int l, int r){
    int mid = (l + r)/2;
    // int result = max(min(a[l],a[mid]), min(max(a[l],a[mid]),a[r]));
    // return result;

    // if(a[l] < a[mid]){ //นึกรูปซ้าย น้อยกว่า กลางไหม
    //     if(a[l] > a[r]){ // และ ซ้ายมากกว่าขวาไหม
    //         return a[l];
    //     }
    //     else{
    //         return a[mid];
    //     }
    // }
    // else{
    //     if(a[l] < a[r]){
    //         return a[l];
    //     }
    // }
    // return a[r];

    if((a[l] > a[mid] && a[l] < a[r]) || (a[l] > a[r] && a[l] < a[mid])){ // กรณี B A C || C A B
        return a[l];
    }
    else if((a[mid] > a[l] && a[mid] < a[r]) || (a[mid] > a[r] && a[mid] < a[l])){ // กรณี A B C || C B A
        return a[mid];
    }
    else{
        return a[r];
    }
}