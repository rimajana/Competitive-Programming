#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

/*Two methods of traversal in graph DFS AND BFS 
DFS IS implemented by recursuion
BFS is sequential process of neighbors so it is implemented by queue

Traverse  throughout the graph and mark visited 

//question
//Find the no of unordered pairs(count ones) of the graph such that if we connect those two edges no of components decreases
//n nodes m edges

/*IDEAS
 if we can get the size of components then er can easily find the answer     sigma(xi*sum-xi)/2
 5 2  n m
 1 2 
 4 5
*/
int n, m;
vector<vector<int>>g;   //we store graph using adjacency list  1->{2,3,4} 2->{4}.... i.e we store an array or vector for each node
vector<int> visited;
vector<int> comp;  // in which component does my node lie in

//DFS
// void dfs(int node,int cur_comp){
//     visited[node] = 1;
//     comp[node] = cur_comp;
//     for(auto v:g[node]){
//         if (!visited[v]) //if not visited it will go inside and recursively mark them visited
//             dfs(v,cur_comp);
//     } 
// }
//If you also checking for bipartite the dfs code is below
bool is_bipartite = 1;
vector<int> col;
void dfs(int node,int cur_comp,int color){
    visited[node]=1;
    col[node]=color;
    comp[node] = cur_comp;
    for(auto v:g[node]){
        if(!visited[v]) // if color is 1 other is 2 and viceversa so we are writing 3-   
            dfs(v,cur_comp,3-color);
        else if(col[v] == col[node]){
            is_bipartite=0;
        }
    }

}


//1. check if graph has cycles
//2.check if graph has even cycle(even number of nodes in cycle)




//DFS AND BFS works in O(N+M)
/*
n=9;m=8; 
1 3
1 4
4 3
2 3
5 6
5 7
6 7
8 9
g={{},{3,4},{3},{1,4,2},{1,3},{6,7},{5,7},{5,6},{9},{8}}
*/
void solve(){
    cin>>n>>m;  //indexing 1
    g.clear();
    g.resize(n + 1); 
     //as we are starting from 1 so we took n+1 and store 0 as empty
    int a, b;
    visited.resize(n + 1, 0);
    col.resize(n + 1);
    g.resize(n + 1);

    fo(i,0,m){//upto number of edges 
        cin >> a >> b;
        g[a].push_back(b);   // i.e b is the neighbour of a a->b and b >a possible as it is undirected
        g[b].push_back(a);  // as it is undirected
    }
    int num_comp=0;    //Number of components  
    fo(i, 1,n+1) 
    { //upto number of nodes 
        if(!visited[i]){     // check  if node is not visited
            num_comp++;  
            dfs(i,num_comp,1); 
            if(!is_bipartite){
                cout <<"not bipartite";
                break;
            }
        }
           
            
        
        
    }
    //is a reachable from b?  if they are in same component then yes else no
    // to find the size of each component
    vector<int> size_comp(num_comp + 1,0);
    fo(i,1,n+1){
        size_comp[comp[i]]++;
    }
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