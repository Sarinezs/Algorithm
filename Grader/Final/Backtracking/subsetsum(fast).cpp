#include<iostream>
#include<algorithm>
using namespace std;

void SubsetUtil(int a[], int g[], int k, int n, int target, int& count){
    if(target < 0 || k == n){
        if(target == 0){
            for(int i = 0; i < n; i++){
                if(a[i]*g[i] != 0){
                    cout << a[i]*g[i] << " ";
                }
            }
            cout << endl;
            count++;
        }
        return;
    }
    
    g[k] = 1;
    SubsetUtil(a, g, k+1, n, target-(a[k]*g[k]), count);
    g[k] = 0;
    SubsetUtil(a, g, k+1, n, target-(a[k]*g[k]), count);
}

void Subset(int a[], int n, int target){
    int count = 0;
    int g[n];
    SubsetUtil(a, g, 0, n, target, count);
    cout << "Total subsets with sum " << target << " are: " << count << endl;
}

int main(){
    int n, target;
    cin >> n >> target;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n); // Sort the array
    Subset(a, n, target);
}
