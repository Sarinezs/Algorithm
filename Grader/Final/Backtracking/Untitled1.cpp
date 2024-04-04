#include <iostream>
#include <vector>
using namespace std;
void PrintSubsetSum(int i, int n, int set[], int targetSum,
                    vector<int>& subset)
{

    if (targetSum == 0) {


        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    if (i == n) {

        return;
    }


    PrintSubsetSum(i + 1, n, set, targetSum, subset);


    if (set[i] <= targetSum) {

        subset.push_back(set[i]);

        PrintSubsetSum(i + 1, n, set, targetSum - set[i],
                       subset);


        subset.pop_back();
    }
}


int main()
{
    int n, k;
    cin >> n >> k;
    int set[n]; 
    for (int i = 0; i < n; i++) 
    {
        cin >> set[i];
    }
    vector<int> subset;
    PrintSubsetSum(0, n, set, k, subset);

    return 0;
}

