#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define MAXN 800800
int arr[200200];

//LAZY PROPAGATION
/* key property to apply lazy to a problem
    1. correction(of the particular node using lazy) o(1) or O(logn)
    2. Lazy should be possible  
*/

//Assuming all postive values in the array

struct node{
    int max;
    int sum;
    int lazy;
    node(int m = 0,int s=0,int l=0){
        max = m;
        sum = s;
        lazy = l;
    }
};
node t[MAXN];

node merge(node a,node b){
    node c;
    c.max = max(a.max, b.max);
    c.sum = a.sum + b.sum;
    return c;
}
void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = node(arr[l], arr[l], 0);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[index << 1], t[2 * index << 1 | 1]);
}

void modify(int id,int l,int r){
    if(t[id].lazy !=0){                        //checking if there is some lazy value that needs to be updated or not
        t[id].sum = t[id].lazy * (r - l + 1);    //value*no of nodes in l to r(r-l+1)
        t[id].max = t[id].lazy;                 //because every leaf node is v so max will be v only
        // passing the lazy to the children(only if they are not leaf nodes)
        if(l!=r){
            t[id << 1].lazy = t[id].lazy;       //t[2*id] .lazy
            t[id << 1 | 1].lazy = t[id].lazy;   //t[2*id+1] .lazy
        }
        t[id].lazy = 0;                    //since we have passed lazy to its children we mark the lazy as 0
    }
}

void update(int index,int l,int r,int lq,int rq,int val){       //updating all the leaf nodes from lq to rq to v
    if (t[index].lazy != 0)         //here we are checking whether there is any lazy value or not
        modify(index,l,r);        
    if(lq>r || l>rq)
        return;
    if(lq<=l and rq>=r){
        t[index].lazy = val;  //Updating to the value v so that we can use it again so we also need to change the max and sum because we also need to modify its parent nodes
        modify(index,l,r);    //calling the modify function to update the sum and max values of the particular index and its parent nodes will be updated in the recursion
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid,lq,rq,val);
    update(2 * index + 1, mid + 1, r,lq,rq,val);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}




node query(int index,int l,int r,int lq,int rq){  // finding the sum and max in the given range
    modify(index, l, r);
    if (lq > r || l > rq)
        return node();
    if (lq <= l and rq >= r)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(query(index << 1, l, mid, lq, rq), query(index<< 1|1, mid + 1, r, lq, rq));

} 


void solve()
{
    int l,q,r,n,v;
    cin>>n;
    fo(i,0,n){
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    cin >> q;
    fo(i,0,q){
        if(q==1){
            cin >> l >> r >>v;
            update(1, 0, n - 1, l, q, v);
        }
        else
        {
            cin >> l >> r;
            node x = query(1, 0, n - 1, l, q);
            cout << x.sum << " " << x.max << "\n";
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