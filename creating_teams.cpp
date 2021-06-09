#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout<<'\n'


//bipartite application
vector<vector<int>>g;
vector<int>visited;
vector<int>color;

bool cl=true;

void dfs(int index,int c){
    visited[index]=1;
    color[index]=c;
    for(auto x:g[index]){
        if(!visited[x])
        	dfs(x,3-c);
        else{
            if(color[x]!=3-c){
                cl=false;
                return;
            }
            	
        }

    }
}


void solve()
{
    int n,m,a,b;
    cin>>n>>m;
    g.resize(n+1);
    visited.resize(n+1,0);
    color.resize(n + 1, 0);
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        
    }
    for(int i=0;i<n;++i){
        if(!visited[i]){
        	dfs(i,1);  //let classes be 1 and 2
            if(cl==false){
                cout<<"NO"<<"\n";
                break;
            }
        }
    }
    if(cl==true){
        cout<<"YES"<<"\n";
    }
    
    
     
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
/*
	GRAPHS - Creating Teams
*/

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long int;
// using ii = pair<int, int>;

// #define F first
// #define S second
// #define mod 1000000007
// #define endl '\n'

// void file_i_o()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input1.txt", "r", stdin);
//     freopen("output1.txt", "w", stdout);
// #endif
// }

// ll n, m;
// vector<vector<int>> g;
// vector<int> vis;
// vector<int> col;
// bool is_bipartite = 1;

// void dfs(int node, int curr_color)
// {
//     col[node] = curr_color;
//     vis[node] = 1;
//     for (auto v : g[node])
//     {
//         if (!vis[v])
//         {
//             dfs(v, 3 - curr_color);
//         }
//         else
//         {
//             if (col[v] == curr_color)
//                 is_bipartite = 0;
//         }
//     }
// }

// void solve()
// {
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.assign(n + 1, 0);
//     col.resize(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             dfs(i, 1);
//         }
//     }
//     if (is_bipartite == 1)
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }
//     return;
// }

// signed main()
// {
//     clock_t begin = clock();
//     file_i_o();
//     // int t;cin>>t;while(t--)
//     solve();

// #ifndef ONLINE_JUDGE
//     clock_t end = clock();
//     cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
// #endif
//     return 0;
// }