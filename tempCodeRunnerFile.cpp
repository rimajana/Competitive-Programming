#include <iostream>
#include<bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout<<"\n"




void solve()
{
    int a,n,q;
    cin >>n >> q;
    vector<int>v;
    fo(i,0,n){
        cin >> a;
        v.push_back(a);
    }
    int x, y;
    fo(i,0,q){
        cin >> x >> y;
        if(x == 1){
            auto it=lower_bound(v.begin(),v.end(),y);
            if(it!= v.end() ){
                cout << *it <<" ";
               
            }
            else{
                cout << -1 <<" ";
                
            }
        }
        else if(x == 2){
            auto it=upper_bound(v.begin(),v.end(),y);
            if(it!= v.end() ){
                cout << *it <<" ";
                
            }
            else{
                cout << -1<<" " ;
                
            }
        }
        else if(x == 3){
            auto it=upper_bound(v.begin(),v.end(),y);
            
            cout << it-v.begin() <<" ";
            
        }
        else{
            auto it=lower_bound(v.begin(),v.end(),y);
            cout << it-v.begin() <<" ";
           
        }

        
    }
    nl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t ;
    cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}