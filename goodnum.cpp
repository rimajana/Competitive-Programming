#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (ll i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout<<'\n'

void solve()
{
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll>v(n+1,0);
    ll par[n+1];
    ll l,r;
    for(ll i=0;i<n;i++){
        cin>>l>>r;
        v[l]+=1;
        if(r!=n)
            v[r+1]-=1;
    }
    par[0]=v[0]=0;
    par[1]=v[1];
    for(ll i=2;i<=n;i++){
        par[i]=par[i-1]+v[i];
    }
    for(ll i=1;i<=n;i++){
        if(par[i]>=k)
            par[i]=1;
        else
            par[i]=0;
    }
    
    ll liked[n+1];
    par[0]=liked[0]=0;
    liked[1] =par[1];
    // cout << par[1] << "fghjk";
    for(ll i=2;i<=n;i++){
        liked[i]=liked[i-1]+par[i];
        // cout << i << " " << liked[i]<<"\n";
    }
        
    int L,R;
    // cout << "WEfg " << liked[0] << " l " << liked[5] <<"\n";
    while (q--)
    {
        cin>>L>>R;
        cout<<liked[R]-liked[L-1]<<"\n";
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