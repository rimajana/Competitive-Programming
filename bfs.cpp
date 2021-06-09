#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pii = pair<int, int>;
#define endl '\n'

int n, m;
vector<string> arr;
vector < vector<int> >dist;   //2D grid of values which stores distance


int dx[]={1,0,-1,0};
int dy[] = {0, 1, 0, -1};

bool check(int x,int y){
    if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y]!='#')
        return 1;
    else
    {
        return 0;
    }
}

vector<vector<pii>>parent; 

/*bfs is iterative and we use queue to store the parent node and while removing the parent node fron the queue
we add its neighbours to the queue*/

void bfs(pii st){
    dist = vector<vector<int>>(n, vector<int>(m, 1e9));           
    parent = vector<vector<pii>>(n, vector<pii>(m, {-1,-1}));
    dist[st.first][st.second] = 0;
    queue<pii>q;
    q.push(st);     //pushing the start pair to the queue
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k< 4; k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(check(nx,ny) and dist[nx][ny]>dist[x][y]+1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));

            }
        }
    }

}


void solve()
{
    cin>>n>>m;
    arr.resize(n);
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    pii st, en;          //PAIR OF START AND END COORDINATES
    //Taking our start and end coordinates
    cin >> st.first >> st.second;   //(3 2)
    cin >> en.first >> en.second;   //5 7

    bfs(st);  //single source to shortest path

    cout << dist[en.first][en.second] << endl;
    pii cur=en;
    vector<pii> path;
    while(cur!=make_pair(-1,-1)){
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());  //because we are starting current fron end
    for(auto i:path){
        cout << i.first << " " << i.second<<"\n";
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