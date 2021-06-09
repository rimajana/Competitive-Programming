#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'



void solve()
{

    int tree[] = {0,1, 2, 3, 4, 5, 6, 7};
    int start=1;
    int end;
    cout << tree[1] << " ";
    fo(i,2,4){
        if(i%2 ==0){
            start = pow(2,i)-1;
            end = pow(2,i-1) ;
            while(start!=end){
                cout << tree[start] <<" ";
                start--;
            }
            cout << tree[start] << " ";
        }

        else{
            end = pow(2, i) - 1;
            start = pow(2, i - 1);
            while (start != end)
            {
                cout << tree[start] <<" ";
                start++;
            }
            cout << tree[start];
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