#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

// // if our string is of length n then no of permutation is n!
// FIRST WE SWAP THE FIRST LETTER OF THE STRING AND THEN CONTINUE TILL THE END OF THE STRING
// THEN WE RECURSE 
// BACKTRACTING TO RETURN TO THE STRING BEFORE RECURSING

string s;  //global
int n;
unordered_set<string>se;   
// WE ARE USING UNORDERED SET BECAUSE IF STRING CONTAINS SAME CHARACTERS 
//THEN IT WOULD PRINT SAME PERMUTATIONS TO AVOID THAT WE ARE USING THIS


void permutation(int l,int r){
    //base condition
    if(l==r){
        // cout << s << "\n";
        se.insert(s); 
    }

    else{
        for (int i = l; i <= r;i++){
            swap(s[i], s[l]);    // SWAPPING 
            
            permutation(l + 1, r);    //RECURSING THROUGH ALL ITS POSSIBILITIES
            
            swap(s[i], s[l]);     //BACKTRACKING TO GET THE STRING THAT WAS PRESENT BEFORE RECURSION.
            
        }
    }
    
}

void solve()
{
    
    cin>>s;
    n=s.size();
    int l;
    int r ;
    permutation(0, n-1);
    for(auto x:se){
        cout << x << "\n";
    }
    // cout << se.size() << " <= size"<< "\n";      //If you want to see NUMBER OF PERMUTATIONS 
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

