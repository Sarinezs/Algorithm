#include<iostream>
using namespace std;

int subset(int a[], int b[], int g[], int k, int n, int c, int &count){
    if(k == n){
        int weightsum = 0;
        int valuesum = 0;
        for(int i = 0; i<n; i++){
            weightsum += a[i]*g[i];
            if(weightsum <= c){
                valuesum += b[i]*g[i];
            }
            else{
                return 0;
            }
        }
        count++;
        cout<<weightsum<<" "<<valuesum<<endl;
        return valuesum;
    }
    else{
        g[k] = 1;
        int sum1 = subset(a, b, g, k+1, n, c, count);
        g[k] = 0;
        int sum2 = subset(a, b, g, k+1, n, c, count);
        int max= (sum1 > sum2) ? sum1 : sum2;

        return max;

    }
}

int main(){
    int n, c, count = 0;
    cin>>n>>c;
    int a[n], b[n], g[n];
    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    cout<<endl;
    subset(a, b, g, 0, n, c, count);
    cout<<count;
}