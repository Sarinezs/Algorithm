#include <iostream>
#include<cmath>
using namespace std;

void* counting_sort(int a[], int size){
    int max = a[0];
    for(int i = 1; i<size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    int count_array[max+1], result[size];

    for(int i = 0; i<max + 1; i++){
        count_array[i] = 0;
    }

    for(int i = 0; i<size; i++){
        count_array[a[i]]++;
    }

    for(int i = 1; i<=max; i++){
        count_array[i] += count_array[i-1];
    }

    for(int i = size - 1; i>=0; i--){
        result[count_array[a[i]]-1] = a[i];
        count_array[a[i]]--;
    }

    for(int i = 0; i<size; i++){
        a[i] = result[i];
    }
}

int main() {
    int n;
    cin>>n;
    int a[n], size_a = sizeof(a) / sizeof(a[0]);
    int size = 0;
    int p[n], b[n]; // b เก็บตัวที่ถูกย่อ;

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    // for(int i = 0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }

    counting_sort(a, size_a);

    // for(int i = 0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }

    // cout<<endl;
    for(int i = 0; i<n; i++){
        int mul = 1;
        p[i] = 0;
        b[i] = 0;

        do{
            p[i]++;
            mul *= 10;
        }while((a[i] % mul) != a[i]);
        size += p[i];
    }

    int split_array[size];
    int index = 0;

    for(int i = 0; i<n; i++){
        while(p[i] > 0){
            int v = (a[i] % static_cast<int>(pow(10,p[i]))) / pow(10,--p[i]);
            split_array[index++] = v;
        }
    }

    for(int i = 0; i<size; i++){
        cout<<split_array[i];
    }
    cout<<endl;

///////////////////////////////////////////ข้างบน หาจำนวนหลัก//////////////////////////////////////////////


    
    int number_reduce = 1, max_number_reduce = -1; // เก็บจำนวนตัวที่ถูกย่อ
    int reduce_index = 0, b_index = 0;


    for(int i = 0; i<size-1; i++){
        if(split_array[i] == split_array[i+1]){
            number_reduce++;
            // cout<<number_reduce<<"--"<<endl;
        }
        else{
            if(number_reduce > max_number_reduce){ ///// เหลือแก้ตรงนี้
                b[b_index] = split_array[i];
                // cout<<b[b_index]<<"--";
                max_number_reduce = number_reduce;
                number_reduce = 1;
            }
            else if(number_reduce == max_number_reduce){
                b_index++;
                b[b_index] = split_array[i];
                // cout<<number_reduce<<"--";
                number_reduce = 1;
            }
        }
    }
    if(number_reduce > max_number_reduce){////////
        b[b_index] = split_array[size-1];
        max_number_reduce = number_reduce;
        number_reduce = 1;                          // ของรอบสุดท้าย
    }
    else if(number_reduce == max_number_reduce){/////////
        b_index++;
        b[b_index] = split_array[size-1];
        number_reduce = 1;
    }                               

    // cout<<max_number_reduce<<"--";

    for(int i = 0; i<size-1; i++){
        if(split_array[i] != split_array[i+1]){
            split_array[reduce_index++] = split_array[i];
        }
    }
    split_array[reduce_index++] = split_array[size-1]; // เก็บตัวท้าย
   

    for(int i = 0; i<b_index+1; i++){
        if(b[i] != 0){
            cout<<b[i]<< " ";
        }
    }

    cout<<endl;

    for(int i = 0; i<reduce_index; i++){
        cout<<split_array[i];
    }

}
