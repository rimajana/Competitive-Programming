#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//max element in each window

#define nl cout << "\n"

void solve()
{
    int q;
    int n, k, a;
    cin >> q;
    fo(i, 0, q)
    {

        cin >> n >> k;
        deque<int> dq;

        int v[n];
        //Storing all the elements in the vector
        fo(i, 0, n)
        {
            cin >> v[i];
        }
        // IN deque we are just entering the indices of the vector elements so that it would be easy for us to delete the indices which are not in the window

        /* in this loop we are adding elements upto the given window length if the new element is greater than or equal
         to thelast element (v[dq.back()]) then we are deleting the element amd then adding the new element or 
         else we are simply adding the new element*/

        fo(i, 0, k - 1)
        {
            while ((!dq.empty()) and (v[i] >= v[dq.back()]))
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        /*here we are taking care of two things adding the element according to the rule and removing the index which doesnot include in the window*/

        fo(i, k-1,n)
        {
            while ((!dq.empty()) and dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while((!dq.empty()) and (v[i] >= v[dq.back()]))
            {
                dq.pop_back();
            }
            dq.push_back(i);

            cout << v[dq.front()] << " ";
        }

        nl;
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