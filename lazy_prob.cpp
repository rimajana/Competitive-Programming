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
    ll sum;
    ll lazy;
    int queryno;
    node(ll s = 0, ll l = 0, int qno = 0)
    {
        sum = s;
        lazy = l;
        queryno = qno;
    }
};

node merge(node a, node b)
{
    node c;
    c.sum = a.sum + b.sum;

    return c;
}
node t[800800];

void build(int index, ll l, ll r)
{
    if (l == r)
    {
        t[index].sum = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(index << 1, l, mid);
    build(index << 1 | 1, mid + 1, r);
    t[index] = merge(t[index << 1], t[index << 1 | 1]);
}

void push(int id, ll l, ll r)
{
    if (t[id].queryno == 1)
    {
        t[id].sum += t[id].lazy * (r - l + 1);
    }
    if (t[id].queryno == 2)
    {
        t[id].sum = t[id].lazy * (r - l + 1);
    }

    if (l != r)
    {
        if (t[id].queryno == 1)
        {
            t[id << 1].lazy += t[id].lazy; //t[2*id] .lazy
            if (t[2 * id].queryno != 2)
                t[id << 1].queryno = t[id].queryno;

            t[id << 1 | 1].lazy += t[id].lazy; //t[2*id+1] .lazy
            if (t[id << 1 | 1].queryno != 2)
                t[id << 1 | 1].queryno = t[id].queryno;
        }
        else
        {
            t[id << 1].lazy = t[id].lazy; //t[2*id] .lazy
            t[id << 1].queryno = t[id].queryno;

            t[id << 1 | 1].lazy = t[id].lazy; //t[2*id+1] .lazy
            t[id << 1 | 1].queryno = t[id].queryno;
        }
    }
    t[id].lazy = 0;
    t[id].queryno = 0;
}

void update(int index, ll l, ll r, ll lq, ll rq, int type, int val)
{

    if (lq > r || rq < l)
        return;

    if (t[index].lazy != 0)
    {
        push(index, l, r);
    }
    if (lq <= l && r <= rq)
    {
        t[index].lazy = val;
        t[index].queryno = type;
        push(index, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    update(index << 1, l, mid, lq, rq, type, val);
    update(index << 1 | 1, mid + 1, r, lq, rq, type, val);
    t[index] = merge(t[index << 1], t[index << 1 | 1]);
}

// void viewtree(int index,int l,int r){
//     for (int i = 1; i < 14;i++){
//         if(i !=10 and i!=11){
//             cout <<" index "<< i << "sum " << t[i].sum << " lazy " << t[i].lazy << " qno " << t[index].queryno << "\n";
//         }
//     }
// }

node show(int index, ll l, ll r, ll lq, ll rq)
{
    if (lq > r || rq < l)
        return node();

    if (t[index].lazy != 0)
    {
        push(index, l, r);
    }

    if (lq <= l && r <= rq)
    {
        return t[index];
    }
    ll mid = (l + r) / 2;
    return merge(show(index << 1, l, mid, lq, rq), show(index << 1 | 1, mid + 1, r, lq, rq));
}

void solve()
{
    int n, q, x, qq;
    ll a, b;
    cin >> n >> q;
    fo(i,0,n)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    //viewtree(1, 0, n - 1);
    fo(i, 0, q)
    {
        cin >> qq;
        if (qq == 3)
        {
            cin >> a >> b;
            cout << show(1, 0, n - 1, a - 1, b - 1).sum << "\n";
        }
        else
        {
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, qq, x);
        }

        //viewtree(1, 0, n - 1);
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