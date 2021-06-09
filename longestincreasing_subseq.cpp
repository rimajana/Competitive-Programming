#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

//here our goal to is to find the longest length of increasing subsequence  

//1325359789

int arr[10010];
int n;
int dp[10010];   //max increasing subsequence at the particular index


int recur(int index){
    // while (arr[index] <= arr[prev] and index < n)
    // {
    //     index++;
    // }
    if(index==n)
        return 0;
    if(dp[index]!=-1)
        return dp[index];

    // int ans = max(recur(index + 1, index) + 1, recur(index + 1, prev));
    int ans=max(1+recur(index+1),

}

void solve()
{
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(0,0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}