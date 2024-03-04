#include<iostream>
using namespace std;
int n, p, q, s, d,a[100][100], visited[100];
// cin>>n;

void dfs(int n, int i){
    int j, s;

    cout<<i;
    if(i == d){
        cout<<endl;
        return;
    }

    visited[i] = 1;
    for(j = i; j<n; j++){
        if(!visited[j] && a[i][j] == 1){
            dfs(n, j);
        }
    }
    // for(j = i; j>=0; j--){
    //     if(!visited[j] && a[i][j] == 1){
    //         dfs(n, j);
    //     }
    // }
    visited[i] = 0;
}

int main(){
    
    cin>>n;
    

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         a[i][j] = 0;
    //     }
    // }

     for(int i = 0; i<n; i++){
        cin>>p;
        for(int j = 0; j<n; j++){
            cin>>q;
            if(q == -1){
                break;
            }
            a[p][q] = 1;
        }
    }

    cin>>s>>d;
    dfs(n, s);


    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}