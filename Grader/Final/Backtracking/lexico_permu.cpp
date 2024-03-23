#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void permutation(string str, int i, int n)
{
    if (i == n-1) {
        cout << str << endl;
        return;
    }

    for (int j = i; j < n; j++)
    {
        sort(str.begin()+j, str.end());
        swap(str[i], str[j]);
        permutation(str, i+1, n);
        swap(str[i], str[j]);
    }
    

}

int main()
{
    string str = "1234";
    sort(str.begin(), str.end());

    permutation(str, 0, str.length());

}