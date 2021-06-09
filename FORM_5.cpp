//GAME DP      //stones total there are n stones and 

#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

int dp[10010];
int moves[10010];
int rec(int n){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    dp[n] = 0;          
    int ans;
    for (int i = 0;i<n;i++){
        if(n>moves[i] && rec(n-moves[i]) == 0){
            ans = 1;
        }
    }
    return dp[n] = ans;
}





void solve()
{
    int a;
    cin >> a;
    for (int i = 0; i < a;i++){
        cin >> moves[i];
    }
    cout << rec(a - 1) << "\n";
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