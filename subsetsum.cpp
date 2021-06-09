#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int n;

//// {2 3 5 6 8 10}    w=10   o/p=1   here we need to find whether there is any subset that sums to the given weight
int arr[10010];
int dp[10010][10010];
int countt = 0;
// we need a same array called back which keeps track of the elements we took
int back[10010][10010];

bool recur(int index,int w){
    if (w == 0){
        return 1;
    }
    if(index >=n){
        return 0;
    }

    if (dp[index][w] !=-1){
        return dp[index][w];
    }

    if(arr[index] >w){
        return  dp[index][w]=recur(index + 1, w);
    }
    else
    {
        int ans = recur(index + 1, w);
        back[index][w] = 0;
        if (recur(index + 1, w - arr[index]) >ans){
            back[index][w] = 1;
            ans = recur(index + 1, w - arr[index]); //it returns as sson as one subset is found
        }
        return dp[index][w]=ans;
    }
    
}

void getsol(){
    int i=0;
    int j = 0;
    vector<int> id;
    while(back[i][j]!=1){
        if(back[i][j]==0){
            i++;
        }
        else{
            id.push_back(i);
        }
    }
}


void solve()
{
     int W;
     cin>>n >>W;
     for (int i = 0;i<n;i++){
         cin >> arr[i];
     }
     memset(dp, -1, sizeof(dp));
     memset(back, -1, sizeof(back));

     if (recur(0,W))
         cout << "YES"<< "\n";
     else
     {
         cout << "NO"<< "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}