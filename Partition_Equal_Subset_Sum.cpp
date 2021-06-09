#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int dp[110][100100];
int n;

int recur(int arr[], int index, int w)
{
    if (w == 0){
        return 1;
        
    }

    if (index >= n)
        return 0;

    if (dp[index][w] != -1)
        return dp[index][w];

    int ans = recur(arr, index + 1, w - arr[index]) || recur(arr, index + 1, w);
    return dp[index][w] = ans;
}

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        
        // cout<<sum<<"df"<<"\n";
        if (sum % 2 != 0)
            return 0;
        else
        {
            n = N;
            for (int i = 0; i < 110; i++)
            {
                for (int j = 0; j < 100100; j++)
                {
                    dp[i][j] = -1;
                }
            }

            return recur(arr, 0, sum / 2);
        }
    }
};

// int dp[1000][1100];    //weights constraint is so more cannot store in array
// int n;
// int recur(int index, int w1, int w2,int arr[])
// {
//     cout<<index <<" "<< w1 << "  " << w2 << "\n";
//     if (w1 == w2 and index == n )
//         return 1;

//     if (index > n - 1)
//     {
//         return 0;
//     }

//     if (dp[w1][w2] != -1)
//         return dp[w1][w2];

//     int ans = recur(index + 1, w1 + arr[index], w2, arr) || recur(index + 1, w1, w2 + arr[index], arr);
//     cout <<index << "and" << ans << "\n";
//     return dp[w1][w2] = ans;
// }

// class Solution
// {
// public:
//     int equalPartition(int N, int arr[])
//     {
//         n = N;
//         memset(dp, -1, sizeof(dp));
        
//         return recur(1, arr[0], 0,arr);
//     }
// };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t;i++)
        cin >> arr[i];
    
    Solution obj;
    cout<<obj.equalPartition(t, arr) <<"\n";
}