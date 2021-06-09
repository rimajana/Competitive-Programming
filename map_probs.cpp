#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solve()
{
    map<string, int> m;
    int q;
    cin >> q;
    string s, a;
    int n;
    while (q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> a >> n;
            m[a] = n;
        }
        else if (s == "print")
        {
            cin >> a;
            if(m.find(a)!= m.end())
                cout << m.at(a) << "\n";
            else
                cout << 0 << "\n";
        }
        else
        {
            cin >> a;
            if (m.find(a) != m.end())
                m.erase(a);
        }
    }
}
void solve_1()
{
    int q;
    cin >> q;
    map<string, int> m;
    string s;
    while (q--)
    {
        cin >> s;
        if (m.find(s) != m.end())
        {
            cout << s << m[s] << "\n";
            m[s]++;
        }
        else
        {
            
            cout << "OK"<< "\n";
            m[s]++;
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
        solve_1();
    }
}