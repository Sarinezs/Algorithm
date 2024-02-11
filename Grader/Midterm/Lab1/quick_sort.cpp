#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r){
    int pivot, i, j;
    pivot = a[l];
    i = l;
    j = r+1;
    while(1){
        do{
            ++i;
        }while(a[i] <= pivot);

        do{
            --j;
        }while(a[j] > pivot);

        if(i >= j){
            break;
        }
        swap(&a[i],&a[j]);
    }
    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int s[], int l, int r){
    int p;
    if((r - l) > 0){
        p = partition(s, l, r);
        quicksort(s, l, p-1);
        quicksort(s, p+1, r);
    }
}

int main(){
    int a[8] = {16,25,2,54,36,9,12,66};
    quicksort(a, 0, 7);
    for(int i = 0; i<8; i++){
        cout<<a[i]<<" ";
    }
}