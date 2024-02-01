#include<iostream>
#include<cmath>
using namespace std;


int power(int a, int n, int &count){
    
    if(a != 0){
        if(n == 0){
            return 1;
        }
        if(n % 2 == 0){
            count++;
            int temp = power(a, n/2, count);
            return temp * temp;
        }
        else{
            // count++;
            int temp = power(a, (n-1)/2, count);
            return a * temp * temp;
        }
    }
    else{
        return 0;
    }
    
    
    

}

int main(){
    int a, n, count = 0;
    cin>>a>>n;
    
    int ans = power(a, n, count);
    if(a == 0){
        cout<<ans<<" "<<0;
    }
    else if(n == 0 || n == 1){
        cout<<ans<<" "<<1;
    }
    else{
        cout<<ans<<" "<<static_cast<int>(ceil(log2(n)));
    }
}