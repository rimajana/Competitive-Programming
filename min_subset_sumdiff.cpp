// Sum of subset differences
// Given a set of integers, the task is to divide it into two sets S1 and S2 
//such that the absolute difference between their sums is minimum.
// If there is a set S with n elements, then if we assume Subset1 has m elements,
// Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

// Example:
// Input:  arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11

#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
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

bool recur(int index, int w)
{
    if (w == 0)
    {
        return 1;
    }
    if (index >= n)
    {
        return 0;
    }
    if (dp[index][w] != -1)
    {
        return dp[index][w];
    }

    if (arr[index] > w)
    {
        return dp[index][w] = recur(index + 1, w);
    }
    else
    {
        dp[index][w] = recur(index + 1, w - arr[index]) || recur(index + 1, w); //it returns as sson as one subset is found
        return dp[index][w];
    }
}

void solve()
{
    int W;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    memset(dp, -1, sizeof(dp));
    vector<int> v;
    for (int i = 0;i<=sum/2;i++){
        if(recur(0,i)){
            v.push_back(i);
        }
    }
    int mini = INT_MAX;
    for (int j = 0; j < v.size();j++){
        mini = min(mini, sum - 2 * v[j]);
    }
    cout << mini << "\n";
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