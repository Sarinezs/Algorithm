#include<iostream>
using namespace std;

// int partition(int a[], int l, int r){
//     int pivot = a[r];
//     int i = l - 1;

//     for(int j = l; j<r; j++){
//         if(a[j] <= pivot){
//             ++i;
//             swap(a[i], a[j]);
//         }
//     }
//     swap(a[i+1], a[r]);
//     return i+1;
// }

void mdt(int a[], int l, int c, int r){
    if(a[l] > a[c]){
        swap(a[l], a[c]);
    }
    if(a[c] > a[r]){
        swap(a[c], a[r]);
    }
    if(a[l] > a[c]){
        swap(a[l], a[c]);
    }
}

int partition(int a[], int l, int r){
    int pivot, i, j, c;
    c = (l + r)/2;
    mdt(a, l, c, r);
    swap(a[l], a[c]);
    pivot = a[l];
    i = l;
    j = r + 1;
    while(1){
        do{
            i++;
        }while(a[i] <= pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i >= j){
            break;
        }
        swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}

int quickselect(int a[], int l, int r, int k){
    if(l <= r){
        // int loop = 0;
        int index = partition(a, l, r);
        if(k == index){
            // return 0;
            return a[index];
        }

        if(k - 1 < index){
            // loop++;
            // loop += quickselect(a, l, index-1, k);
            return quickselect(a, l, index-1, k);
        }
        else{
            // loop++;
            // loop += quickselect(a, index+1, r, k);
            return quickselect(a, index+1, r, k);
        }
        // return loop;

    }
}

int main(){
    // int size,k;
    // cin>>size;
    // cin>>k;
    // int a[size];
    // for(int i = 0; i<size; i++){
    //     cin>>a[i];
    // }
    // int n = sizeof(a) / sizeof(a[0]);
    // cout<<a[k-1]<<" "<<quickselect(a,0, n-1, k-1);

    int a[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int n = sizeof(a) / sizeof(a[0]);

    cout<<quickselect(a, 0, n-1, 6-1);
}