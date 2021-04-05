#include <iostream>
#include<bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"

int n;
vector<int> queens;
int ans=0;
//prow and pcol are previous queens positions

bool check(int row,int col){
    for(int prow = 0; prow < row;prow++){      //Looping on previous queens positions to check whether we can insert new queen or not
        int pcol=queens[prow];
        if((col == pcol) or abs(row-prow) == abs(col-pcol)){  //check whether queens attack each other or not
            return 0;
        }
    }
    return 1;
}

void brute(int row){ //return , answer and backtracking concept
    if(row== n){
        ans++;
        return;
    }
    for (int col = 0;col<n;col++){
        if(check(row,col)){
            queens.push_back(col);
            brute(row+1);
            queens.pop_back();
        }
    }
}

void solve()
{
    cin>>n;
    brute(0);
    cout << ans << endl;
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