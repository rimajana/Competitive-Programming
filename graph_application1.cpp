#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
vector<int> visited;
vector<vector<int>> graph;
bool found_cycle = 0;
vector<int> par;
void dfs(int node,int parent){
    visited[node] = 1;
    par[node] = parent;

    for(auto v:graph[node]){
        if(!visited[v]){   //forward edge
            dfs(v,parent);
        }
        else if(visited[v]==1){//backedge
            found_cycle = 1;
            // vector<int> temp;
            // int x=node;
            // while(x!=v){
            //     temp.push_back(x);
            //     x = par[x];
            // }
            // temp.push_back(v);
        }
        else{//cross edge
        

        }
    }
    visited[node] = 2;   // those who are done they are marked 2 so 
}




void solve()
{
    int n;
    cin>>n;
    visited.resize(n+1,0);
    graph.resize(n + 1);
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