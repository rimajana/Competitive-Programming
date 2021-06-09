#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int temp[100001];

void merge(int arr[], int l, int mid, int r, int &count)
{
    int st = l;
    int en = mid + 1;
    int in = -1;
    while (st <= mid && en <= r)
    {
        in++;
        if (arr[st] <= arr[en])
        {
            temp[in] = arr[st];            
            st++;
        }
        else
        {            
            temp[in] = arr[en];
            en++;
            count += (1 + mid - l);
        }
    }
    in++;
    while(st<=mid){
        temp[in++] = arr[st++];
    }
    while(en<=r)
        temp[in++] = arr[en++];
    for (int i = l; i <= r;i++)
        arr[i] = temp[i];
}

void mergesort(int arr[], int l, int r, int &count)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;

        mergesort(arr, l, mid, count);
        mergesort(arr, mid + 1, r, count);
        merge(arr, l, mid   , r, count);
    }
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    mergesort(arr, 0, n - 1, count);
    cout << "Count : " << count << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
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