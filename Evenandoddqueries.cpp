#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

//Query 1 updating a value in the array
//Query 2 Finding the count of even numbers in l to r inclusive
//Query 3 Finding the count of Odd numbers in l to r inclusive

int arr[200200];
struct node
{
    
    int even;
    int odd;
    node(int b = 0, int c = 0)
    {
        
        even = b;
        odd = c;
    }
};

node t[800800];
node merge(node a,node b){
    return node(a.even + b.even, a.odd + b.odd);
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        
        if(arr[l]%2 == 0){
            t[index] = node(1, 0);
           
        }
        else{
            t[index] = node(0, 1);
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index]= merge(t[2 * index], t[2 * index + 1]);
}
void update(int index,int l,int r,int pos,int value){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        arr[l] = value;
        if (arr[l] % 2 == 0)
        {
            t[index] = node(1, 0);
        }
        else
        {
            t[index] = node(0, 1);
        }
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid,pos,value);
    update(2 * index + 1, mid + 1, r,pos,value);

    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

node even_odd(int index,int l,int r,int lq,int rq){
    if (l > rq or lq > r)
    {
        return node();
    }
    if (lq <= l and r <= rq)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(even_odd(2 * index, l, mid,lq,rq), even_odd(2 * index + 1, mid + 1, r, lq, rq));
}

void solve()
{
    int n;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    build(1,0,n-1);
    int q;
    cin >> q;
    int x, j, k;
    while (q--)
    {
        cin >> x >> j >> k;
        if (x == 0)
        {
            update(1, 0, n - 1, j-1, k);
        }

        else if (x == 1)
        {
            cout << even_odd(1, 0, n - 1, j-1, k-1).even << "\n";
            
        }
        else
        {
            cout << even_odd(1, 0, n - 1, j-1, k-1).odd << "\n";
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