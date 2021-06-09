#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int n=8;
int arr[] = {2, 1, 2, 2, 2, 3, 4, 2};

void swap(int &a, int &b)
{
    int c=a;
    a=b;
    b = c;
}

void solve()
{

    // time complexity O(n)  because we are visiting all elements only once and swap is constant time and space complexity is constant space
    
    n= sizeof(arr)/sizeof(int);
    
    int start=0;
    int end=n-1;
    int k;
    cin>>k;
    while(start<end){
        while(arr[start]!=k)
            start++;
        while(arr[end]==k)
            end--;
        if(start<end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
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