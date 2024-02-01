#include<iostream>
using namespace std;
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
    swap(a[c], a[l]);
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

void quicksort(int a[], int l, int r){
    if(l <= r){
        int p = partition(a, l, r);
        quicksort(a, l, p-1);
        quicksort(a, p+1, r);
    }
}

int main(){
    int a[8] = {16,25,2,54,36,9,12,66};
    quicksort(a, 0, 7);
    for(int i = 0; i<8; i++){
        cout<<a[i]<<" ";
    }
}