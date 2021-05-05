#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int arr[100];

/*Kadanes algorithm to find max sum of contiguos subarray in given range
Idea is to maintain current maximum and gloabl maximum and first equal them to the first element of the given range;
Then,current_maximum upto a particular node is equal to max of current_max_Sum upto previous node and particular node value

current_max =max(arr[left + 1], arr[left + 1] + current_max)


array           1    2  3  -2  5
current_max     1    3  6   4  9
global_max      1    3  6   6  9

Answer=9   1 2 3 -2 5
*/

//Considering zero indexing
int kadane(int left ,int right)
{
    int current_max = arr[0], global_max = arr[left];
    fo(i,left+1,right+1){
        current_max = max(arr[left + 1], arr[left + 1] + current_max);
        if(current_max >global_max)
            global_max = current_max;
    }
    return global_max;

}

void solve()
{
    int n;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    int l=0,r=n-1;
    //cin >> l >> r;

    cout <<kadane(l,r) << "\n";
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