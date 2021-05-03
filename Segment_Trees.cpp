#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int arr[10100];
//tree should be 4 times the size of array
int t[40400];

//here index is nothing but node number and it starts from 1

//root node is at  1
void build(int index, int l, int r)
{
    if (l == r)
    {
        //leaf node
        //Here the value of that node will be taken directly from the array
        t[index] = arr[l];
        return;
    }

    //IF the index node is i then the left node is 2*i and the right node would be 2*i+1 i.e index 1 left node 2 right node 3

    int mid = (l + r) / 2;

    //Building Left tree
    build(index * 2, l, mid);

    //Building right tree
    build(index * 2 + 1, mid + 1, r);

    //merge logic of segment tree
    t[index] = t[2 * index] + t[2 * index + 1];
}

void update(int index, int l, int r, int pos, int val) //Here we are updating the position with value
{

    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        //Leaf node
        arr[l] = val;
        t[index] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(index * 2, l, mid, pos, val);
    update(index * 2 + 1, mid + 1, r, pos, val);

    t[index] = t[2 * index] + t[2 * index + 1]; //merge logic of segment tree
}

int sum(int index, int l, int r, int lq, int rq) //Here we are findind the sum from range (lq to rq including lq and rq)
{

    if (l > rq || lq > r) //check if two ranges intersect or not if they dont intersect then return 0
    {
        return 0;
    }

    if (lq <= l and r <= rq) //If l and r exist in between lq and rq then we are directly returning the node
    {

        return t[index];
    }
    int mid = (l + r) / 2;
    return sum(index * 2, l, mid, lq, rq) + sum(index * 2 + 1, mid + 1, r, lq, rq); //contribution of left child and right child(recurse on left size and right side)
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1); //node 1 is root node and it is responsible from l to r

    int q; //  Taking the number of queries
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1) //updating any position(x) with value(v)
        {

            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        { //Here we are findind the sum from range (l to r including l and r)

            int l, r;
            cin >> l >> r;
            cout << sum(1, 0, n - 1, l, r) << "\n";
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