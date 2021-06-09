#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

int arr[200200];

struct node
{
    ll psum, ssum, max, tsum;
    node(ll pre = INT_MIN, ll suf = INT_MIN, ll tot = INT_MIN, ll maxs = INT_MIN)
    {
        psum = pre;
        ssum = suf;
        max = maxs;
        tsum = tot;
    }
};

node t[800800];

node merge(node a, node b)
{
    node c;
    c.psum = max(a.psum, a.tsum + b.psum);
    c.ssum = max(b.ssum, b.tsum + a.ssum);
    c.tsum = a.tsum + b.tsum;
    c.max = max(a.max, max(b.max, a.ssum + b.psum));
    return c;
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = node(arr[l], arr[l], arr[l], arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        arr[l] = val;
        t[index] = node(val, val, val, val);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void solve()
{
    int n, m, k, x;
    cin >> n >> m;
    //Array indexing is from 1
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while (m--)
    {
        cin >> k >> x;
        update(1, 0, n - 1, k - 1, x);
        if (t[1].max < 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << t[1].max << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}