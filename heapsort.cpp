#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
const int mod = 100000;
int arr[mod];
int n;
void swapy(int &a,int &b){
    int temp=a;
    a = b;
    b = temp;
}

void heapify(int size,int index){
    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    if(l<size and arr[l]>arr[largest]){
        largest = l;
        
    }
    if (r < size and arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest!=index){
        swapy(arr[largest], arr[index]);
        heapify(size,largest);
    }

}

void maxheap(int l, int r){
    //building maximum heap
    for(int i=(n/2 -1);i>=0;i--){   //since there are n elements the index f ny element in tree is n/2 -1
        heapify(n, i);
    }
    //swapping and removing the last element
    for (int i = n-1; i >=0;i--){
        swapy(arr[0], arr[i]);
        heapify(i, 0); //updating heap as max heap
    }
}
        

void solve()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    maxheap(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] <<" ";
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