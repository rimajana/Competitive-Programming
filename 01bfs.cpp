#include <iostream>
#include <bits/stdc++.h>
// #define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

const int MOD = 1e9 + 7;

vector<vector<pair<int,int>>> g;        //vec
vector<int> dist;




void bfs(int sc){
    deque<int> dq;
    dist[sc]=0;
    dq.push_back(sc);
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();

        for(auto v:g[x]){
            int neigh=v.first;
            int weight = v.second;

            if(dist[neigh]>dist[x]+weight){
                dist[neigh] = dist[x] + weight; 
        
            } //updating the value
            if(weight == 0)
                dq.push_front(neigh);
            else
            {
                dq.push_back(neigh);
            }
                
            
        }

    }
}










void solve()
{
     int n,m,a,b,c;
     cin >> n >> m;
     dist.resize(n + 1,1e9);
     g.resize(n + 1);
     



     for (int i = 1; i <= m;i++){
         cin >> a >> b>>c;
         g[a].push_back({b,c});
         g[b].push_back({a,c});
     }
     int sc;   //source
     cin >> sc;
     bfs(sc);
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