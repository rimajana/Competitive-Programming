#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
#define nl cout << '\n'

vector<vector<int>> g;
vector<int> visited;
vector<int> component;
int countt = 0;
void dfs(int index, int comp)
{
    visited[index] = 1;
    component[index] = comp;
    for (auto v : g[index])
    {
        // cout << "uyu" << "\n";
        if (!visited[v])
            dfs(v, comp);
        
    }
}

void solve()
{
    int n, m, q;
    cin >> n >> m;
    int a, b;
    g.resize(n + 1);
    visited.resize(n + 1);
    component.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int c, x, y;
    
    int comp = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            
            dfs(i, comp);
            comp++;
                }
        
    }
    
    // for(auto x:component)
    //     cout << x << "ab"
    //          << "\n";
    map<int,int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[component[i]]++;
    }
    int ans=0;
    for(auto p:mp){
        ans += p.second * (n -p.second);
        
    }
    cout << ans / 2 << "\n";
}

signed main()
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