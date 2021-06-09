#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int n;
// {2 3 5 6 8 10}    w=10   o/p=3      2,3,5  2,8  10
//here we need to find out no of subsets equal to the given weight

int arr[10010];
int dp[10010][10010];
int countt = 0;

int recur(int index, int w)
{
    cout << index << " " << w << "\n";
    if (w == 0)
    {
        return 1;
    }
    if (index >= n)
    {
        return 0;
    }

    if (dp[index][w] != -1)
    {
        // cout << dp[index][w] << "\n";
        return dp[index][w];
    }

    if (arr[index] > w)
    {
        return dp[index][w] = recur(index + 1, w);
    }
    else
    {
        dp[index][w] = recur(index + 1, w - arr[index]) + recur(index + 1, w);
        cout << dp[index][w] << "yo"
             << "\n";
        return dp[index][w];
    }
}

void solve()
{
    int W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(0, W) << "\n";
    //  if (ans > 0)
    //      cout << "YES"
    //           << " Number of subsets present are " << ans << "\n";
    //  else
    //  {
    //      cout << "NO"
    //           << "\n";
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}