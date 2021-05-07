#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'


//Given an array of unsorted array find the minimum length  of window (0 indexing ) that we need to sort to make the entire array sorted

/*Dividing the array into 3 parts 
1.Traverse from the start of the array and check where the arr[i]>arr[i+1] and take that index as start index
similarly traverse fron the end of the array and check where the arr[i]<arr[i-1] and take the index as end index

2. traverse from the start index to end index and note the min and max values

3. Traverse from the start to start index and check where arr[i]>min value of window if you found it then change the start index to i
similarly traverse from the end of the array to the end index and check where the arr[i]<max value and if found then change the end index to i

*/



int arr[10100];
int n;

void query(){
   
    int start_index=0, end_index=0;

    for (int i = 0; i < n-1;i++){
        if(arr[i]>arr[i+1]){
            start_index = i;
            break;
        }
    }
    for (int i = n - 1; i > 0;i--){
        if(arr[i]<arr[i-1]){
            end_index=i;
            break;
        }
    }

    int min = arr[start_index], max = arr[start_index];

    for (int j = start_index ; j <= end_index; j++)
    {
        if (arr[j] < min){

            min = arr[j];
        }
        else if(arr[j]>max)
        {
            max = arr[j];
        }
    }
    for (int i = 0; i < start_index; i++)
    {
        if(arr[i] > min){
            start_index=i;
            break;
        }
    }

    for (int i = n - 1; i > end_index; i--)
    {
        if (arr[i] < max)
        {
            end_index = i;
            break;
        }
    }
    cout << start_index <<" "<< end_index << "\n";
}

void solve()
{
    
    cin>>n;
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    query();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    //string s
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}