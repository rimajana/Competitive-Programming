#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,m;
int dp[3010][3010];


int recur(int l,int r){
    // cout << "fs" << s1[l] << "\n";
    if (l == n or r == m)
    {
        return 0;
    }
  if(dp[l][r]!=-1)
    return dp[l][r];

   int ans= dp[l][r]= max(recur(l,r+1),recur(l+1,r));
   if(s1[l]==s2[r]){

    return dp[l][r] = max(1 + recur(l + 1, r + 1), ans);

   }
   return dp[l][r] = ans;

}


void solve(){
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp, -1, sizeof(dp));
  int lcs=recur(0,0);
  
  if(lcs == 0){
    cout<<""<<"\n";
    return;
  }
  string s = "";
  int i = 0,j = 0;
 
  while(i<n and j<m){
    if(dp[i][j] >= max(max(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1])){
      if (dp[i + 1][j + 1] == dp[i + 1][j] and dp[i + 1][j + 1] == dp[i][j + 1] and dp[i+1][j+1]==dp[i][j])
      {
        i++;
      }
      else if (dp[i + 1][j + 1] >= dp[i + 1][j] and dp[i + 1][j + 1] >= dp[i][j + 1])
      {
        s += s1[i];
        i++;
        j++;
      }
      else if (dp[i + 1][j] >= dp[i][j + 1] and dp[i + 1][j] >= dp[i + 1][j + 1])
      {
        i++;
      }
      else if (dp[i][j + 1] >= dp[i + 1][j] and dp[i][j + 1] >= dp[i + 1][j + 1])
      {
        j++;
      }
    }
    
  }
  cout << s << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}