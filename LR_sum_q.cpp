#include <iostream>
#include <bits/stdc++.h>

#define fo(i, a, p) for (ll i = (a); i < p; i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout << '\n'

void solve()
{
    ll MOD = 1e9 + 7;

    ll n, q;
    cin >> n >> q;
    ll arr[n];
    ll psa[n];
    psa[0] = arr[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (i == 1)
            psa[i] = arr[i];
        else
            psa[i] = psa[i - 1] + arr[i];

        if (psa[i] < 0)
            psa[i] += MOD;

        if (psa[i] >= MOD)
            psa[i] -= MOD;
    }
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        ll s = psa[r] - psa[l - 1];
        if (s < 0)
            s += MOD;
        if (s >= MOD)
            s -= MOD;

        cout << s << "\n";
    }
}

signed main()
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