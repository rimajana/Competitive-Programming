#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout << '\n'

const int ub = 1005;
int n, m;
int visited[ub][ub];
int matrix[ub][ub];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//no of components application
int check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return 1;
    return 0;
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny) and (matrix[nx][ny] == 1) and (visited[nx][ny] == 0))
        {
            
            dfs(nx, ny);
        }
    }
}

void solve()
{
    
    cin >> n >> m;
    
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j <m; j++)
        {
            
            if (s[j] == '#'){
                matrix[i][j] = 0;
                
            }
            else
                matrix[i][j] = 1;
        }
    }
    

        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
        }
    }
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 and matrix[i][j] == 1)
            {
                
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << "\n";
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