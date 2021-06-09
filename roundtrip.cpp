#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout << '\n'

vector<vector<int>> g;
vector<int> visited;
vector<int> parent;
int countt = 0;



void dfs(int index,int par)
{
    if(countt==1)
        return;
    visited[index] = 1;
    parent[index] = par;
    for (auto x : g[index])
    {
        if (!visited[x])
        {
            dfs(x,index);
        }
        else
        {
            if (parent[index] != x)
            {
                countt = 1;
            }
        }
        // cout << countt  <<" in "<< "\n";
    }
    
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    visited.resize(n + 1, 0);
    parent.resize(n + 1, -1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fo(i, 1, n + 1)
    { //upto number of nodes
        if (!visited[i])
        {
            dfs(i,0);
        }
    }

    if (countt == 0)
        cout << "NO"
             << "\n";
    else
        cout << "YES"
             << "\n";
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