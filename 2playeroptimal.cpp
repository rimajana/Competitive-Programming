
                            //  ***FORM 4 ***

//here the question is 2 players play a game 
//where there are numnbers in the array but in each move player needs to select either first or last element of the array 
//and both players need to play optimally  we need to return optimal diff
//ex 1    =>  7 5 3 2 9  =

#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

int dp[10010][10010];

vector<int> v;
int n;
int p1, p2;
int done[10010][10010];   //WHETHER WE ALREADY CALCULATED THE VALUE OR NOT BECAUSE THERE CAN BE NEGATIVE VALUES SO WE ARE USING THIS DONE ARRAY


int recur(int l,int r){
    if(l==r)
        return v[l];
    if(done[l][r])
        return dp[l][r];
    int ans = max(v[l] - recur(l + 1, r), v[r] - recur(l, r - 1));
    done[l][r] = 1;
    return dp[l][r] = ans;
}



void solve()
{
    int a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(0, n - 1);
    
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