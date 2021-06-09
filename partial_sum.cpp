#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'



// each query(Q) contains l r and value we need to add value to every number at the range l to r 
//so worst case complexity o(Q*n)   looping over the range and incrementing the value for each query

// IF WE WANT TO ADD V IN L TO R THEN ADD V TO ARR[L] AND SUBTRACT ARR[R+1] AND FINALLY PREFIX array of the array gives us the ans



void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0;i<n;i++)
        cin >> arr[i];
    int q, l,r,v;
    cin >> q;

    while(q--){
        cin >> l >> r >> v;
        arr[l] += v;
        if(r!=n-1)
            arr[r + 1] += v;
    }

    //finally we want the modified array
    int psa[n];
    psa[0] = arr[0];
    for (int i = 0; i < n;i++){
        psa[i] = psa[i - 1] + arr[i];
        cout << psa[i] << " ";
    }
    cout << "\n";
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