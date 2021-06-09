#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

int arr[101000];
int t[404000];

void build(int index,int l,int r){
    if(l==r){
        t[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = min(t[2 * index], t[2 * index + 1]);
}


void print_left(int n){
    int k;
    cout << t[1] << "\n";
    if(n%2 == 1)
        k = n / 2 + 1;
    else k = n / 2;
    for (int i = 2; i <= k;i++){
        cout << t[2*i] << t[2*i + 1];

    }
}
ll query(int index,int l,int r,int lq,int rq){  
    if (l > rq || lq > r) //check if two ranges intersect or not if they dont intersect then return 0
    {
        return INT_MAX;
    }
   // lq<=l<=r<=rq
    if (lq <= l and r <= rq)
    {
        return t[index];
    }
    int mid = (l + r )/ 2;
    return min(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
}

void update(int index,int l,int r,int pos,int val){
    if(pos<l or pos >r){
        return;
    }
    if(l==r){
        t[index]=val;
        arr[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = min(t[2*index],t[2*index+1]);
}
void solve()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    fo(i, 0, q)
    {
        cin >> a >> b;
        cout << query(1, 0, n - 1, a, b) << "\n";
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