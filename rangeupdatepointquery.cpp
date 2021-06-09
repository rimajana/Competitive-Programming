#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

int arr[10100];
int t[40400];



//The idea is to keep all the nodes of tree as zero and only increment the leaf nodes by given value and while printing the value add by arr[index ]


void update(int index, int l, int r, int lq, int rq,int val) {
    if(l>rq or lq>r){
        return;
    }
    if(lq<=l and r<=rq){
        
        t[index] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2*index,l,mid,lq,rq,val);
    update(2 * index + 1, mid + 1, r, lq, rq,val);
    
}

int show(int index, int l, int r, int x){
    if(x<l or x>r){
        return 0;
    }
    if(l==r){
        return t[index];
    }
    int mid = (l + r) / 2;
    return (t[index]+show(index*2, l, mid, x)+show(index*2+1, mid + 1, r, x));

}

void solve()
{
    int n,q;
    cin>>n>>q;
    fo(i,0,n){
        cin >> arr[i];
    }
    int a, l, r, v, x;
    fo(i,0,q){
        cin >> a;
        if(a==1){
            cin>>l>>r>>v;
            update(1,0,n-1,l-1,r-1, v);
        }
        else{
            cin >> x;
            cout << show(1, 0, n - 1, x - 1) + arr[x - 1] << "\n";
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