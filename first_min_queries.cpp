#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int arr[200200];
int t[800800];
int n;

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = max(t[2 * index], t[2 * index + 1]);    
    
}

void update(int index,int l,int r,int pos ,int val){
    if(pos<l || pos>r)
        return;
    if (l==r){
        arr[l]-=val;
        t[index] -= val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid,pos,val);
    update(2 * index + 1, mid + 1, r,pos,val);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}

int query(int index, int l, int r,int val)
{       
    if(t[index]<val){
        return INT_MAX;
    }
    if(l==r){
        if (t[index] < val){
            return INT_MAX;
        }
        update(1, 1,n, l, val);
        
        return l;
    }
    int mid = (l + r) / 2;
    if (t[2 * index] >= val)
        return query(2 * index, l, mid, val);
    return query(2 * index + 1, mid + 1, r, val);
}

void solve()
{
    int q,value;
    int x;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    fo(i,0,q){
        cin >> value;
        if(t[1] <value){
            cout << 0 << "\n";
            
        }
        else{
            int p = query(1, 1, n, value);
            cout<< p << "\n";
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