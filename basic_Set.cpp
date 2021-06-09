#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout << "\n"

void solve()
{
    int q, n;
    cin >> q;
    string s;
    set<int> st;

    while (q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> n;
            st.insert(n);
        }
        else if (s == "find")
        {
            cin >> n;
            if ((st.find(n)) != st.end())
            {
                cout << "YES";
                nl;
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
        else if (s == "erase")
        {
            cin >> n;

            if ((st.find(n)) != st.end())
            {
                st.erase(n);
            }
        }
        else if (s == "print")
        {
            for (int x : st)
            {
                cout << x << " ";
            }
            nl;
        }
        else
        {
            st.clear();
        }
    }
}

void solve_1()
{
    int n, a;
    cin >> n;
    set<int> s;
    fo(i, 0, n)
    {
        cin >> a;
        s.insert(a);
    }
    if (s.size() > 1)
    {
        auto it = s.begin();
        cout << *(++it) << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}
void solve_2()
{
    int q;
    cin >> q;
    set<ll> st, nst;
    while (q--)
    {
        int ty;
        ll x;
        cin >> ty >> x;
        if (ty == 1)
        {
            st.insert(x);
            auto tmp = nst.find(x);
            if (tmp != nst.end())
                nst.erase(tmp);
            if (!st.count(x + 1))
                nst.insert(x + 1);
        }
        else
        {
            if (!st.count(x))
                cout << x;
            else
                cout << *nst.lower_bound(x);
            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        //solve();
        //solve_1();
        solve_2();
    }
}