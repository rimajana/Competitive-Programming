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
vector<int> component;

void dfs(int index, int compo)
{
    visited[index] = 1;
    component[index] = compo;
    for (auto i : g[index])
    {
        if (!visited[i])
            dfs(i, compo);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    component.resize(n + 1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int no_comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            no_comp++;
            dfs(i, no_comp);
        }
    }
    cout << no_comp - 1 << "\n";

    //minimum no of roads
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