#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'


/*psa implementation

sum from l to r = psa[r]+psa[l-1]   if l is not 0

*/
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int psa[n];
    psa[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        psa[i] = psa[i - 1] + arr[i];
    }
    int query;
    cin >> query;
    int l, r;
    while(query--){
        cin >> l >> r;
        if(l!=0)
            cout << psa[r] - psa[l - 1];
        else
        {
            cout << psa[r];
        }
        
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