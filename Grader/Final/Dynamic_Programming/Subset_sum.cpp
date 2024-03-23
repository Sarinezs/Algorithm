#include <bits/stdc++.h>
using namespace std;
bool memo[1000] = {false};

void bottomup(int nums[], int n, int targetSum)
{
    bool dp[1000][1000] = {false};
    int subset[1000];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= targetSum; j++)
        {
            if (nums[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
        }
    }

    // for(int i = 0; i<=n; i++){
    //     for(int j = 0; j<=targetSum; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int n_subset = 0;
    if (dp[n][targetSum])
    {
        while (n > 0 && targetSum > 0)
        {
            if (dp[n][targetSum] && !dp[n - 1][targetSum])
            {
                subset[n_subset] = nums[n - 1];
                targetSum -= nums[n - 1];
                n_subset++;
            }
            n--;
        }
        // return true;
    }
    cout<<n_subset;
}

bool topdown(int nums[], int n, int targetSum)
{
    if (targetSum == 0)
    {
        return true;
    }
    if (n == 0 || targetSum < 0)
    {
        return false;
    }

    if (nums[n - 1] > targetSum)
    {
        return memo[n] = topdown(nums, n - 1, targetSum);
    }
    else
    {
        return memo[n] = topdown(nums, n - 1, targetSum - nums[n - 1]) || topdown(nums, n - 1, targetSum);
    }
}

int main()
{
    int nums[] = {1,1,2,1,3};
    int targetSum = 100;
    int n = sizeof(nums) / sizeof(nums[0]);

    bottomup(nums, n, targetSum);
    // cout << topdown(nums, n, targetSum);
}